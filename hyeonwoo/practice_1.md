## 1.1 What are the three main purposes of an operation system?

- 응용 프로그램 간의 하드웨어 사용을 제어하고 조정한다
- 자원 할당자로서 자원을 적절하게 사용할 수 있는 방법을 제공한다
- 다른 프로그램이 유용한 작업을 할 수 있는 환경을 제공한다

## 1.2 We have stressed the need for an operating system to make efficient use of the computing hardware. When is it appropriate for the operating system to forsake this principle and to "waste" resources? Why is such a system not really wasteful?

- 모니터, 키보드, 마우스로 구성된 PC에서 작업하는 사용자는 자원을 독점하도록 설계됐다. 이때는 자원을 얼마나 효율적으로 잘 사용하기보다는 사용자가 수행하는 작업을 최대화하기 위해 운영체제는 사용의 용이성을 위해 설계됐다

## 1.3 What is the main difficulty that a programmer must overcome in writing an operating system for a real-time environment?

- 비동기 처리가 원활하게 처리해야한다. 실시간 채팅 서비스의 경우 비동기 처리가 원활하지 않는다면 사용자가 대화를 보내고 새로고침을 통하여 새로운 리소스를 받아야 보낸 대화 내용을 볼 수 있다. 따라서 real-time 환경을 제공하기 위해서는 비동기 처리가 중요하다고 생각한다

## 1.4 Keeping in mind the various definitions of operating system, consider whether the operating system should include applications such as web browsers and mail programs. Argue both that it should and that is should not and support your answers.

- 포함시키지 않는다
   - 운영체제가 애플리케이션과 하드웨어의 범용적인 인터페이스를 제공하여 애플리케이션마다 하드웨어를 사용하는 기능들을 따로 구현하지 않아도 된다
- 포함시킨다
   - 운영체제에 애플리케이션을 포함시킨다면 분리했을 때보다 액세스하는 시간이 더 짧아질 것이다 그리고 각 애플리케이션마다 운영체제에 특화되어있으므로 퍼포먼스 향상에서의 이점이 있을 것 같다
   - 만약 운영체제에 응용 프로그램이 포함된다면 운영체제마다 애플리케이션이 하드웨어 사용을 제어하고 조정하는 기능들이 각각 구현되어야한다 

## 1.5 How does the distinction between kernel mode and user mode function as a rudimentary form of protection?

- 운영체제와 사용자는 하드웨어, 소프트웨어 자원을 공유하기 때문에 잘못된 프로그램으로 인해 다른 프로그램이나 운영체제 자체가 잘못 실행될 수 없도록 보장해야 한다. 그러기 위해서는 운영체제 코드 실행과 사용자 코드 실행을 구분할 수 있어야한다. 따라서 사용자 모드와 커널 모드로 구분하여 특권 명령, 하드웨어 장치 접근은 커널 모드에서 실행할 수 있다. 즉, 사용자 모드에서는 실행할 수 있는 기능을 매우 제한하여 리소스들을 보호한다

## 1.6 Which of the following instructions should be privileged?
a. set value of timer.  
b. Read the clock.  
c. Clear memory.  
d. Issue a trap instruction.  
e. Turn off interrupts.  
f. Modify entries in device-status table.  
g. Switch from user to kernel mode.  
h. Access I/O device.  

- a, c, d, e, f, g, h

## 1.7 Some early computers protected the operating system by placing it in a memory partition that could not be modified by either the user job or the operating system itself. Describe two difficulties that you think could arise with such a scheme.

## 1.8 Some CPUs provide for more than two modes of operation. What are two possible uses of these multiple modes?

## 1.9 Timers could be used to compute the current time. Provide a short description of how this could be accomplished.
- 타이머는 지정된 시간 후 컴퓨터를 인터럽트 하도록 설정한다. 고정, 가변 타이머가 존재한다. 가변 타이머는 fixed-rate-clock과 계수기로 구현한다. 운영체제는 계수기 값을 설정한다. 클록이 tick 할 때마다 계수기가 감소하여, 계수기가 0이 되면 인터럽트가 발생한다
- 타이머 값을 변경하는 명령은 특권 명령이다.


## 1.10 Give two reasons why caches are useful. What problems do they solve? What problems do the cause? If a cache can be made as large as the device for which it is caching (for instance, a cache as large as a disk), why not make it that large and eliminate the device?

### 캐시의 장점
- 메인 메모리에 비해 접근 시간이 적게 든다
- 메인 메모리보다 처리 시간이 빠르기 때문에 데이터 액세스 속도가 증가하므로 CPU가 더 빠르게 작동한다  

### 캐시의 단점
- 단일 프로세스 환경에서는 문제가 되지 않지만, 멀티 프로세스 환경에서 문제가 발생할 수 있다. 리소스가 캐시까지 오면서 여러 곳에 저장이 되는데, 각 저장장치 시스템에서 데이터의 정합성이 깨지지 않도록 해야한다. 즉, 캐시 일관성 문제가 생기지 않도록 주의해야 한다.

## 1.11 Distinguish between the client-server and peer-to-peer models of distributed systems
### 클라이언트-서버
- 클라이언트가 생성한 요청을 서버에서 처리하여 응답을 보내주는 구조를 가진다
### P2P
- 클라이언트와 서버가 서로 구별되지 않고 모든 노드를 피어라고 하며, 피어끼리 요청과 응답을 처리한다
- 클라이언트-서버 구조는 서버가 병목으로 작용할 수 있는 서버 중심 구조이지만, P2P는 여러 노드에 분산되어 있다.
