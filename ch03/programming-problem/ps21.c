#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if(argc < 2) {
        printf("잘못된 입력");
        return 0;
    }

    int num = atoi(argv[1]);

    pid_t child_pid;

    child_pid = fork();

    if(child_pid == 0){
        while(num > 2){
            printf("%d ", num);

            if(num % 2 == 0) num /= 2;

            else num = num * 3 + 1;
        }
         printf("1\n");
    }
    else if(child_pid > 0){
        printf("Parent process wait\n");
        wait(NULL);
        printf("Child process exit\n");
    }
}
