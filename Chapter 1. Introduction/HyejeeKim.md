# Chapter 1. Introduction

## Exercises
---

**1.12 How do clustered systems differ from multiprocessor systems? What is required for two machines belonging to a cluster to cooperate to provide a highly available service?**

* clustered 시스템은 두 개 이상의 독립적인 시스템을 모아 하나의 시스템으로 사용함으로써 CPU가 여러 개인 것과 같은 형상을 한다는 점에서 multiprocessor 시스템과 다르다. 
* 두 개의 기기로 이루어진 clustered 시스템이 highly available service를 제공하기 위해서는 두 기기가 네트워크를 통해 연결이 되어 있어야한다. 그래야 한 기기가 다른 기기가 fail 된 것을 확인하고, fail 된 기기가 하던 작업을 자신이 가지고 와 지속할 수 있다.

--- 

**1.13 Consider a computing cluster consisting of two nodes running a database. Describe two ways in which the cluster software can manage access to the data on the disk. Discuss the benefits and disadvantages of each.**

* symmetric clustering과 asymmetric clustering 두 가지 형태로 clustered 시스템을 구축할 수 있다. 
* asymmetric clusterting 형태로 구축하는 경우, 하나의 노드는 hot-stand-by 모드를 유지하게 되므로 오직 하나의 노드만 디스크에 접근하게 된다. 따라서 디스크 접근에 대한 별도의 management가 필요하지 않다.

---

**1.14 What is the purpose of interrupts? How does an interrupt differ from a trap? Can traps be generated intentionally by a user program? If so, for what purpose?**

* 인터럽트의 목적은 운영체제와 하드웨어가 상호작용할 수 있는 수단을 제공하는 것이다.
* 인터럽트와 트랩의 주요한 차이점은 발생 주체이다. 인터럽트는 하드웨어 장치에서 발생되지만 트랩은 유저 프로세스에서 발생된다. 또한, 인터럽트는 asynchronous 하지만 트랩은 synchronous하다.
* 트랩은 유저 프로그램에서 고의적으로 생성될 수 있으며, 이와 같은 일을 하는 이유는 커널 모드에서만 사용할 수 있는 기능을 사용하기 위해서다. 



--- 

**1.15 Explain how the Linux kernel variables HZ and jiffies can be used to determine the number of seconds the system has been running since it was booted.**

---

**1.16 Direct memory access is used for high-speed I/O devices in order to avoid increasing the CPU’s execution load.**

**a. How does the CPU interface with the device to coordinate the transfer?**

**b. How does the CPU know when the memory operations are complete?**

**c. The CPU is allowed to execute other programs while the DMA controller is transferring data. Does this process interfere with the execution of the user programs? If so, describe what forms of interference are caused.**

---

**1.17 Some computer systems do not provide a privileged mode of operation in hardware. Is it possible to construct a secure operating system for these computer systems? Give arguments both that it is and that it is not possible.**

* 

---

1.18 Many SMP systems have different levels of caches; one level is local to each processing core, and another level is shared among all processing cores. Why are caching systems designed this way?

--- 

**1.19 Rank the following storage systems from slowest to fastest:**
**a. Hard-disk drives**
**b. Registers**
**c. Optical disk**
**d. Main memory**
**e. Nonvolatile memory**
**f. Magnetic tapes**
**g. Cache**

*

1.20 Consider an SMP system similar to the one shown in Figure 1.8. Illustrate with an example how data residing in memory could in fact have a different value in each of the local caches.

1.21 Discuss, with examples, how the problem of maintaining coherence of cached data manifests itself in the following processing environments:
a. Single-processor systems
b. Multiprocessor systems
c. Distributed systems

1.22 Describe a mechanism for enforcing memory protection in order to prevent a program from modifying the memory associated with other programs.
1.23 Which network configuration — LAN or WAN — would best suit the fol- lowing environments?
a. A campus student union
b. Several campus locations across a statewide university system
c. A neighborhood

1.24 Describe some of the challenges of designing operating systems for mobile devices compared with designing operating systems for tradi- tional PCs.

1.25 What are some advantages of peer-to-peer systems over client – server systems?

1.26 Describe some distributed applications that would be appropriate for a peer-to-peer system.

1.27 Identify several advantages and several disadvantages of open-source operating systems. Identify the types of people who would find each aspect to be an advantage or a disadvantage.