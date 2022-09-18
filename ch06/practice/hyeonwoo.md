## 6.1 In Section 6.4, we mentioned that disabling interrupts frequently can affect the system’s clock. Explain why this can occur and how such effects can be minimized.

지정된 time quantum 보다 프로세스가 시간을 더 쓰기 때문에 system clock에 문제가 생기게 된다.

## 6.2 What is the meaning of the term busy waiting? What other kinds of waiting are there in an operating system? Can busy waiting be avoided altogether? Explain your answer.

busy waiting은 한 프로세스가 critical section에 있을 때 다른 프로세스들은 cs에 접근하지 못하기 때문에 cs에 있는 프로세스가 section에서 나올 때까지 무한 루프를 도는 것을 말합니다.

busy waiting을 해결하는 방법은 block & wake up 방식이 있습니다.

## 6.3 Explain why spinlocks are not appropriate for single -processor systems yet are often used in multiprocessor systems.

CPU가 하나 존재하면 컨텍스트 스위칭을 하면서 프로세스가 race condition 이 발생하지 않기 때문입니다.

## 6.4 Show that, if the wait() and signal() semaphore operations are not executed atomically, then mutual exclusion may be violated.

wait 경우에는 자원만 빼고 자원을 할당하지 않을 수도 있고, signal 경우에는 자원을 늘리기만 하고 프로세스를 깨우지 않을 수도 있습니다.

## 6.5 Illustrate how a binary semaphore can be used to implement mutual exclusion among n processes.

```c
semaphore mutex;

do{

	wait(mutex);

	// criticial section

	signal(mutex);
	
} while(true)
```

## 6.6 Race conditions are possible in many computer systems. Consider a banking system that maintains an account balance with two functions: deposit(amount) and withdraw(amount). These two functions are passed the amount that is to be deposited or withdrawn from the bank account balance. Assume that a husband and wife share a bank account. Concurrently, the husband calls the withdraw() function, and the wife calls deposit(). Describe how a race condition is possible and what might be done to prevent the race condition from occurring.

withdraw나 deposit 하는 연산 중에는 인터럽트가 발생하지 않도록 두 연산을 행할 때는 atomic이 보장되어야합니다.
