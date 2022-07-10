## 3.8

### Describe the actions taken by a kernel to context-switch between processes

1. switch 하는 프로세스의 정보를 PCB에 저장한다
2. 스케줄러를 통해 switch 되는 프로세스를 결정한다
3. switch 되는 프로세스의 PCB를 메모리에 적재한다

## 3.9

### Construct a process tree similar to Figure 3.7. To obtain process information for the UNIX or Linux system, use the command ps -ael. Use the command man ps to get more information about the ps command. The task manager on Windows systems does not provide the parent process ID, but the ***process monitor*** tool, available from technet.microsoft.com, provides a process-tree tool.

## 3.10

### Explain the role of init (or systemd) process on UNIX and Linux systems in regard to process termination

- 부모 프로세스가 wait()를 호출하는 대신 종료를 하여 자식 프로세스가 고아 프로세스가 된다
- 이때 고아 프로세스가 가지고 있는 자원을 반납하기 위해 고아 프로세스의 새로운 부모 프로세스로 init 프로세스를 지정하여 init 프로세스는 wait()를 호출하여 고아 프로세스를 종료 시키고 리소스를 반납시킨다

## 3.11

### Including the initial parent process, how many processes are created by
the program shown in Figure 3.32?

```c
#include <stdio.h> 
#include <unistd.h>

int main()
{
	int i;

	for(int i = 0; i < 4; i++) fork();

	return 0;	
}
```

- 1번째 fork
    - 부모 1 , 자식 1
- 2번째 fork
    - 부모 1, 자식 1 + 자식 2
- 3번째 fork
    - 부모 1, 자식 1 + 자식 2 + 자식 4
- 4번째 fork
    - 부모 1, 자식 1 + 자식 2 + 자식 4 + 자식 8
- 총 16개

## 3.12

### Explain the circumstances under which the line of code marked printf("LINE J") in Figure 3.33 will be reached.

```c
#include <sys/types.h> 
#include <stdio.h> 
#include <unistd.h>

int main()
{
    pid t pid;
    
    /* fork a child process */
    pid = fork();
    
    if (pid < 0) { /* error occurred */ 
        fprintf(stderr, "Fork Failed"); 
        return 1;
    }
    else if (pid == 0) { /* child process */
        execlp("/bin/ls","ls",NULL);
        printf("LINE J");
    }
    else { /* parent process */
        /* parent will wait for the child to complete */
        wait(NULL);
        printf("Child Complete");
    }
    return 0;
}
```

- 부모 프로세스는 else 부분에 들어가서 wait 한다
- 자식 프로세스는 else if 에 들어가서 ls를 실행한다
    - exec()를 호출한 프로세스는 새로운 프로세스에 의해 덮어 쓰여지게 됩니다.
    - execlp를 호출하기 때문에 print(”LINE J”)은 출력하지 않고 ls만을 출력한다
- 자식 프로세스는 죽는다
- 자식 프로세스가 죽고 나서 부모 프로세스는 Child Complete 가 출력한다

## 3.13

### Using the program in Figure 3.34, identify the values of pid at lines A, B,
C, and D. (Assume that the actual pids of the parent and child are 2600
and 2603, respectively.)

```c
#include <sys/types.h> 
#include <stdio.h> 
#include <unistd.h>

int main()
{
    pid t pid, pid1;
    
    /* fork a child process */
    pid = fork();
    
    if (pid < 0) { /* error occurred */ 
        fprintf(stderr, "Fork Failed"); 
        return 1;
    }
    else if (pid == 0) { /* child process */
        pid1 = getpid();
        printf("child: pid = %d",pid); /* A */
        printf("child: pid1 = %d",pid1); /* B */
    }
    else { /* parent process */
        pid1 = getpid();
        printf("parent: pid = %d",pid); /* C */
        printf("parent: pid1 = %d",pid1); /* D */
        wait(NULL);
    }

    return 0;
 }
```

- getpid는 현재 실행 중인 프로세스의 pid를 얻는 함수
- A는 fork로부터 반환받았으므로 0
- B는 현재 실행되고 있는 프로세스의 pid이므로 자식 프로세스의 pid인 2603
- C는 부모 프로세스에서 fork로부터 반환받은 것은 자식 프로세스의 pid이기 때문에 2603
- D는 현재 실행되고 있는 프로세스는 parent process이므로 2600

## 3.14

### Give an example of a situation in which ordinary pipes are more suitable
than named pipes and an example of a situation in which named pipes
are more suitable than ordinary pipes.

## 3.15

### Consider the RPC mechanism. Describe the undesirable consequences that could arise from not enforcing either the “at most once” or “exactly once” semantic. Describe possible uses for a mechanism that has neither of these guarantees.

## 3.16

### Using the program shown in Figure 3.35, explain what the output will be at lines X and Y.

```c
#include <sys/types.h> 
#include <stdio.h> 
#include <unistd.h>

#define SIZE 5

int nums[SIZE] = {0,1,2,3,4};

int main()
{
    int i;
    pid t pid;

    pid = fork();

    if (pid == 0) {
        for (i = 0; i < SIZE; i++) {
            nums[i] *= -i;
            printf("CHILD: %d ",nums[i]); /* LINE X */
        } 
    }
    else if (pid > 0) { 
				wait(NULL);
        for (i = 0; i < SIZE; i++)
                printf("PARENT: %d ",nums[i]); /* LINE Y */
    }

    return 0;
}
```

- X는 0, -1, -4, -9, -16
- Y는 0, 1, 2, 3, 4
- 부모, 자식 프로세스는 데이터를 공유하지 않기 때문에 서로에게 영향을 주지 않는다

## 3.17

### What are the benefits and the disadvantages of each of the following? Consider both the system level and the programmer level.

1. Synchronous and asynchronous communication
2. Automatic and explicit buffering
3. Send by copy and send by reference
4. Fixed-sized and variable-sized messages
