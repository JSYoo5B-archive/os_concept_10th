## 5.1 A CPU-scheduling algorithm determines an order for the execution of its scheduled processes. Given *n* processes to be scheduled on one processor, how many different schedules are possible? Give a formula in terms of *n.*

무슨 말인지 모르겠다,, n개의 프로세스를 스케줄링 할 수 있는 경우의 수를 n개로 나타내는 것이면 (n!) ?

## 5.2  Explain the difference between preemptive and nonpreemptive scheduling.

비선점은 진행하고 있는 프로세스의 작업이 완료될 때까지 CPU를 강제로 뺏지 않고,
선점은 진행하고 있는 프로세스에게서 CPU를 강제로 뺏는다.

## 5.3 Suppose that the following processes arrive for execution at the times inducated. Each process will run for the amount of time listed. In answering the questions, use nonpreemptive scheduling, and base all decisions on the information you have at the time the decision must be made.

1. What is the average turnaround time for these processes with the FCFS scheduling algorithm?
2. What is the average turnaround time for these processes with the SJF scheduling algorithm?
3. The SJF algorithm is supposed to improve performance, but notice that we chose to run process P1 at time 0 because we did not know that two shorter processes would arrive soon. Compute what the average turnaround time will be if the CPU is left idle for the first 1 unit and then SJF scheduling is used. Remember that processes P1 and P2 are waiting during this idle time, so their waiting time may increase. This algorithm could be known as future-knowledge scheduling.

5.4 Consider the following set of processes, with the length of the CPU burst time given in milliseconds:

The processes are assumed to have arrived in the order *P*1, *P*2, *P*3, *P*4, *P*5, all at time 0.

a. Draw four Gantt charts that illustrate the execution of these processes using the following scheduling algorithms: FCFS, SJF, nonpreemptive priority (a larger priority number implies a higher priority), and RR (quantum = 2).

b. What is the turnaround time of each process for each of the scheduling algorithms in part a?

c. What is the waiting time of each process for each of these scheduling algorithms?

d. Which of the algorithms results in the minimum average waiting time (over all processes)?

## 5. 5 The following processes are being scheduled using a preemptive, round-robin scheduling algorithm.

Each process is assigned a numerical priority, with a higher number indicating a higher relative priority. In addition to the processes listed below, the system also has an **idle task** (which consumes no CPU resources and is identified as *Pidle*). This task has priority 0 and is scheduled whenever the system has no other available processes to run. The length of a time quantum is 10 units. If a process is preempted by a higher-priority process, the preempted process is placed at the end of the queue.

1. Show the scheduling order of the processes using a Gantt chart.
2. What is the turnaround time for each process?
3. What is the waiting time for each process?
4. What is the CPU utilization rate?

## 5.6  ****What advantage is there in having different time quantum sizes at different levels of a multilevel queueing system?

- I/O 작업과 같은 interactive한 job들을 빨리 처리함으로써 client의 응답 시간을 줄일 수 있다

## 5. 7 Many CPU-scheduling algorithms are parameterized. For example, the RR algorithm requires a parameter to indicate the time slice. Multilevel feedback queues require parameters to define the number of queues, the scheduling algorithms for each queue, the criteria used to move processes between queues, and so on. These algorithms are thus really sets of algorithms (for example, the set of RR algorithms for all time slices, and so on). One set of algorithms may include another (for example, the FCFS algorithm is the RR algorithm with an infinite time quantum). What (if any) relation holds between the following pairs of algorithm sets?

### Priority and SJF

- Priority 알고리즘에서 CPU를 사용하는 시간이 가장 짧은 것을 기준으로 하면 SJF가 된다

### Multilevel feedback queues and FCFS

- 멀티레벨 피드백 큐의 마지막 큐는 FCFS를 사용한다

### Priority and FCFS

- Priority에서 요청 시간이 빠른 것을 기준으로 하면 FCFS가 된다

### RR and SJF

- 모르겠다

## 5.8  ****Suppose that a CPU scheduling algorithm favors those processes that have used the least processor time in the recent past. Why will this algorithm favor I/O-bound programs and yet not permanently starve CPU-bound programs?

- 프로세서 시간이 가장 적은 프로세스를 우선한다는 것은 결국 CPU burst time이 작은 I/O bound process를 선호한다는 뜻이다.
- 그런데 왜 CPU bound program이 starvation을 겪지 않을까?
- 그것은 I/O 작업을 하게 되면 CPU를 반환하고 가기 때문에, I/O 작업이 활발하면 CPU를 자주 반환하기 때문에 CPU bound programs들이 starvation을 겪지 않게 된다

## 5.9  ****Distinguish between PCS and SCS scheduling.

PCS

- OS 입장에서는 프로세스에게 CPU를 할당하고, 프로세스 내부에서는 어떤 스레드에게 CPU를 할당할지 결정

SCS

- OS가 스레드의 존재를 알기 때문에 OS 자체가 프로세스 스케줄링하듯 어떤 스레드에게 CPU를 할당할지 결정

## 5.10  ****The traditional UNIX scheduler enforces an inverse relationship between priority numbers and priorities: the higher the number, the lower the priority. The scheduler recalculates process priorities once per second using the following function:

Priority = (recent CPU usage / 2) + base

where base = 60 and *recent CPU usage* refers to a value indicating how often a process has used the CPU since priorities were last recalculated.
 Assume that recent CPU usage for process *P*1 is 40, for process *P*2 is 18, and for process *P*3 is 10. What will be the new priorities for these three processes when priorities are recalculated? Based on this information, does the traditional UNIX scheduler raise or lower the relative priority of a CPU-bound process?

