#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int exflag = 0;
void main()
{
    char c;
    int pfd[2];
    if (pipe(pfd) > 0)
    {
        printf("error");
    }
    if (!fork())
    {
        printf("press a key");
        scanf("%c", &c);
        exflag = 1;
        write(pfd[1], &exflag, 1);
        exit(0);
    }
    else
    {
        read(pfd[0], &exflag, 1);
        while (!exflag);

        printf("I received the character");
        exit(0);
    }
}