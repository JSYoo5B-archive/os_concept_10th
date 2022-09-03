# Lottery Scheduling의 의미  

## Lottery Scheduling이란?  
* lottery scheduling은 fair share scheduling 중 하나이다.  
* fair share scheduling은 turnaround time을 최적화하는 대신에 모든 프로세스들이 적정한 수준의 CPU time을 가질 수 있도록 보장하는 스케줄링이다.  
* lottery scheduling은 그 중에서도 ticket과 lottery라는 개념을 사용해 CPU time을 가질 프로세스를 선택하게 된다.  

### Ticket  
* Lottery scheduling에서 티켓은 프로세스가 받아야할 공유 자원의 몫이다.  
* e.g. 프로세스 A가 60개의 티켓을, 프로세스 B가 40개의 티켓을 가진 경우 -> A는 궁극적으로 전체 CPU time 중 60%를 차지하고, B는 궁극적으로 40%를 차지하게 된다.  

### Lottery  

## Lottery Scheduling의 의미  
