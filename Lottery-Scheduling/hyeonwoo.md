## Proportinal Scheduling algorithm

응답시간의 최적화보다는 스케줄러가 각 작업에게 “일정비율”의 CPU 사용을 보장하는게 목적인 알고리즘

## Lottery Scheduling

각 프로세스에게 lottery 를 할당하고, 스케줄러는 다음 프로세스를 선택하기 위해 ticket을 뽑는 확률적 스케줄링 알고리즘입니다. 당첨된 프로세스는 타임 슬라이스가 만료될 때까지 CPU를 할당받습니다. 프로세스에 더 많은 티켓을 부여하면 상대적으로 더 높은 선택 기회를 제공합니다. 또한, 각 프로세스에게 적어도 하나의 lottery 를 제공하게 되면 선택적 확률이 0이 아니기 때문에 기아 문제도 해결할 수 있습니다.

 lottery 방식은 구현이 쉽고, 관리해야 할 상태 정보가 거의 없으므로 가볍습니다. 하지만 랜덤하기 때문에 어떤 결과를 가져올지 확실하지 않는 not deterministic 을 띄고 있습니다. 

## Stride Scheduling

lottery scheduling에서 fairness를 보장할 수 없기 때문에 이를 해결하기 위해 stride scheduling이 나왔습니다. stride scheduling란 stride라는 변수(티켓 수 / 지정 숫자)를 두어 fairness 를 해결합니다.

모든 프로세스에 0으로 초기화한 pass value를 두어 프로세스를 한 번 수행할 때마다 pass value 값에 stride 값을 더해줘서 pass value 값이 가장 작은 프로세스를 실행합니다.

하지만 중간에 프로세스가 들어오게 되면 새로운 프로세스의 pass value를 지정하는데 어려움이 있습니다. 만약 0으로 설정한다면 해당 프로세스가 CPU를 독점할 수 있습니다. 따라서 이러한 경우에는 stride scheduling 보다는 lottery scheduling 에서 처리하는 것이 더욱 간단합니다.

즉, lottery scheduling은 fairness를 보장할 순 없지만, 중간에 새로운 프로세스가 들어오면 처리하기 쉽고, stride scheduling는 fairness를 보장하지만 중간에 새로운 프로세스가 들어오면 처리하는 것이 복잡합니다.

## CFS

리눅스에서는 completely fair scheduler 를 사용하여 fairness 를 만족 시킵니다. virtual runtime 이라는 기술로 모든 프로세스에게 CPU를 균등하게 분배하려고 합니다. 각 프로세스들은 실행될 때마다 vruntime이 누적되고, CFS 스케줄러는 vruntime이 가장 작은 프로세스를 다음에 실행할 프로세스로 선택합니다. 

 CFS에서는 time slice가 유동적입니다. 어떤 프로세스가 전환되기 전에 sched latency 라는 변수를 통해 다음 프로세스의 실행 시간을 결정합니다. 해당 값은 프로세스 수로 나누어 time slice를 결정하기 때문에 프로세스가 많아지면 time slice가 매우 짧아져 context switch가 자주 발생하여 성능 저하가 일어날 수 있습니다.

 그래서 위 문제를 해결하기 위해 min granularity 변수를 통해 최소 time slice를 정합니다. 프로세스의 개수가 많아져서 time slice가 작아지더라도 min granularity보다는 작아지지 않도록 하여 context switch가 자주 발생하지 않도록 합니다.

 하지만 I/O 대기를 하는 프로세스가 장기간 sleep 하게 되면 vruntime이 다른 프로세스에 비해 뒤쳐지게 됩니다. 그래서 해당 프로세스가 깨어나면 virtual runtime을 맞추기 위해 해당 프로세스만 실행하게 되고, 이 시간동안에는 다른 프로세스가 CPU를 할당받지 못하게 됩니다.
