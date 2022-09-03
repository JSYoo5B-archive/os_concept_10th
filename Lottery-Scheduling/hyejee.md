# Lottery Scheduling의 의미  

## Lottery Scheduling이란?  
* lottery scheduling은 fair share scheduling 중 하나이다.  
* fair share scheduling은 turnaround time을 최적화하는 대신에 모든 프로세스들이 적정한 수준의 CPU time을 가질 수 있도록 보장하는 스케줄링이다.  
* lottery scheduling은 그 중에서도 ticket과 lottery라는 개념을 사용해 CPU time을 가질 프로세스를 선택하게 된다.  

### Ticket  
* Lottery scheduling에서 티켓은 프로세스가 받아야할 공유 자원의 몫이다.  
* e.g. 프로세스 A가 60개의 티켓을, 프로세스 B가 40개의 티켓을 가진 경우 -> A는 궁극적으로 전체 CPU time 중 60%를 차지하고, B는 궁극적으로 40%를 차지하게 된다.  

### Lottery  
* 프로세스들에게 배정된 티켓들은 바로 lottery를 위한 것이다.  
* lottery의 방식은 다음과 같다.  
    * 스케줄러는 프로세스들이 가지고 있는 전체 티켓의 개수를 알고있다.  
    * 스케줄러는 랜덤하게 티켓 중 하나를 고른다.  
    * 해당 티켓을 가진 프로세스가 다음 time slice 동안 CPU를 사용한다.  
* lottery에서 중요한 것은 "랜덤"을 사용하는 것이다.  

## Lottery Scheduling의 의미  
* 랜덤성을 사용하여 global하게나 local(각 프로세스의 state)하게 관리해야하는 것이 적다. 전체 티켓의 개수, 각 프로세스들이 갖고 있는 티켓이 무엇인지 등 다른 스케줄링 알고리즘에 비해 light-weight하다. 이는 결국 변수들로 인한 side-effect를 최소화할 수 있는 설계라고 생각한다.  
* 또한, 적절한 random number generator만 사용한다면 빠르게 다음으로 스케줄링될 프로세스를 선택할 수 있다.  
* deterministic이 아닌 probablisitic이기 때문에, 프로세스들 사이에 lottery가 진행되고 있는 중간에 새로운 프로세스가 와도 얼마든지 대응할 수 있다.  
* 하지만 범용 OS의 경우 각 프로세스가 얼마나 많은 티켓을 각각 할당 받아야하는지 결정하는 것이 쉽지 않기 때문에 우리가 흔히 아는 Linux 등의 운영체제에서 lottery scheduling을 채택하지 않는 것으로 보인다.  