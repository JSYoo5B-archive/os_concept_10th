## 2.1

### What is the purpose of system calls?

- 커널 모드에 대한 직접적인 접근이 불가능하므로 API를 통해 커널의 코드(커널 접근)를 실행하게 해주는 것을 system call이라고 한다

## 2.2

### What is the purpose of the command interpreter? Why is it usually separate from the kernel?

- command interpreter는 입력되는 명령어를 읽고 실행하는 프로그램이다
    - command를 interpreter 해주는 것들을 shell이라 한다
- 커널로부터 separate 한 이유는 한 OS에 제한되지 않고 여러 OS에 범용적으로 사용하기 위해서이다

## 2.3

### What system calls have to be executed by a command interpreter or shell in order to start a new process on a UNIX system?

- fork()로 새로운 프로세스를 시작하고, exec() 시스템 콜을 통해 메모리에 적재된다

## 2.4

### What is the purpose of system programs?

- 운영체제에 대해 문제가 생겼을 때, 사용자의 편의를 위하여 사용자가 직접 해결하지 않고 시스템 프로그램을 이용하여 해결할 수 있게 해준다

## 2.5

### What is the main advantage of the layered approach to system design? What are the disadvantages of the layered approach?

- 장점
    - 층 마다 기능이 분리되어 있어서 구현과 디버깅이 쉽다
    - 특정 기능에 대해 오류가 생기면 해당 기능이 구현된 층만 문제 해결을 하면 된다
- 단점
    - 특정 기능을 수행하기 위해 여러 계층을 통과해야하는 오버헤드가 발생

## 2.6

### List five services provided by an operating system, and explain how each creates convenience for users. In which cases would it be impossible for user-level programs to provide these services? Explain your answer.

- program execution, I/O operation, file system manipulation, communication, error detection
- 2.1 Operating-System Services

## 2.7

### Why do some systems store the operating system in firmware, while others store it on disk?

## 2.8

### How could a system be designed to allow a choice of operating systems from which to boot? What would the bootstrap program need to do?

- bootstrap program이라고 하는 코드가 커널의 위치를 찾기 때문에 해당 bootstrap program이 어느 운영 체제를 선택할 지 미리 설계하도록 한다