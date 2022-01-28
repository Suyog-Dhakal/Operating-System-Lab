// #include <stdio.h>
// #include <sys/types.h>
// #include <unistd.h>
// #include <sys/wait.h>
// #define msgsz 16

// void main() {
//     char *msg="hello1";
//     char inbuf[msgsz];
//     int p[2],pid,j;
//     pipe(p);
//     pid=fork();
//     if(pid>0)
//     {
//         close(p[0]);
//         write(p[1],msg1,msgsz);
//     }
//     if(pid==0)
//     {
//         close(p[1]);
//         read(p[0],inbuf,msgsz);
//         printf("%s\n",inbuf);
//     }
//     exit(0);
// }

 #include <stdio.h>
 #include <sys/types.h>
 #include <unistd.h>
 #include <sys/wait.h>
#define msgsz 16

int main() {
    char *msg = "hello1";
    char inbuf[msgsz];
    int p[2], pid, j;
    pipe(p);
    pid = fork();
    if (pid > 0) {
        if (close(p[0]) == 0) {
            printf("Read file descriptor closed successfully!\n");
        }
        if (read(p[0], inbuf, msgsz) == -1) {
            printf("Unable to read from pipe!\n");
        } else {
            printf("Successfully read content from pipe!\n");
            printf("In parent, read data : %s\n", inbuf);
        }
        write(p[1], msg, msgsz);
    }
    if (pid == 0) {
        if (close(p[1]) == 0) {
            printf("Write file descriptor closed successfully!\n");
        }
        if (write(p[1], msg, msgsz) == -1) {
            printf("Unable to write to pipe!\n");
        } else {
            printf("Successfully written content to pipe!\n");
        }
        read(p[0], inbuf, msgsz);
        printf("In child, data read : %s\n", inbuf);
    }
    exit(0);
}
