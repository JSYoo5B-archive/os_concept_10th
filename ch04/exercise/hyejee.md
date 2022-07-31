**4.8 Provide two programming examples in which multithreading does not provide better performance than a single-threaded solution.**  

**4.9 Under what circumstances does a multithreaded solution using multiple kernel threads provide better performance than a single-threaded solution on a single-processor system?**  

**4.10 Which of the following components of program state are shared across threads in a multithreaded process?**  
**a. Register values**  
**b. Heap memory**  
**c. Global variables**  
**d. Stack memory**  
* b. Heap memeory, c. Global variable  

**4.11 Can a multithreaded solution using multiple user-level threads achieve better performance on a multiprocessor system than on a single-processor system? Explain.**  

**4.12 In Chapter 3, we discussed Google’s Chrome browser and its practice of opening each new tab in a separate process. Would the same benefits have been achieved if, instead, Chrome had been designed to open each new tab in a separate thread? Explain.**  

* 각 탭에 대해 쓰레드를 생성하게 될 경우, 하나의 탭(쓰레드)에 문제가 발생하여 크래시가 발생했을 때 다른 탭(쓰레드)에 영향을 줄 수 있기 때문에 프로세스로 각 탭을 구현했을 때와 다르다.  

**4.13 Is it possible to have concurrency but not parallelism? Explain.**  

* 가능하다. 여러 개의 태스크를 조금씩 태스크 사이를 이동하며 처리하면 parallelism 없이도 concurrency를 이룰 수 있다.    

**4.14 Using Amdahl’s Law, calculate the speedup gain for the following applications:**  
• 40 percent parallel with (a) eight processing cores and (b) sixteen processing cores  
• 67 percent parallel with (a) two processing cores and (b) four pro- cessing cores  
• 90 percent parallel with (a) four processing cores and (b) eight pro- cessing cores  

**4.15 Determine if the following problems exhibit task or data parallelism:**  
• Using a separate thread to generate a thumbnail for each photo in a collection  
• Transposing a matrix in parallel  
• A networked application where one thread reads from the network and another writes to the network  
• The fork-join array summation application described in Section 4.5.2  
• The Grand Central Dispatch system  

**4.16 A system with two dual-core processors has four processors available for scheduling. A CPU-intensive application is running on this system. All input is performed at program start-up, when a single file must be opened. Similarly, all output is performed just before the program termi- nates, when the program results must be written to a single file. Between start-up and termination, the program is entirely CPU-bound. Your task is to improve the performance of this application by multithreading it. The application runs on a system that uses the one-to-one threading model (each user thread maps to a kernel thread).**  
• How many threads will you create to perform the input and output? Explain.  
• How many threads will you create for the CPU-intensive portion of the application? Explain.  

**4.17 Consider the following code segment:**  
```C
pid_t pid;

pid = fork();

if (pid == 0) { /* child process */
    fork();
    thread_create( . . .);
}

fork();
```
**a. How many unique processes are created?**  
**b. How many unique threads are created?**  

* a. 5개의 서로 다른 프로세스들이 추가적으로 생성된다(부모 프로세스까지 생각한다면 6개).  
* b. 2개의 서로 다른 쓰레드들이 생성된다.  

**4.18 As described in Section 4.7.2, Linux does not distinguish between pro- cesses and threads. Instead, Linux treats both in the same way, allowing a task to be more akin to a process or a thread depending on the set of flags passed to the clone() system call. However, other operating systems, such as Windows, treat processes and threads differently. Typically, such systems use a notation in which the data structure for a process contains pointers to the separate threads belonging to the process. Contrast these two approaches for modeling processes and threads within the kernel.**  

**4.19 The program shown in Figure 4.23 uses the Pthreads API. What would be the output from the program at LINE C and LINE P?**  

```C
#include <pthread.h> 
#include <stdio.h>

int value = 0;

void *runner(void *param); /* the thread */

int main(int argc, char *argv[])
{
    pid_t pid;
    pthread_t tid; 
    pthread_attr_t attr;

    pid = fork();

    if (pid == 0) { /* child process */ 
        pthread_attr init(&attr);
        pthread_create(&tid,&attr,runner,NULL); 
        pthread_join(tid,NULL);
        printf("CHILD: value = %d",value); /* LINE C */
    }
    else if (pid > 0) { /* parent process */
        wait(NULL);
        printf("PARENT: value = %d",value); /* LINE P */
    }
}

void *runner(void *param) { 
    value = 5;
    pthread_exit(0);
}
```
**4.20 Consider a multicore system and a multithreaded program written using the many-to-many threading model. Let the number of user-level threads in the program be greater than the number of processing cores in the system. Discuss the performance implications of the following scenarios.**  
**a. The number of kernel threads allocated to the program is less than the number of processing cores.**  
**b. The number of kernel threads allocated to the program is equal to the number of processing cores.**  
**c. The number of kernel threads allocated to the program is greater than the number of processing cores but less than the number of user-level threads.**  

**4.21 Pthreads provides an API for managing thread cancellation. The pthread setcancelstate() function is used to set the cancellation state. Its prototype appears as follows:**  
```C
pthread_setcancelstate(int state, int *oldstate)
```
**The two possible values for the state are `PTHREAD_CANCEL_ENABLE` and `PTHREAD_CANCEL_DISABLE`.
Using the code segment shown in Figure 4.24, provide examples of two operations that would be suitable to perform between the calls to disable and enable thread cancellation.**  
```C
int oldstate;

pthread setcancelstate(PTHREAD_CANCEL_DISABLE, &oldstate); 

/* What operations would be performed here? */

pthread setcancelstate(PTHREAD_CANCEL_ENABLE, &oldstate);
```