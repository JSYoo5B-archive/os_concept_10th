# 1.1 What are the three main purposes of an operation system?

- 응용 프로그램 간의 하드웨어 사용을 제어하고 조정한다
- 자원 할당자로서 자원을 적절하게 사용할 수 있는 방법을 제공한다
- 다른 프로그램이 유용한 작업을 할 수 있는 환경을 제공한다

# 1.2 We have stressed the need for an operating system to make efficient use of the computing hardware. When is it appropriate for the operating system to forsake this principle and to "waste" resources? Why is such a system not really wasteful?

- 모니터, 키보드, 마우스로 구성된 PC에서 작업하는 사용자는 자원을 독점하도록 설계됐다. 이때는 자원을 얼마나 효율적으로 잘 사용하기보다는 사용자가 수행하는 작업을 최대화하기 위해 운영체제는 사용의 용이성을 위해 설계됐다

# 1.3 What is the main difficulty that a programmer must overcome in writing an operating system for a real-time environment?

- 비동기 처리가 원활하게 처리해야한다. 실시간 채팅 서비스의 경우 비동기 처리가 원활하지 않는다면 사용자가 대화를 보내고 새로고침을 통하여 새로운 리소스를 받아야 보낸 대화 내용을 볼 수 있다. 따라서 real-time 환경을 제공하기 위해서는 비동기 처리가 중요하다고 생각한다

# 1.4 Keeping in mind the various definitions of operating system, consider whether the operating system should include applications such as web browsers and mail programs. Argue both that it should and that is should not and support your answers.

- 포함시키지 않는다
   - 만약 운영체제에 응용 프로그램이 포함된다면 운영체제마다 애플리케이션이 하드웨어 사용을 제어하고 조정하는 기능들이 각각 모두 구현되어야한다
- 포함시킨다
   - 운영체제에 애플리케이션을 포함시킨다면 분리했을 때보다 액세스하는 시간이 더 짧아질 것이다 그리고 각 애플리케이션마다 운영체제에 특화되어있으므로 퍼포먼스 향상에서의 이점이 있을 것 같다

# 1.5 How does the distinction between kernel mode and user mode function as a rudimentary form of protection?

- 운영체제와 사용자는 하드웨어, 소프트웨어 자원을 공유하기 때문에 잘못된 프로그램으로 인해 다른 프로그램이나 운영체제 자체가 잘못 실행될 수 없도록 보장해야 한다. 그러기 위해서는 운영체제 코드 실행과 사용자 코드 실행을 구분할 수 있어야한다. 따라서 사용자 모드와 커널 모드로 구분하여 특권 명령, 하드웨어 장치 접근은 커널 모드에서 실행할 수 있다. 즉, 사용자 모드에서는 실행할 수 있는 기능을 매우 제한하여 리소스들을 보호한다

# 1.6 Which of the following instructions should be privileged?
a. set value of timer.  
b. Read the clock.  
c. Clear memory.  
d. Issue a trap instruction.  
e. Turn off interrupts.  
f. Modify entries in device-status table.  
g. Switch from user to kernel mode.  
h. Access I/O device.  

- a, c, d, e, f, g, h
