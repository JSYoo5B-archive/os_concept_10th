## 4.8  Provide two programming examples in which multithreading does *not* provide better performance than a single-threaded solution

- 싱글 코어에서는 멀티 스레딩의 장점을 발휘할 수 없다.
- 싱글 코어에서는 여러 스레드가 concurrency 하게 실행되지만, 멀티 코어에서는 parallelsim하게 실행되므로 싱글 코어에서는 better performance를 내지 못한다

## 4.9  Under what circumstances does a multithreaded solution using multiple kernel threads provide better performance than a single-threaded solution on a single-processor system?

- 비동기를 지원하는 멀티 스레드 환경에서는 여러 요청을 동시에 받을 수 있지만, 싱글 프로세서 + 싱글 스레드 환경에서는 하나의 요청의 응답이 올 때까지 다른 요청들은 대기하고 있어야한다

## 4.10 Which of the following components of program state are shared across threads in a multithreaded process?

1. Register values
2. Heap memory
3. Global variables
4. Stack memory

- 고유한 code, data, register, program counter 등을 가지므로 b,c 이다

## 4.11  Can a multithreaded solution using multiple user-level threads achieve better performance on a multiprocessor system than on a single-processor system? Explain.

- 멀티 스레드를 사용하면 멀티 코어 환경에서 더욱 효율적이다
- 단일 코어에서는 연산을 수행할 수 없는 CPU가 1개이므로 스레드가 가질 수 있는 CPU 자원은 1개이다
- 따라서 멀티스레드는 여러 CPU를 가진 멀티 코어 환경에서 효율적이다

## 4.12  In Chapter 3, we discussed Google’s Chrome browser and its practice of opening each new tab in a separate process. Would the same benefits have been achieved if, instead, Chrome had been designed to open each new tab in a separate thread? Explain.

- 하나의 탭이 잘못되면 나머지 탭에 모두 영향을 끼치게 된다
- 왜냐하면 프로세스는 고유한 메모리 공간을 가지기 때문에 서로에게 영향을 주지 않지만 스레드는 메모리 영역을 공유하기 때문에 하나의 스레드가 잘못되면 다른 스레드에게 영향을 주게 된다

## 4.13 Is it possible to have concurrency but not parallelism? Explain.

- 싱글 코어에서 멀티 스레드 환경이라면 concurrency는 가능하지만 CPU 자원은 1개이므로 parallelism하게 동작하지 않는다

## 4.14  Using Amdahl’s Law, calculate the speedup gain for the following applications:

- 40 percent parallel with (a) eight processing cores and (b) sixteen
processing cores
- 67 percent parallel with (a) two processing cores and (b) four pro-
cessing cores
- 90 percent parallel with (a) four processing cores and (b) eight pro-
cessing cores

1. (1 / (0.4 + (1 - 0.4) / 8) , (1 / (0.4 + (1 - 0.4) / 16)
    - 2.105, 2.285
2. 1.197, 1.3289
3. 1.081, 1.095

## 4.15 Determine if the following problems exhibit task or data parallelism:

- Using a separate thread to generate a thumbnail for each photo in a collection
    - 각 사진마다 썸네일을 만드는 것이기 때문에 task
- Transposing a matrix in parallel
    - 행렬의 각 element에 각각 연산을 하여 합치면 되기 때문에 data
- A networked application where one thread reads from the network and another writes to the network
    - 하나의 데이터를 가지고 하는 기능이 다르기 때문에 task
- The fork-join array summation application described in Section 4.5.2
    - array sum은 data같은데 fork를 해서 서로 다른 task에서 행하기 때문에 task
- The Grand Central Dispatch system
    - 무엇인지 검색해서 보니 다중 코어 프로세서 시스템이라고 해서 task

## 4.16  A system with two dual-core processors has four processors available for scheduling. A CPU-intensive application is running on this system. All input is performed at program start-up, when a single file must be opened. Similarly, all output is performed just before the program terminates, when the program results must be written to a single file. Between start-up and termination, the program is entirely CPU-bound. Your task is to improve the performance of this application by multithreading it. The application runs on a system that uses the one-to-one threading model (each user thread maps to a kernel thread).

- How many threads will you create to perform the input and output? Explain.
- How many threads will you create for the CPU-intensive portion of the application? Explain.

- 연산을 수행할 수 있는 CPU는 총 4개라고 했으며 일대일 모델을 사용하므로 각 유저 레벨 스레드는 커널 레벨 스레드에 1:1로 맵핑된다
- 따라서 연산할 수 있는 CPU의 개수만큼 스레드를 생성하는 것이 가장 효율적이지 않을까?
- 많으면 4개를 제외한 나머지 스레드는 놀게 되므로 스레드를 생성하기 위해 사용된 리소스가 아깝고, 적으면 CPU가 놀고 있기 때문에 CPU가 낭비된다
- 또한, 스레드가 input, output을 모두 처리하기 때문에 input, output 스레드를 따로 만들어야할까?

## 4.17 Consider the following code segment:

```c
pid_t pid;

pid = fork();

if (pid == 0) { /* child process */
		fork();
    thread_create(...);
}

fork();
```

a. How many unique processes are created?

- 처음 프로세스에서 fork 되어 p - 2
- 자식 프로세스에서 fork하고 스레드 생성하므로 p - 3 t - 1
- fork 한번 더 하므로, p - 6, t - 2

b. How many unique threads are created?

- 2개

## 4.18 As described in Section 4.7.2, Linux does not distinguish between processes and threads. Instead, Linux treats both in the same way, allowing a task to be more akin to a process or a thread depending on the set of flags passed to the clone() system call. However, other operating systems, such as Windows, treat processes and threads differently. Typically, such systems use a notation in which the data structure for a process contains pointers to the separate threads belonging to the process. Contrast these two approaches for modeling processes and threads within the kernel.

## 4.19 he program shown in Figure 4.23 uses the Pthreads API. What would be the output from the program at LINE C and LINE P?

```c
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
        pthread_attr_init(&attr);
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

- LINE C
    - 5
- LINE P
    - 자식 프로세스로부터 영향을 받지 않으니까 0

## 4.20 Consider a multicore system and a multithreaded program written using the many-to-many threading model. Let the number of user-level threads in the program be greater than the number of processing cores in the system. Discuss the performance implications of the following scenarios.**

**a. The number of kernel threads allocated to the program is less than the number of processing cores.**

**b. The number of kernel threads allocated to the program is equal to the number of processing cores.**

**c. The number of kernel threads allocated to the program is greater than the number of processing cores but less than the number of user-level threads.**

## **4.21 Pthreads provides an API for managing thread cancellation. The pthread setcancelstate() function is used to set the cancellation state. Its prototype appears as follows:**

```c
pthread_setcancelstate(int state, int *oldstate)
```

**The two possible values for the state are PTHREAD_CANCEL_ENABLE and PTHREAD_CANCEL_DISABLE. Using the code segment shown in Figure 4.24, provide examples of two operations that would be suitable to perform between the calls to disable and enable thread cancellation.**

```c
int oldstate;

pthread setcancelstate(PTHREAD_CANCEL_DISABLE, &oldstate); 

/* What operations would be performed here? */

pthread setcancelstate(PTHREAD_CANCEL_ENABLE, &oldstate);
```
