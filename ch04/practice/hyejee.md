**4.1 Provide three programming examples in which multithreading provides better performance than a single-threaded solution.**  

**4.2 Using Amdahl’s Law, calculate the speedup gain of an application that has a 60 percent parallel component for (a) two processing cores and (b) four processing cores.**  
* (a) 약 1.428배  
* (b) 약 1.818배  

**4.3 Does the multithreaded web server described in Section 4.1 exhibit task or data parallelism?**  
* 각 쓰레드가 동일한 task를 서로 다른 데이터에 대해 수행하고 있기 때문에 data parallelism이다.  

**4.4 What are two differences between user-level threads and kernel-level threads? Under what circumstances is one type better than the other?**  
* user-level thread와 kernel-level tread의 가장 큰 차이점은 thread를 managing하는 주체이다. 운영체제가 직접 지원하고 관리하는 kernel-level thread와 달리 user-level thread는 운영체제의 도움 없이 user space의 thread library에 의해 관리된다.  
* kernel-level trhead는 kernel-level에서 관리되기 때문에 비용이 더 비싸다. 꼭 kernel space에 존재해야하는 쓰레드가 아니라면 user-level thread를 사용하여 처리하고, many-to-one 모델처럼 다수의 user-level thread들을 하나의 kernel-level thread로 매핑시켜 비용을 절감시켜줄 수 있다.  

**4.5 Describe the actions taken by a kernel to context-switch between kernel- level threads.**  
* context-switch 될 쓰레드의 CPU 레지스터 내용들을 저장하고, 새로 스케쥴된 쓰레드의 레지스터 내용들을 restore한다.  

**4.6 What resources are used when a thread is created? How do they differ from those used when a process is created?**  

**4.7 Assume that an operating system maps user-level threads to the kernel using the many-to-many model and that the mapping is done through LWPs. Furthermore, the system allows developers to create real-time threads for use in real-time systems. Is it necessary to bind a real-time thread to an LWP? Explain.**  