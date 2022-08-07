## [공룡책 3장 Exercise Problems]

#### 3.8 프로세스간 context-switch가 일어날 때 커널이 어떤식으로 작동하는지 설명하여라.
->
1. 운영체제에서 프로세스 스케줄러에 의한 인터럽트 발생
2. 프로세스가 실행되는 사용자 모드에서 커널 모드로 전환
3. 기존에 실행되고 있던 프로세스 정보를 PCB에 저장
4. PCB에 있는 다음 실행 프로세스 상태를 복구
5. 커널 모드에서 사용자 모드로 전환하여 프로세스 실행

#### 3.9 Construct a process tree similar to Figure 3.7. To obtain process infor- mation for the UNIX or Linux system, use the command ps -ael. Use the command man ps to get more information about the ps com- mand. The task manager on Windows systems does not provide the parent process ID, but the process monitor tool, available from tech- net.microsoft.com, provides a process-tree tool.
->

#### 3.10 프로세스 종료와 관련하여 UNIX 및 Linux 시스템에서 init(또는 systemd) 프로세스의 역할을 설명하여라.
->
Init 프로세스는 커널 부팅이 완료된 뒤 실행되는 첫 번째 프로세스이며, 커널이 직접 실행하는 유일한 프로세스이다. Init 프로세스는 시스템의 초기화와 관리를 위해 백그라운드 서비스 실행, 네트워크/파일 시스템 등 초기화, 프로세스 상태 모니터링, 데몬/고아 프로세스 해제, 저널링 등의 역할을 수행한다.

#### 3.11 초기 부모 프로세스를 포함하여, 그림 3.32에 표시도니 프로그램에 의해 몇 개의 프로세스들이 생성되는가?

```
#include <stdio.h> 
#include <unistd.h>

int main()
{
    int i;

    for (i = 0; i < 4; i++)
      fork();

    return 0;
}
```
-> 
for 문이 4번 반복되기 때문에 2^4=16개의 프로세스가 생성된다.

#### 3.12 그림 3.33에서 printf("LINE J")로 표시된 코드 라인에 도달하는 상황을 설명하여라.

```
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
-> 
 fork() 시스템 콜을 통해 자식 프로세스를 생성한 후 부모 프로세스는 wait()에 의해 자식 프로세스가 종료될 때까지 기다린다. 자식 프로세스는 pid==0인 조건에 걸려 ls를 실행, `LINE J`는 출력하지 않고 프로세스가 종료된다. 자식 프로세스가 return 되었기 때문에 부모 프로세스는 wait 상태에서 빠져나와 `Child Complete`를 출력한다.

#### 3.13 그림 3.34의 프로그램을 사용하여 선 A, B, C 및 D에서 pid 값을 확인하여라. (부모와 자녀의 실제 pid가 각각 2600과 2603이라고 가정)
```
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
->  
A : 0  
B : 자식 프로세스의 pid는 2603으로 가정, 2603  
C : 자식 프로세스의 pid 출력, 2603  
D : 부모 프로세스의 pid를 출력, 2600

#### 3.14 Ordinary pipe가 Named pipe보다 적합한 상황과 Named pipe가 Ordinary pipe보다 적합한 상황을 제시하시오.
->
 Ordinary pipe 사용이 더 적합한 경우 : 생산자-소비자 현태로 두 프로세스 간 통신할 경우 적합하다.
 Named pipe 사용이 더 적합한 경우 : Named pipe는 양방향 통신이 가능하므로 여러 프로세스간 통신이 필요한 경우 Ordinary pipe보다 더 적은 수의 파이프로 통신이 가능하다.

#### 3.15 Consider the RPC mechanism. Describe the undesirable consequences that could arise from not enforcing either the “at most once” or “exactly once” semantic. Describe possible uses for a mechanism that has neither of these guarantees.
-> 

#### 3.16 그림 3.35에 표시된 프로그램을 사용하여 X line과 Y line에서 출력되는 것을 설명하여라.
```
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
    else if (pid > 0) { wait(NULL);
        for (i = 0; i < SIZE; i++)
                printf("PARENT: %d ",nums[i]); /* LINE Y */
    }

    return 0;
}
```
-> 
 X : `CHILD: 0`, `CHILD: -1`, `CHILD: -4`, `CHILD: -9`, `CHILD: -16`  
 Y : `PARENT: 0`, `PARENT: 1`, `PARENT: 2`, `PARENT: 3`, `PARENT: 4`

#### 3.17 아래 질문에서 각각의 장단점은 무엇인가? 시스템 레벨과 프로그래머 레벨에서 생각해보아라.
a. 동기와 비동기의 커뮤니케이션  
->  
동기 커뮤니케이션은 설계가 간단하고 직관적이지만 결과가 주어질 때까지 대기해야 한다는 단점이 있으며, 비동기 커뮤니케이션은 요청에 따른 결과가 반환되는 시간 동안 다른 작업을 수행할 수 있다는 장점이 있지만 설계가 복잡하다는 단점이 있다.

b. Automatic and explicit buffering  
->   

c. 복사로 전송과 참조로 전송  
->  
복사 전송은 수신자가 매개변수 상태를 변경할 수 없지만, 참조 전송은 매개 변수 상태를 변경할 수 있다. 

d. 고정길이 메시지와 가변길이 메시지  
->  
고정길이 메시지는 메시지의 크기가 버퍼보다 작을 때 사용하고 가변길이 메시지는 버퍼의 크기를 모를 때 사용한다.