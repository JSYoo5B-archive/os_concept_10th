## 7.1 Explain why Windows and Linux implement multiple locking mechanisms. Describe the circumstances under which they use spinlocks, mutex locks, semaphores, and condition variables. In each case, explain why the mechanism is needed.

## 7.2  Windows provides a lightweight synchronization tool called slim reader–writer locks. Whereas most implementations of reader–writer locks favor either readers or writers, or perhaps order waiting threads using a FIFO policy, slim reader–writer locks favor neither readers nor writers, nor are waiting threads ordered in a FIFO queue. Explain the benefits of providing such a synchronization tool.

## 7.3  Describe what changes would be necessary to the producer and consumer processes in Figure 7.1 and Figure 7.2 so that a mutex lock could be used instead of a binary semaphore.

wait, signal 연산이 아닌 lock을 획득하고, 해제하는 연산으로 바꾸면 된다

## 7.4  Describe how deadlock is possible with the dining-philosophers problem.

철학자들이 모두 동시에 왼쪽 젓가락을 집어들 경우 데드락이 발생할 수 있다

## 7.5  Explain the difference between signaled and non-signaled states with Windows dispatcher objects.

## 7.6  Assume val is an atomic integer in a Linux system. What is the value of val after the following operations have been completed?

- atomic set(&val,10);
- atomic sub(8,&val);
- atomic inc(&val);
- atomic inc(&val);
- atomic add(6,&val);
- atomic sub(3,&val);

inc는 atomic 한 i++ 의미

10 - 8 + 1 + 1 + 6 - 3 = 7
