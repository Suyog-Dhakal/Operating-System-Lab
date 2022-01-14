#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int pid;
    int fork();
    if (pid == 0)
    {
        printf("i’m the child, my process ID is %d\n", getpid());
        printf("I’m the child and my parent’s ID is %d\n", getppid());
        sleep(5);
        printf("(after sleep)i’m the child, my process ID is %d\n", getpid());
        printf("(after sleep)Im the child and my parent’s ID is %d\n", getppid());
    }
    else
    {
        //anchor
        sleep(10);
        printf("I’m the parent, my process ID is %d", getpid());
        printf("the parent’s process ID is %d", getppid());
    }
}