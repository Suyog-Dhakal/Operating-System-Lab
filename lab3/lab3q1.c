#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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
        close(pfd[0]);
        printf("press a key");
        scanf("%c", &c);
        write(pfd[1], &c, 1);
        exit(0);
    }
    else
    {
        close(pfd[1]);
        read(pfd[0], &c, 1);

        printf("I received the character %c",c);
        exit(0);
    }
}