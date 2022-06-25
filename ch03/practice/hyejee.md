**3.1 Using the program shown in Figure 3.30, explain what the output will be at LINE A.**  
```C
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
          printf("PARENT: value = %d",value); /* LINE A */

          return 0;
    } 
}
```
**3.2 Including the initial parent process, how many processes are created by the program shown in Figure 3.31?**  
```C
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

**3.3 Original versions of Apple’s mobile iOS operating system provided no means of concurrent processing. Discuss three major complications that concurrent processing adds to an operating system.**  

**3.4 Some computer systems provide multiple register sets. Describe what happens when a context switch occurs if the new context is alreadyloaded into one of the register sets. What happens if the new context is in memory rather than in a register set and all the register sets are in use?**  

**3.5 When a process creates a new process using the fork() operation, which of the following states is shared between the parent process and the child process?**  
**a. Stack**  
**b. Heap**  
**c. Shared memory segments**  

**3.6 Consider the “exactly once”semantic with respect to the RPC mechanism. Does the algorithm for implementing this semantic execute correctly even if the ACK message sent back to the client is lost due to a net- work problem? Describe the sequence of messages, and discuss whether “exactly once” is still preserved.**  

**3.7 Assume that a distributed system is susceptible to server failure. What mechanisms would be required to guarantee the “exactly once” semantic for execution of RPCs?**  

