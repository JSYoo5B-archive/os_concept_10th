#include <stdio.h> 
#include <unistd.h>

int main()
{
    int num = 0;

    scanf("%d", &num);

    pid_t child_pid;

    child_pid = fork();

    while(num != 1){
        printf("%d ", num);

        if(num % 2 == 0) num /= 2;

        else num = num * 3 + 1;
    }

    printf("1\n");
}
