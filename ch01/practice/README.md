## 1.1 What are the three main purposes of an operation system?

### 일반 답변 (책 답안, 의도한 바)

1. 하드웨어 제어
2. 자원 관리
3. 프로그램 관리

### 토의한 답변

책에서는 3가지 목적을 말하라고 하지만, 2가지로 요약 가능하다고 생각함.

1. 자원 관리  
   하드웨어 제어나, 앞서 언급한 자원 관리는 자원관리 하나로 묶을 수 있다고 생각함.  
   하드웨어 제어의 경우, 물리적으로 실존하는 자원 관리를 의미하며 (CPU 점유, 물리 메모리)
   앞서 언급한 자원 관리는 추상화된 자원 관리를 의미하는 것이라 생각함 (CPU time quantum, Page frame, sema/mutex ...)  
2. 프로그램들의 공통 요구사항 제공  
   프로그램을 운영체제 없이 직접 작성했을 때 사용하게 될 기능들을 운영체제가 제공해 주는 것  
   일반적으로 System Calls로 제공됨.

## 1.2 We have stressed the need for an operating system to make efficient use of the computing hardware. When is it appropriate for the operating system to forsake this principle and to "waste" resources? Why is such a system not really wasteful?

### 일반 답변 (책 답안, 의도한 바)

GUI의 경우, 사용자의 편의성과 프로그램의 오버헤드에 대한 Trade-off 관계를 가지는 프로그램이다.
CLI같은 명령어로 수행할 수 있는 일을 GUI로 제공함으로서 계산 등의 자원이 낭비된다는 의견으로 보임.

### 다른 답변

