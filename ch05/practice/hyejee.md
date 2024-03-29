**5.1 A CPU-scheduling algorithm determines an order for the execution of its scheduled processes. Given n processes to be scheduled on one processor, how many different schedules are possible? Give a formula in terms of n.**  

* n!  

**5.2 Explain the difference between preemptive and nonpreemptive scheduling.**  

* nonpreemptive 스케줄링의 경우, 실행 중이던 프로세스가 종료(terminate)되거나 자발적으로 I/O 등으로 인해 running state에서 waiting state로 넘어간 경우에만 스케줄링이 일어나는 것이다. preemptive 스케줄링은 nonpreemtive 스케줄링이 일어나는 상황이 아닌 모든 상황에서 스케줄링이 일어나는 것을 말한다. 여러 프로세스에서 동일한 데이터를 공유하는 상황이었다면 preemptive 스케줄링의 경우 race condition이 발생할 수 있다.  

**5.3 Suppose that the following processes arrive for execution at the times indicated. Each process will run for the amount of time listed. In answering the questions, use nonpreemptive scheduling, and base all decisions on the information you have at the time the decision must be made.**  

|Process|Arrival Time|Burst Time|
 |:---:|:---:|:---:|
 |P1|0.0|8|
 |P2|0.4|4|
 |P3|1.0|1|
  
**a. What is the average turnaround time for these processes with the FCFS scheduling algorithm?**  
**b. What is the average turnaround time for these processes with the SJF scheduling algorithm?**  
**c. The SJF algorithm is supposed to improve performance, but notice that we chose to run process P1 at time 0 because we did not know that two shorter processes would arrive soon. Compute what the average turnaround time will be if the CPU is left idle for the first 1 unit and then SJF scheduling is used. Remember that processes P1 and P2 are waiting during this idle time, so their waiting time may increase. This algorithm could be known as future-knowledge scheduling.**  

* a) (8 + (12 - 0.4) + (13 - 1)) / 3 = 10.53  
* b) (8 + (9 - 1) + (13 – 0.4)) / 3 = 9.53  

**5.4 Consider the following set of processes, with the length of the CPU burst time given in milliseconds:**  
**The processes are assumed to have arrived in the order P1, P2, P3, P4, P5, all at time 0.**  
**a. Draw four Gantt charts that illustrate the execution of these pro- cesses using the following scheduling algorithms: FCFS, SJF, non-preemptive priority (a larger priority number implies a higher priority), and RR (quantum = 2).**  

|Process|Burst Time|Priority|
 |:---:|:---:|:---:|
 |P1|2|2|
 |P2|1|1|
 |P3|8|4|
 |P4|4|2|
 |P5|5|3|

**b. What is the turnaround time of each process for each of the scheduling algorithms in part a?**  
**c. What is the waiting time of each process for each of these scheduling algorithms?**  
**d. Which of the algorithms results in the minimum average waiting time (over all processes)?**  

**5.5 The following processes are being scheduled using a preemptive, roundrobin scheduling algorithm.**  
**Each process is assigned a numerical priority, with a higher number indicating a higher relative priority. In addition to the processes listed below, the system also has an idle task (which consumes no CPU resources and is identified as Pidle). This task has priority 0 and is scheduled whenever the system has no other available processes to run. The length of a time quantum is 10 units. If a process is preempted by a higher-priority process, the preempted process is placed at the end of the queue.**  
**a. Show the scheduling order of the processes using a Gantt chart.**  
**b. What is the turnaround time for each process?**  
**c. What is the waiting time for each process?**  
**d. What is the CPU utilization rate?**  

**5.6 What advantage is there in having different time-quantum sizes at different levels of a multilevel queueing system?**  

* 빠르게 응답을 해줘야하거나 I/O bound인 작업들은 time quantum이 작은 큐에 배치하고, CPU bound 작업들은 time quantum이 긴 곳에 배치하여 궁극적으로는 CPU를 더 효율적으로 사용할 수 있게 된다.

**5.7 Many CPU-scheduling algorithms are parameterized. For example, the RR algorithm requires a parameter to indicate the time slice. Multilevel feedback queues require parameters to define the number of queues, the scheduling algorithms for each queue, the criteria used to move processes between queues, and so on.**  
**These algorithms are thus really sets of algorithms (for example, the set of RR algorithms for all time slices, and so on). One set of algorithms may include another (for example, the FCFS algorithm is the RR algorithm with an infinite time quantum). What (if any) relation holds between the following pairs of algorithm sets?**  
**a. Priority and SJF**  
**b. Multilevel feedback queues and FCFS**  
**c. Priority and FCFS**  
**d. RR and SJF**  

* a) priority와 SJF는 반비례 관계다.  
* b) MLFQ의 최하위 레벨의 큐는 FCFS를 채택한다.    
* c) FCFS에서는 CPU를 가장 오랫동안 받지 못한 job에게 가장 높은 priority를 준다.  
* d) 뭐가 있나...? 둘 다 CPU 스케줄링 알고리즘이다... 정도?  

**5.8 Suppose that a CPU scheduling algorithm favors those processes that have used the least processor time in the recent past. Why will this algorithm favor I/O-bound programs and yet not permanently starve CPU-bound programs?**  

* I/O-bound 프로그램들은 CPU를 사용하는 시간이 상대적으로 짧기 때문에 해당 알고리즘이 더 선호할 수밖에 없다. 하지만 CPU-bound 프로그램들이 기아 상태에 빠지지 않는 이유는 I/O-bound 프로그램들은 I/O를 기다리느라 wait state로 가는 등 CPU를 더 이상 사용하지 않기 때문이다.    

**5.9 Distinguish between PCS and SCS scheduling.**  

**5.10 The traditional UNIX scheduler enforces an inverse relationship between priority numbers and priorities: the higher the number, the lower the priority. The scheduler recalculates process priorities once per second using the following function:**  
```
Priority = (recent CPU usage / 2) + base
```
**where base = 60 and recent CPU usage refers to a value indicating how often a process has used the CPU since priorities were last recalculated. Assume that recent CPU usage for process P1 is 40, for process P2 is 18, and for process P3 is 10. What will be the new priorities for these three processes when priorities are recalculated? Based on this information, does the traditional UNIX scheduler raise or lower the relative priority of a CPU-bound process?**  