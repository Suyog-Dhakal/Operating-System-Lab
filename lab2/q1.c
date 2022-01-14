#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main() {
    if(!fork())
    {
        printf("hello! I'm from child and my process id is %d.\nMy parent process id is %d\n",getpid(),getppid());
    }
    else{
        printf("hi! I'm from parent and my process id is %d",getpid());
    }
    return 0;
}
