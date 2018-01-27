#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include  <sys/types.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>


char message[25] = "Cela provient d'un tube";

main()
{
    /*
    * communication PERE --> FILS par pipe
    */
    int p[2];
    int pipe(int[2]);


    if (pipe(p) == -1)
    {
        fprintf(stderr, "erreur ouverture pipe\n");
        exit(1);
    }


    if (fork() == 0)
    {
        /* fils */
        char c;
        close(p[1]);
        while (read(p[0], &c, 1) != 0)
        printf("%c", c);
        close(p[0]);exit(0);
    }
    else
    {
        /* suite pere */
        close(p[0]);
        write(p[1], message, 24);
        close(p[1]);
        exit(0);
    }
}

