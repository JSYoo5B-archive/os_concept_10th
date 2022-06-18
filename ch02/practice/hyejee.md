**2.1 What is the purpose of system calls?**    
* 시스템콜의 목적은 운영체제의 기능을 사용할 수 있도록 인터페이스를 제공하는 것이다.  

**2.2 What is the purpose of the command interpreter? Why is it usually separate from the kernel?**  
* command interpreter의 목적은 유저가 원하는 명령을 받고 실행하기 위함이다.  
* command interpreter는 여러 개가 존재할 수 있고, 사용자가 그 중 하나를 선택해서 사용하게 된다. 이처럼 command interpreter는 변경 가능하기 때문에 커널과 분리되어 있어야 한다.  

**2.3 What system calls have to be executed by a command interpreter or shell in order to start a new process on a UNIX system?**  
* UNIX에서 새로운 프로세스를 시작하기 위해서는 `fork()`와 `exec()`을 호출해야한다. 

**2.4 What is the purpose of system programs?**  
* 사용자를 위한 유틸리티들을 제공하기 위해서 시스템 프로그램이 존재한다.

**2.5 What is the main advantage of the layered approach to system design? What are the disadvantages of the layered approach?**  
* 장점
	* layered 방식으로 설계된 운영체제는 여러 기능들이 모듈로 나눠져 있다. 따라서 디버깅이 용이하고, 어떤 component를 수정하는 것은 오직 그 component에게만 영향을 미친다.
* 단점
	* 서로 다른 레이어의 기능들을 실행하기 위해 레이어 사이를 왔다갔다 하는데 필요한 오버헤드가 layered 방식의 단점이다.  

**2.6 List five services provided by an operating system, and explain how each creates convenience for users. In which cases would it be impossible for user-level programs to provide these services? Explain your answer.**  

**2.7 Why do some systems store the operating system in firmware, while others store it on disk?**  

**2.8 How could a system be designed to allow a choice of operating systems from which to boot? What would the bootstrap program need to do?**  
