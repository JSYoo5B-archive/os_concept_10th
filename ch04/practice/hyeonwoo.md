## 4.1  Provide three programming examples in which multithreading provides better performance than a single-threaded solution.

- 웹 서버에서 서비스의 요청과 응답까지 하나의 스레드로 수행될 때, 여러 사용자를 수용하기 위해 멀티 스레드 사용
- 빠른 연산을 위해 사용,,?

## 4.2  Using Amdahl’s Law, calculate the speedup gain of an application that has a 60 percent parallel component for (a) two processing cores and (b) four processing cores.
(a) S = 2, P = 0.6

S / S ( 1 - P ) + P 

= 2 / 2 * 0.4 + 0.6

= 1.428

(b) S = 4, P = 0.6

S / S ( 1 - P ) + P

= 4 / 4 * 0.4 + 0.6

= 1.818

## 4.3 Does the multithreaded web server described in Section 4.1 exhibit task or data parallelism?

- 요청 건마다 thread를 생성하기 때문에 task parallelism

## 4.4  What are two differences between user-level threads and kernel-level threads? Under what circumstances is one type better than the other?

- user level thread는 user program과 관련되있는 스레드, 즉, 스레드 개념을 프로그래밍 레벨에서 추상화한 것이다. 따라서 해당 프로그램의 library를 이용하여 구현한다. ex) Java Thread Class
- kernel level thread는 OS에서 구현한다.
- 컨텍스트 스위칭이 자주 발생한다면 비용이 더 적게 드는 user level thread를 사용하는 것이 좋아보인다. kernel level thread에서 컨텍스트 스위칭이 일어나게 되면 커널이 개입하기 때문에 더 많은 비용이 발생한다.

## 4.5 Describe the actions taken by a kernel to context-switch between kernel-level threads.

- 교환될 스레드는 TCB에  CPU register, stack 등을 저장하고, 실행될 스레드의 TCB를 복원하여 메모리에 올려야한다
- user level thread에서의 context-switch는 다를까,,? 왜 thread context switching 을 물어볼 때 굳이 kernel level thread라 명시를 해놨을까?

## 4.6  What resources are used when a thread is created? How do they differ from those used when a process is created?

- Thread가 생성될 때는 register, program counter, stack이 할당되어야 한다
- Process가 생성될 때는 code, data, virtaul memory 등 할당되어야합니다

## 4.7  Assume that an operating system maps user-level threads to the kernel using the many-to-many model and that the mapping is done through LWPs. Furthermore, the system allows developers to create real-time threads for use in real-time systems. Is it necessary to bind a real-time thread to an LWP? Explain.

- 애플리케이션에 요청을 보낼 때, thread가 LWP 에 바인딩되어 있지 않다면 요청을 보내고나서 바인딩 될 때까지 기다려야하기 때문에 bind를 해줘야한다고 생각한다. 그래서 서비스가 지연되지 않고 바로 처리할 수 있다
