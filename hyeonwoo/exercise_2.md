## 2.9

### The services and functions provided by an operating system can be divided into two main categories. Briefly describe the two categories, and discuss how they differ.

- service는 프로그래밍 작업을 더 쉽게 수행할 수 있도록 도와주고, function은 시스템 자체의 효율적인 동작을 보장하기 위한 것이다
- 자원 할당, logging, protection, security는 멀티 프로세스 시스템에서 프로세스 간에 컴퓨터 자원을 어떻게 할당해야 효율적인지, 어떤 자원을 사용했는지의 기록, 외부로부터 시스템을 보호하기 위해 위와 같은 기능들을 제공한다

## 2.10

### Describe three general methods for passing parameters to the operating system

- 2.6 ABI 설명 부분

## 2.11

### Describe how you could obtain a statistical profile of the amount of time a program spends executing different sections of its code. Discuss the importance of obtaining such a statistical profile

## 2.12

### What are the advantages and disadvantages of using the same system call interface for manipulating both files and devices?

## 2.13

### Would it be possible for the user to develop a new command interpreter using the system-call interface provided by the operating system?

- 사용자는 인터프리터를 이용하여 시스템 콜을 하여 커널 코드를 실행할 수 있기 때문에, 특정 시스템 콜을 호출하는 api를 작성하여 새로운 인터프리터를 만들 수 있다고 생각한다

## 2.14

### Describe why Android uses ahead-of-time (AOT) rather than just-in-time (JIT) compilation

## 2.15

### What are the two models of interprocess communication? What are the
strengths and weaknesses of the two approaches?

- 공유 메모리와 메세지 전송 방식이 있다
- 메시지 전송 방식의 장점은 피해야 할 충돌이 없기 때문에 소량의 데이터를 교환할 때 유용하고 구현이 쉽지만 속도가 공유 메모리보다 느리다

질문 : 공유 메모리에서는 프로세스가 다른 프로세스에 접근하기 위해서는 별도의 조치가 필요한데 이를 피해야 할 충돌이라 표현한 것일까??(2.3.3.5)

- 공유 메모리 방식의 장점은 속도가 빠르고 편리하지만 프로세스 간의 보호 및  동기화 부분에서 여러 문제점을 가지고 있다

## 2.16

### Contrast and compare an application programming interface (API) and an application binary interface (ABI).

## 2.17

### Why is the separation of mechanism and policy desirable?

- mechanism은 어떤 일을 “어떻게"할 것인가를 결정
- policy는 “무엇을" 할 것인가를 결정하는 것이다

## 2.18

### It is sometimes difficult to achieve a layered approach if two components of the operating system are dependent on each other. Identify a scenario in which it is unclear how to layer two system components that require tight coupling of their functionalities.

## 2.19

### What is the main advantage of the microkernel approach to system design? How do user programs and system services interact in a microkernel architecture? What are the disadvantages of using the microkernel approach?

## 2.20

### What are the advantages of using loadable kernel modules?

## 2.21

### How are iOS and Android similar? How are they different?

## 2.22

### Explain why Java programs running on Android systems do not use the standard Java API and virtual machine.

## 2.23

### The experimental Synthesis operating system has an assembler incorporated in the kernel. To optimize system-call performance, the kernel assembles routines within kernel space to minimize the path that the system call must take through the kernel. This approach is the antithesis of the layered approach, in which the path through the kernel is extended to make building the operating system easier. Discuss the pros and cons of the Synthesis approach to kernel design and system-performance optimization.

## 2.24

### In Section 2.3, we described a program that copies the contents of one file to a destination file. This program works by first prompting the user for the name of the source and destination files. Write this program using either the POSIX or Windows API. Be sure to include all necessary error checking, including ensuring that the source file exists. Once you have correctly designed and tested the program, if you used a system that supports it, run the program using a utility that traces system calls. Linux systems provide the strace utility, and macOS systems use the dtruss command. (The dtruss command, which actually is a front end to dtrace, requires admin privileges, so it must be run using sudo.) These tools can be used as follows (assume that the name of the executable file is FileCopy:

Linux:
strace ./FileCopy
macOS:
sudo dtruss ./FileCopy
Since Windows systems do not provide such a tool, you will have to
trace through the Windows version of this program using a debugger.