### [Lottery Scheduling]

#### Q. Lottery Scheduling이란?  
Lottery Scheduling은 운영체제의 proportional share(비례 지분) 스케줄링 알고리즘이다. 각 프로세스에는 로또 번호를 받는 것처럼 ticket이 할당되고, 스케줄러는 다음에 스케줄링할 프로세스를 선택하기 위해 임의의 ticket을 뽑는다. 이때, 모든 프로세스의 ticket 분배가 균일할 필요는 없다. 선택의 우선순위를 주고 싶다면 해당 프로세스에 더 많은 ticket을 부여하여 더 높은 선택 기회를 제공한다. 즉, 프로세스들이 보유한 ticket 비율이 해당 시스템의 자원 점유율이 된다. 또한, 각 프로세스에는 적어도 하나의 ticket을 제공하게 되면 선택될 확률이 0이 아님을 보장함으로 기아 문제를 해결할 수 있다.

#### Q. Ticket Mechanisms  
Ticket Currency : ticket을 마치 돈처럼 사용하는 개념으로 어떤 프로세스에게 지역 통화를 부여하면 CPU는 이를 글로벌 통화로 바꿔 스케줄링에 사용하는 방식.
Ticket Transfer : ticekt을 다른 프로세스에게 전송하는 방식으로 클라이언트-서버 환경에 유용하다. 클라이언트가 수행해야 할 작업이 없다면 자신이 가진 ticket을 서버에게 전송해 서버가 더 많은 작업을 수행할 수 있도록 돕는다.
Ticket Inflation : 이는 프로세스들이 서로 경쟁상태가 아닌 협력하는 상황에서 사용 가능한 방식으로 어떤 프로세스가 빠르게 수행되어야 하는 상황에 해당 프로세스에 부여된 ticket을 늘려 CPU를 차지하게 만들 수 있다.

#### Q. Stride Scheduling  
Lottery Scheduling은 간단하게 구현할 수 있다는 장점이 있지만 늘 공평하게 프로세스들을 스케줄링할 수는 없다. 이를 해결하기 위해 Stride Scheduling이 사용된다. 
 Stride Scheduling 프로세스에 ticket을 분배한다는 점은 같지만, ticket 수에 반비례하는 변수(stride)와 pass value를 추가하여 형평성 문제를 해결한다. stride는 어떤 값/ticket으로 구할 수 있고, pass value는 처음에는 모두 0으로 초기화되어 있다가 프로세스가 한 번 수행될 때마다 stride를 더해준다. 실행할 프로세스는 이 pass value 값이 가장 작은 프로세스를 실행하게 된다.
 Stride scheduling이 Lottery scheduling 보다 프로세스의 형평성을 보장하는 것 같지만 중간에 새 프로세스가 추가되는 상황에서는 반드시 Lottery scheduling가 필요하다. Stride scheduling에서 중간에 새 프로세스 A가 추가된다면 당분간은 해당 프로세스의 pass value 값이 최솟값이기 때문에 A 프로세스만 계속 실행되는 기아 상태가 지속되는 문제가 발생할 것이다.

#### Q. Completely Fair Scheduling(CFS)  
Stride Scheduling에서 pass value 값에 대한 처리 작업만 전체 CPU의 5%를 소모한다. 이 때문에 현재 Linux 시스템에서는 Completely Fair Scheduling 스케줄링을 사용한다. 
 앞서 배운 스케줄링 기법들이 고정된 time slice를 전제로 하지만, CFS는 모든 프로세스들에게 CPU를 말 그대로 균등하게 배분하고자 Virtual runtime(vruntime)이라는 간단한 카운팅 기반의 기술을 통해 구현한다. 즉, 앞선 스케줄링에서는 time slice를 사용하여 현재 실행 중인 프로세스를 중단시키고 새로운 프로세스를 스케줄링 할 수 있었지만 CFS는 time slice와 같은 고정값을 사용하지 않는다.
 스케줄러는 vruntime이 가장 낮은 프로세스를 다음 실행할 작업으로 선택하고, 각 프로세스는 실행될 때마다 각각의 vruntime 값을 축적한다. 이때, Stride scheduling에서 사용하는 stride 등의 고정된 값이 아니라 vruntime 값은 물리적(실제) 시간에 비례하여 동일한 비율로 증가시킨다는 점이 다르다. 
 만약 프로세스를 실행시키는 시간을 너무 짧게 설정하면 형평성은 증가하겠지만 Context switching 비용으로 인해 성능이 떨어질 것이고, 반대의 경우에는 성능 측면에서는 좋아지지만, 형평성의 측면에서 떨어질 것이다. CFS는 sche_latency, min_granuality 같은 값들을 사용하여 Context switching 발생 이전에 새로 선택된 프로세스를 얼마큼 오래 실행할지 결정하여 스케줄링 한다. 


