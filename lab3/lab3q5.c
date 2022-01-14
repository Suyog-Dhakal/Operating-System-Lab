#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#define msgsz 16

void main()
{
    char *msg1 ="hello1";
    char inbuf[msgsz];
    int p[2], pid, j;
    pipe(p);

    pid = fork();
    if (pid > 0)
    {
        close(p[0]);
        write(p[1], msg1, msgsz);
    }
    if (pid == 0)
    {
        close(p[1]);
        read(p[0], inbuf, msgsz);
        printf("%s\n", inbuf);
    }
    exit(0);
}
