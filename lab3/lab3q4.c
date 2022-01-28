// #include <stdio.h>
// #include <sys/types.h>
// #include <unistd.h>

// void main()
// {
//     int p[2],pid;
//     pipe(p);
//     pid = fork();
//     if (pid == 0)
//         printf("in the child p[0] is % d p[1] is % d\n", p[0], p[1]);
//     else
//         printf("in the parent p[0] is % d p[1] is % d\n", p[0], p[1]);
// }

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

void main()
{
    int pfd[2];
    if (pipe(pfd) < 0)
        printf("error ");
    if (!fork())
    {
        char data;
        printf("I’m parent\n");
        printf("press any key to exit……\n");
        scanf("%c",&data);
        write(pfd[1], &data, 1);
        wait(NULL);
        printf("parent exiting\n");
    }
    else
    {
        char data;
        read(pfd[0], &data, 1);
        printf("I’m child\n");
        printf("received %c from parent\n", data);
        printf("child exiting……\n");
        exit(0);
    }
}