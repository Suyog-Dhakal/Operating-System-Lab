#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

#define DEL1 10000
#define DEL2 50000

int main() {
    int i,d;
    char c;

    if(!fork())
    {
        for(c='a';c<='z';c++)
        {
            printf("%c\t",c);
            fflush(stdout);
            for(d=0;d<DEL1;d++);
        }
        exit(0);
    }else{
        for(i=0;i<=10;i++)
        {
            printf("%i\n",i);
            fflush(stdout);
            for(d=0;d<=DEL2;d++);
        }
        exit(0);
    }
}