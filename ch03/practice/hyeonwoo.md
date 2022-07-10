**3.1 Using the program shown in Figure 3.30, explain what the output will be at LINE A.**

```java
#include <sys/types.h>
#include <stdio.h> 
#include <unistd.h>

int value = 5;

int main()
{
    pid_t pid;
    pid = fork();

    if (pid == 0) { /* child process */ 
        value += 15;

        return 0;
    }
    else if (pid > 0) { /* parent process */
					wait(NULL);
          printf("PARENT: value = %d",value); /* LINE A */return 0;
    } 
}
```

- fork를 하게 되면 새로운 자식 프로세스가 생성됩니다
- 자식 프로세스는 pid가 0이기 때문에 value가 20이 됩니다
- 하지만 pid > 0 인 부모 프로세스는 value가 그대로 5입니다

**3.2 Including the initial parent process, how many processes are created by the program shown in Figure 3.31?**

```java
#include <stdio.h> 
#include <unistd.h>

int main()
{
    /* fork a child process */
		fork();

    /* fork another child process */
		fork();

    /* and fork another */
		fork();

    return 0;
}
```

- 1번 fork
    - 부모 프로세스 1 + 자식 프로세스 1
- 2번 fork
    - 부모 프로세스 1 + 자식 프로세스 1 + 자식 프로세스 2
- 3번 fork
    - 부모 프로세스 1 + 자식 프로세스 1 + 자식 프로세스 2 + 자식 프로세스 4
- 총 8개

**3.3 Original versions of Apple’s mobile iOS operating system provided no means of concurrent processing. Discuss three major complications that concurrent processing adds to an operating system.**

**3.4 Some computer systems provide multiple register sets. Describe what happens when a context switch occurs if the new context is already loaded into one of the register sets. What happens if the new context is in memory rather than in a register set and all the register sets are in use?**

- 새로운 context가 이미 레지스터 set 중 하나에 로드되어 context switch가 일어나면 CPU는 새로운 context를 로드하기 위해 포인터를 레지스터 set으로 옮긴다
- 새로운 context가 레지스터 set이 아닌 메모리에 있고, 모든 레지스터 set가 사용 중일 경우에는 ,,?
    - 새로운 context가 메모리에 있으면 그냥 실행하면 되는거 아닌가??

**3.5 When a process creates a new process using the fork() operation, which of the following states is shared between the parent process and the child process?**

**a. Stack**

**b. Heap**

**c. Shared memory segments**

- 답이 없지 않나,,?
- fork를 해도 메모리 공간은 따로 할당하지 않나요,,?

**3.6 Consider the “exactly once”semantic with respect to the RPC mechanism. Does the algorithm for implementing this semantic execute correctly even if the ACK message sent back to the client is lost due to a net- work problem? Describe the sequence of messages, and discuss whether “exactly once” is still preserved.**

**3.7 Assume that a distributed system is susceptible to server failure. What mechanisms would be required to guarantee the “exactly once” semantic for execution of RPCs?**
