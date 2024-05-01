#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
/*
este programa crea tres procesos: 
el proceso padre, que lee un conjunto de números desde un archivo, 
y dos procesos hijos, cada uno de los cuales realiza un cálculo sobre esos números (promedio y moda) 
utilizando tuberías para la comunicación de datos entre ellos.
*/
int main()
{
	int tb1[2], tb2[2], tb3[2], tb4[2];
	pipe(tb1);
	pipe(tb2);
	pipe(tb3);
	pipe(tb4);

	if (fork() == 0)
	{
		close(tb1[1]);
		close(tb2[0]);
		close(tb3[0]);
		close(tb3[1]);
		close(tb4[0]);
		close(tb4[1]);
		printf("soy el hijo h1 con pid [%d] y padre con pid[%d]\n", getpid(), getppid());
		int tam;
		read(tb1[0], &tam, sizeof(tam));

		int vec[tam], promedio, suma = 0, i;
		read(tb1[0], &vec, sizeof(vec));
		for (i = 0; i < tam; i++)
		{
			suma = suma + vec[i];
		}
		promedio = suma / tam;

		write(tb2[1], &promedio, sizeof(int));
	}
	else if (fork() == 0)
	{
		close(tb1[0]);
		close(tb1[1]);
		close(tb2[0]);
		close(tb2[1]);
		close(tb3[1]);
		close(tb4[0]);
		printf("soy el hijo h2 con pid [%d] y padre con pid[%d]\n", getpid(), getppid());
		int tam;
		read(tb3[0], &tam, sizeof(int));
		int vecm[tam], resultadores, cont = 0, moda = 0, j, k;
		read(tb3[0], &vecm, sizeof(vecm));

		for (j = 0; j < tam; j++)
		{
			for (k = 0; k < tam; k++)
			{
				if (vecm[j] == vecm[k])
				{
					cont = cont + 1;
				}
			}
			if (cont >= moda)
			{
				moda = vecm[j];
			}
			cont = 0;
		}

		write(tb4[1], &moda, sizeof(int));
	}
	else
	{
		close(tb1[0]);
		close(tb2[1]);
		close(tb3[0]);
		close(tb4[1]);
		printf("soy el padre con pid[%d]\n", getppid());
		FILE *archivo;
		int n, i = 0, index = 0, resp1, resp2, j;
		int vector[100];

		archivo = fopen("prueba.txt", "r");

		if (archivo == NULL)
		{

			printf("\nError de apertura del archivo. \n\n");
		}
		else
		{
			while (feof(archivo) == 0)
			{
				fscanf(archivo, "%d;", &n);
				vector[index] = n;
				index++;
			}
			index = index - 1;
			int v[index];
            printf("\nEl contenido del archivo de prueba es: \n");

			printf("Cantidad Num [%d] \n", index);

			for (i = 0; i < index; i++)
			{
				v[i] = vector[i];
				printf("Valor: [%d] pos: %d \n", v[i], i+1);
			}

			write(tb1[1], &index, sizeof(index));
			write(tb1[1], &v, sizeof(v));
			write(tb3[1], &index, sizeof(int));
			write(tb3[1], &v, sizeof(v));
			read(tb2[0], &resp1, sizeof(int));
			read(tb4[0], &resp2, sizeof(int));
			printf("el promedio es %d  y la moda  es %d \n", resp1, resp2);
		}
	}
	return 0;
}