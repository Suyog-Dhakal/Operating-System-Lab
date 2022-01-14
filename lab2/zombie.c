#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>


int main()
{
    //Fork returns process id in parent process
    pid_t child_pid = fork();

    //parent process
    if(child_pid > 0){
        sleep(5000);
        printf("parent");
    }
    //child process
    else
        exit(0);
    
    return 0;
}