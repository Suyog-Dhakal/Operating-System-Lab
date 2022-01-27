#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#define msgsz 16

void main()
{
    char *msg1 = "hello one";
    char *msg2 = "hello two";
    char *msg3 = "hello three";
    char inbuf[msgsz];
    int p[2];

    pipe(p);

    if(!fork())
    {
        printf("\n message sent from child:%s",msg1);
        fflush(stdout);
        write(p[1],msg1,msgsz);
        printf("\nMessage sent from child:%s",msg2);
        fflush(stdout);
        write(p[1],msg2,msgsz);
        printf("\nmessage sent from child:%s",msg3);
        fflush(stdout);
        write(p[1],msg3,msgsz);
    }
    else{
        char inbuff[msgsz];
        for(int i=0;i<3;i++){
            read(p[0],inbuf,msgsz);
            printf("\nMessage received in parent: %s",inbuf);
            fflush(stdout);
        }
    }
}