먼저 GUI의 경우, GUI의 구현을 GPU에서 제공하지 않고, CPU에서 제공하게 되는 경우로 한정해야 한다 생각함.  
CPU를 사용하여 화면을 렌더링 하는 예시로는 [FrameBuffer](https://bronks.tistory.com/89) 방식이 있다.

GUI를 제외하고 자원을 낭비하는 대표적인 예시로는 Spin-lock이 있다. (Ch06쯤 Busy-waiting 개념에서 다룸)
멀티 코어 환경에서 동기화 문제 발생 시, Sleep으로 대기시키면 문제가 발생할 수 있어, CPU time을 낭비하더라도 프로그램의 정확성을 확보해야 한다.

## 1.3 What is the main difficulty that a programmer must overcome in writing an operating system for a real-time environment?

### 일반 답변 (책 답안, 의도한 바)

실시간성은 시간 제약사항이 강한 상황을 의미한다. 운영체제 설계 관점에서는, 반응 시간이 시간 제약사항을 지킬 수 있도록 스케쥴링 되게 구현해야 한다.

### 추가 답변

앞의 답변도 틀린 것은 아니나, 너무 실시간 시스템의 정의에 집중하고 있으며, 구현을 위해 필요한 실질적인 어려움에 대한 설명이 부족하다.
반응 시간이 시간 제약사항을 지키는 상황을 좀 더 구체적으로 보면 다음과 같다.
1. 특정 작업이 지정된 timeout 이후에 즉시 실행될 수 있게 수정되어야 한다.  
   범용 운영체제의 경우 [usleep()](https://man7.org/linux/man-pages/man3/usleep.3.html) 등의 함수를 호출하면 주어진 시간만큼 동작하지 않는 것은 보장하지만, 그 이후 무조건 깨어나는 것을 보장하지는 않는다.  
   하지만 실시간성의 특징을 고려하면 최대한 빨리 깨어날 수 있다는 것을 보장해야 한다. (soft냐 hard냐에 따라 최대한/즉시 여부가 다를 수도 있다.)  
   (범용 운영체제의 경우, timeout 이후로 스케쥴링 하다가 생기는 context switch의 오버헤드를 줄이기 위해, timeout 이후 스케쥴링 될 수 있게 구현하는 편이다.)  
   (범용 운영체제에서도 극단적인 환경이 아니라면 timeout이후 실행되는 수준처럼 보이지만, 보통 실시간 환경의 시간 제약 단위는 범용 대비 극도로 짧아서 쉽게 못 느끼게 된다.)
2. 실시간 운영체제는 시간 제약사항을 지키지 못하면, 일부 프로세스를 실패시킬 수도 있다.  
   범용 운영체제의 경우, 자원을 최대한 효율적으로 사용하여 프로세스들을 수행하고, 각 프로세스들이 정확하게 실행될 수 있게 설계한다.  
   (여기서 정확성은 여러 프로세스간 동기화 문제를 해결한 부분을 의미한다.)  
   하지만 실시간 운영체제는 중요한, 더 급한 프로세스의 동작을 위해 다른 프로세스의 동작을 실패 시킬 수도 있다.  
   (예를 들어 덜 중요한 프로세스가 mutex를 점유했더라도, 중요한 프로세스가 mutex 점유 상태를 뺏어 동작하고, 덜 중요한 프로세스가 실패할 수도 있다.)

## 1.4 Keeping in mind the various definitions of operating system, consider whether the operating system should include applications such as web browsers and mail programs. Argue both that it should and that is should not and support your answers.

### 일반 답변 요약 (책 답안, 의도한 바)

* 포함하는 경우
  * 운영체제와 해당 어플리케이션 간의 연결 최적화가 가능해짐
  * 개별 응용 프로그램 구현이 불필요해져 사용에 편리함
* 배제하는 경우
  * 운영체제의 역할은 최소한의 공통 기능만 제공하는 것, 크기가 불필요하게 커짐

### 추가 답변

이 질문은 쉘과 커널을 엄밀하게 분리하지 않은 관점을 바탕으로 한다.  
(커널만을 운영체제로 보는 관점에서는 이미 쉘이 질문의 응용 프로그램 역할이라 볼 수 있다.)  
응용 프로그램들을 운영체제에 포함시키던 대표적인 예시로 Microsoft의 Windows가 있었으며, [IE를 끼워팔아서 독점 소송이 있었다.](https://en.wikipedia.org/wiki/United_States_v._Microsoft_Corp.)  
해당 사건에 따르면, Windows에 IE를 무조건 포함시킨 것 뿐만 아니라, 운영체제에서도 IE에 유리한 API 등을 제공했다고 한다.  
하지만 이 API가 system call 수준으로, 응용 프로그램의 역할을 커널단에서 제공한 것인지는 잘 모르겠다.

## 1.5 How does the distinction between kernel mode and user mode function as a rudimentary form of protection?

### 일반 답변 (책 답안, 의도한 바)

하드웨어 장치 접근, 인터럽트 활성화/비활성화 등의 기능은 CPU가 커널 모드로 동작할 때만 가능하게 한다.  
유저 모드일 때는 위와 같은 동작을 할 수 없고, 제한적인 동작만 가능하기 때문에 중요한 자원 접근에 대한 보호가 가능하다.

이를 통해 다른 프로세스의 메모리 영역에 대한 접근을 막는 등의 보호를 제공하게 된다.

### 추가 답변

하드웨어 장치 접근이나, 메모리 영역 보호 등은 보호 기능을 제공하지만, 목적 보다는 부가적인 결과라 생각한다.

운영체제가 여러 프로세스에게 일관되게 자원을 관리해서 제공하려 하다 보니, 직접적인 하드웨어 접근을 막을수 있었다.  
컴퓨터 시스템 구성 간 이식성을 용이하게 하기 위해 프로세스마다 가상 주소공간을 제공하다 보니, 프로세스 간 메모리 영역 접근을 막을수 있었다.

위와 같은 사항은 부수적인 효과라 생각하며, 보안 자체를 목적으로 하는 기능은 개별적인 개념이라 생각한다.  
운영체제의 보안 관점에서, 커널이 거의 모든 기능을 제공하므로, 유저 프로세스가 당장 필요로 하지 않는 커널 주소공간에 접근하게 되는 것을 막아야 한다.  
이런 커널의 주소 공간을 접근하는 대표적인 공격으로 [멜트다운](https://ko.wikipedia.org/wiki/%EB%A9%9C%ED%8A%B8%EB%8B%A4%EC%9A%B4_(%EB%B2%84%EA%B7%B8)), [스펙터](https://ko.wikipedia.org/wiki/%EC%8A%A4%ED%8E%99%ED%84%B0_(%EB%B2%84%EA%B7%B8)) 공격이 있다.  
리눅스 커널의 경우, 위 공격을 막기 위해 아래와 같은 기법을 사용한다.
* [KASLR](https://lwn.net/Articles/569635/): 커널 주소 공간의 위치를 무작위로 설정하게 해서 메모리 주소 공간에 대한 공격을 어렵게 한다.
* [KPTI](https://en.wikipedia.org/wiki/Kernel_page-table_isolation): 유저 모드일 때는 커널에서 지금 당장 필요한 페이지만 접근할 수 있게 하고, 나머지 커널 주소 공간을 격리한다.

## 1.6 Which of the following instructions should be privileged?
a. set value of timer.  
b. Read the clock.  
c. Clear memory.  
d. Issue a trap instruction.  
e. Turn off interrupts.  
f. Modify entries in device-status table.  
g. Switch from user to kernel mode.  
h. Access I/O device.  

## 1.7 Some early computers protected the operating system by placing it in a memory partition that could not be modified by either the user job or the operating system itself. Describe two difficulties that you think could arise with such a scheme.

## 1.8 Some CPUs provide for more than two modes of operation. What are two possible uses of these multiple modes?

## 1.9 Timers could be used to compute the current time. Provide a short description of how this could be accomplished.


## 1.10 Give two reasons why caches are useful. What problems do they solve? What problems do the cause? If a cache can be made as large as the device for which it is caching (for instance, a cache as large as a disk), why not make it that large and eliminate the device?

## 1.11 Distinguish between the client-server and peer-to-peer models of distributed systems


