#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

void *oldhandler;
void sighandler(int sig)
{
  // if (sig == SIGUSR1)
  //   flag = 0;
}

int main(int argc, char *argv[])
{
  FILE *file;
  int i, n;
  pid_t root = getpid();
  char contenido[1000] = "";
  char linea[1000] = "";

  pid_t pidhijo[2];
  // Configuracion de la señal
  oldhandler = signal(SIGUSR1, sighandler);
  if (oldhandler == SIG_ERR)
  {
    perror("signal:");
    exit(EXIT_FAILURE);
  }

  // Creacion de las tuberias
  int tubs[2][2];
  for (i = 0; i < 2; i++)
    pipe(tubs[i]);

  // Creacion de los hijos
  for (i = 0; i < 2; i++)
  {
    pidhijo[i] = fork();
    if (pidhijo[i] == 0)
    {
      printf("Soy hijo y mi id es: %d\n", getpid());
      break;
    }
    else
    {
      printf("Soy padre y mi id es: %d\n", getpid());
    }
  }

  if (getpid() == root)
  {
    close(tubs[0][1]);
    close(tubs[1][1]);

    usleep(200);
    printf("Padre esperando a que los hijos escriban...\n");

    kill(pidhijo[0], SIGUSR1);
    do
    {
      pause();
      n = read(tubs[0][0], linea, 1000);
      linea[n + 1] = '\0';
      printf("[%d]write-->:%s\n", getpid(), linea);

      kill(pidhijo[1], SIGUSR1);
      pause();
      n = read(tubs[1][0], linea, 1000);
      linea[n + 1] = '\0';
      printf("[%d]write-->:%s\n", getpid(), linea);

      if (((n = read(tubs[0][0], linea, 1000)) <= 0) || ((n = read(tubs[1][0], linea, 1000)) <= 0))
      {
        printf("Entro");
        break;
      }
      printf("Hey");
    } while (1);

    printf("Texto recibido por el padre: \n%s", contenido);

    // for (int j = 0; j < 2; j++)
    // {
    //   wait(NULL);
    // }
  }
  else
  {
    if (i == 0)
    {
      close(tubs[0][0]);
      close(tubs[1][0]);
      close(tubs[1][1]);

      file = fopen(argv[1], "r");

      if (file == NULL)
      {
        perror("Error al abrir el archivo");
        exit(1);
      }

      while (fgets(linea, 1000, file))
      {
        pause();
        linea[strlen(linea)] = '\0';
        write(tubs[0][1], linea, strlen(linea));
        kill(getppid(), SIGUSR1);
      }

      fclose(file);
      close(tubs[0][1]);
    }
    else if (i == 1)
    {
      close(tubs[0][0]);
      close(tubs[0][1]);
      close(tubs[1][0]);

      file = fopen(argv[2], "r");

      if (file == NULL)
      {
        perror("Error al abrir el archivo");
        exit(1);
      }

      while (fgets(linea, 1000, file))
      {
        pause();
        linea[strlen(linea)] = '\0';
        write(tubs[1][1], linea, strlen(linea));
        kill(getppid(), SIGUSR1);
      }

      fclose(file);
      close(tubs[1][1]);
    }
  }

  signal(SIGUSR1, oldhandler);
  return EXIT_SUCCESS;
}