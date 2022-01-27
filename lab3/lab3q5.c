#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#define msgsz 16

void main()
{
    int errno;
    char *msg1 ="hello1";
    char inbuf[msgsz];
    int p[2], pid, j;
    pipe(p);

    printf("\n initially errno: %d",errno);
    fflush(stdout);
    pid = fork();
    if (pid > 0)
    {
        close(p[0]);
        write(p[1], msg1, msgsz);
        errno=0;
        j=read(p[0],inbuf,msgsz);
        if(j==-1)
            printf("\n read returned error in Parent,errno: %d",errno);
            fflush(stdout);
        wait(NULL);
    }
    else if (pid == 0)
    {
        close(p[1]);
        read(p[0], inbuf, msgsz);
        printf("\nreceived message in child :%s\n", inbuf);
        errno = 0;
        j=write(p[1],msg1,msgsz);
        if(j==-1)
            printf("\n write returned error in child, errno: %d",errno);
            fflush(stdout);
    }
    else{
        printf("error creating process");
    }
    
}
