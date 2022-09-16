## CFS

리눅스에서는 completely fair scheduler 를 사용하여 fairness 를 만족 시킵니다. vitrtual runtime 이라는 기술로 모든 프로세스에게 CPU를 균등하게 분배하는 목표를 수행합니다. 각 프로세스들은 실행될 때마다 virtual runtime이 누적되고, CFS 스케줄러는 virtual runtime을 기준으로 가장 작은 프로세스를 다음에 실행할 프로세스로 선택합니다. CFS가 실행 중인 프로세스를 자주 바꾸면 fairness가 증가할 수 있지만, 잦은 context switch 때문에 성능이 저하됩니다. 따라서 CFS 는 다음 프로세스를 실행할 시간인 “예정된 지연 시간”과 time slice 의 min 값을 결정하는 “min granularity”를 통해 완벽하게 공평한 스케줄링(CFS)를 할 수 있게 됩니다.

 하지만 I/O 대기를 하는 프로세스가 장기간 sleep 하게 되면 virtual runtime이 다른 프로세스에 비해 뒤쳐지게 됩니다. 그래서 해당 프로세스가 깨어나면 virtual runtime을 맞추기 위해 해당 프로세스만 실행하게 되고, 이 시간동안에는 다른 프로세스가 CPU를 할당받지 못하게 됩니다.

## Lottery Scheduling

각 프로세스에게 lottery 를 할당하고, 스케줄러는 다음 프로세스를 선택하기 위해 ticket을 뽑는 확률적 스케줄링 알고리즘입니다. 당첨된 프로세스는 타임 슬라이스가 만료될 때까지 CPU를 할당받습니다. 프로세스에 더 많은 티켓을 부여하면 상대적으로 더 높은 선택 기회를 제공합니다. 또한, 각 프로세스에게 적어도 하나의 lottery 를 제공하게 되면 선택적 확률이 0이 아니기 때문에 기아 문제도 해결할 수 있습니다.

 lottery 방식은 구현이 쉽고, 관리해야 할 상태 정보가 거의 없으므로 가볍습니다. 하지만 복권으로 랜덤하게 되기 때문에 어떤 결과를 가져올지 확실하지 않는 not deterministic 을 띄고 있습니다. 

## 예시

A, B 프로세스는 각각 1 ~ 60의 숫자로 60개의 티켓을, B는 61 ~ 100인 40장의 티켓을 가지고 있다

스케줄러는 1 ~ 100까지 임의의 숫자를 선택한다

1 ~ 60 사이면 A가 실행되고 그렇지 않으면 B가 실행된다

## REFERENCES

[https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-sched-lottery.pdf](https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-sched-lottery.pdf)
