**2.9 The services and functions provided by an operating system can be divided into two main categories. Briefly describe the two categories, and discuss how they differ.**  
1. 사용자의 편의를 위한 기능  
	* program execution, user interface, I/O operations, file-system manipulation, IPC, error detection 등이 있다.  
2. 운영체제 자체의 효율적인 작업을 위한 기능
	* resource allocation, logging, protection and security 등이 있다.  
	
**2.10 Describe three general methods for passing parameters to the operating system.**  
* 운영체제에게 파라미터를 넘기는 일반적인 방식에는 크게 세 가지가 존재한다.
	1. 레지스터 방식  
		* 레지스터에 바로 파라미터 값을 저장하는 방식이다.  
		* 파라미터 개수가 가용 가능한 레지스터 개수보다 많은 경우 이 방식은 사용할 수 없다.  
	2. 블록 방식  
		* 메모리에 블록 또는 테이블을 잡고, 해당 영역에 파라미터들을 저장한 후 메모리 주소를 레지스터에 저장하는 방식이다.  
		* 레지스터 방식처럼 파라미터 개수를 제한하지 않는다.
	3. 스택 방식  
		* 파라미터들을 스택에 집어넣고 운영체제가 pop하여 사용하는 방식이다.
		* 레지스터 방식처럼 파라미터 개수를 제한하지 않는다.

**2.11 Describe how you could obtain a statistical profile of the amount of time a program spends executing different sections of its code. Discuss the importance of obtaining such a statistical profile.**  

**2.12 What are the advantages and disadvantages of using the same system- call interface for manipulating both files and devices?**  
* 장점  
	* 모든 디바이스에 파일시스템에 존재하는 파일과 동일하게 접근할 수 있다. 따라서 프로그램들은 파일에 액세스하는 코드를 디바이스 액세스에 사용할 수 있어 코드의 재사용성을 높일 수 있다.
* 단점  
	* 인터페이스는 general한 operation들에 대한 기능만 제공하게 되므로, 특정 디바이스의 기능을 사용할 수 없을 수 있다.  
	
**2.13 Would it be possible for the user to develop a new command interpreter using the system-call interface provided by the operating system?**  

**2.14 Describe why Android uses ahead-of-time (AOT) rather than just-in-time (JIT) compilation.**  

**2.15 What are the two models of interprocess communication? What are the strengths and weaknesses of the two approaches?**  
1. message-passing 모델  
	* communication하는 프로세스들이 메세지를 주고 받아 정보를 교환하는 방식이다.  
	* 정보를 교환하는데 있어 conflict가 발생하지 않아 작은 크기의 데이터를 주고 받는 것에 용이하나, 사이즈가 큰 데이터를 주고 받기 어렵다.  
2. shared-memory 모델  
	* communication하는 프로세스들 사이에 공유하는 메모리 영역을 잡고, 해당 메모리 영역에 데이터를 쓰고 읽어 정보를 교환하는 방식이다.
	* synchronization, protection과 같은 이슈를 고려하며 구현해야 하기 때문에 구현이 더 복잡하지만 별도의 시스템 콜을 호출할 필요 없이 메모리에 데이터를 쓰고, 읽으면 되므로 빠르다.  

**2.16 Contrast and compare an application programming interface (API) and an application binary interface (ABI).**  
* API와 ABI는 인터페이스를 제공한다는 것에 있어 유사성을 갖는다. 다만 API는 소스코드 레벨에서의 인터페이스를 제공하고, ABI는 두 개의 바이너리 모듈 사이의 인터페이스를 제공하는 것에서 차이점을 갖는다.  

**2.17 Why is the separation of mechanism and policy desirable?**  

**2.18 It is sometimes difficult to achieve a layered approach if two components of the operating system are dependent on each other. Identify a scenario in which it is unclear how to layer two system components that require tight coupling of their functionalities.**  

**2.19 What is the main advantage of the microkernel approach to system design? How do user programs and system services interact in a micro- kernel architecture? What are the disadvantages of using the microker- nel approach?**  

**2.20 What are the advantages of using loadable kernel modules?**  

**2.21 How are iOS and Android similar? How are they different?**  

**2.22 Explain why Java programs running on Android systems do not use the standard Java API and virtual machine.**  

**2.23 The experimental Synthesis operating system has an assembler incor- porated in the kernel. To optimize system-call performance, the kernel assembles routines within kernel space to minimize the path that the sys- tem call must take through the kernel. This approach is the antithesis of the layered approach, in which the path through the kernel is extended to make building the operating system easier. Discuss the pros and cons of the Synthesis approach to kernel design and system-performance optimization.**  

**2.24 In Section 2.3, we described a program that copies the contents of one file to a destination file. This program works by first prompting the user for the name of the source and destination files. Write this program using either the POSIX or Windows API. Be sure to include all necessary error checking, including ensuring that the source file exists.   
Once you have correctly designed and tested the program, if you used a system that supports it, run the program using a utility that traces sys- tem calls. Linux systems provide the strace utility, and macOS systems use the dtruss command. (The dtruss command, which actually is a front end to dtrace, requires admin privileges, so it must be run using sudo.) These tools can be used as follows (assume that the name of the executable file is FileCopy:**  
Linux: `strace ./FileCopy`   
macOS: `sudo dtruss ./FileCopy`   
**Since Windows systems do not provide such a tool, you will have to trace through the Windows version of this program using a debugger.**  
