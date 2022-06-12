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

## 1.4 Keeping in mind the various definitions of operating system, consider whether the operating system should include applications such as web browsers and mail programs. Argue both that it should and that is should not and support your answers.

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


