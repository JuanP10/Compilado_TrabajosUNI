#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#define OR_ABORT 1
#define OR_TEMP 2
#define OR_RELEASE 3

void write_int(int pipe[], int n)
{
    write(pipe[1], &n, sizeof(int));
}

int read_int(int pipe[])
{
    int n;
    read(pipe[0], &n, sizeof(n));
    return n;
}

void abort_operation()
{
    printf("Abotar operacion.\n");
}

void launch_capsule()
{
    printf("Capsula lanzada.\n");
}

int main()
{
    srand(time(NULL));

    int pipe01[2];
    int pipe10[2];
    int pipe02[2];
    int pipe20[2];

    pipe(pipe01);
    pipe(pipe10);

    if (fork())
    {
        pipe(pipe02);
        pipe(pipe20);

        if (fork())
        {

            close(pipe01[0]);
            close(pipe10[1]);
            close(pipe02[0]);
            close(pipe20[1]);

            time_t start = time(NULL);
            time_t end = start;

            int abort = 0;
            do
            {
                end = time(NULL);
                write_int(pipe01, OR_TEMP);
                int overtemp = read_int(pipe10);
                if (overtemp)
                {
                    abort = 1;
                    break;
                }
            } while (end - start < 5);

            write_int(pipe01, OR_ABORT);
            if (abort)
            {
                write_int(pipe02, OR_ABORT);
            }
            else
            {
                write_int(pipe02, OR_RELEASE);
            }

            wait(NULL);
            wait(NULL);
        }
        else
        {
            close(pipe01[0]);
            close(pipe01[1]);
            close(pipe10[0]);
            close(pipe10[1]);
            close(pipe02[1]);
            close(pipe20[0]);

            int order = read_int(pipe02);
            if (order == OR_ABORT)
            {
                abort_operation();
                launch_capsule();
            }
            else if (order == OR_RELEASE)
            {
                launch_capsule();
            }
        }
    }
    else
    {

        close(pipe01[1]);
        close(pipe10[0]);

        int i;
        int busters[4];

        int order = read_int(pipe01);
        while (order == OR_TEMP)
        {
            int overtemp = 0;
            for (i = 0; i < 4; ++i)
            {
                busters[i] = rand() % 6;
                if (busters[i] > 5)
                {
                    overtemp = 1;
                    break;
                }
            }

            write_int(pipe10, overtemp);
            order = read_int(pipe01);
        }
    }

    return 0;
}
