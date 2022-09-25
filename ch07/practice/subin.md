### [7장 pracitce 문제 풀이]

#### 7.1 Windows와 Linux가 여러 락 기법을 구현하는 이유를 설명하라. 그들이 스핀락, mutex 락, 세마포 및 조건 변수를 사용하는 환경을 설명하라. 각각의 경우에 그 기법이 필요한 이유를 설명하라.
->

#### 7.2 Windows는 슬림 reader-writer 락이라는 가벼운 동기화 도구를 제공하낟. 대부분의 reader-writer 구현은 reader 또는 writer를 선호하거나 FIFO 정책을 사용하여 대기 스레드를 정렬하는 반면에, 슬림 reader-writer은 reader 또는 writer를 선호하지 않으며 대기 스레드를 FIFO 정책에 따라 정렬하지도 않는다. 이러한 동기화 도구를 제공하면 얻을 수 있는 이점을 설명하라.
->

#### 7.3 이진 세마포 대신 mutex 락을 사용할 수 있도록 하려면 그림 7.1 및 그림 7.2의 생산자와 소비자 프로세스를 어떻게 변경해야 하는지 설명하라.
->
<p align="center"><img src="https://user-images.githubusercontent.com/45066381/192123727-300f88f2-2f11-40c9-94ca-8214c22b17bd.png" width="500" height="300"/></p>
<p align="center"><img src="https://user-images.githubusercontent.com/45066381/192123730-a1555e88-bc36-4322-bdde-f26c8a5199ca.png" width="500" height="300"/></p>

위의 코드에서 wait(mutex) -> acquire(mutex)로, signal(mutex) -> release()로 수정하면 이진 세마포어 대신 mutex를 사용할 수 있다. 즉, API 변경을 통해 변경할 수 있다.

#### 7.4 식사하는 철학자들의 문제에서 교착 상태가 어떻게 가능한지 설명하라.
->
 식사하는 철학자들의 문제에서 교착상태는 다섯 명의 철학자가 원탁에 앉아 있고, 각자의 앞에는 스파게티와 양옆에 포크가 하나씩 있다고 가정하는 상황에서 발생한다. 이때, 각각의 철학자는 다른 철학자에게 말을 할 수 없으며, 스파게티를 먹기 위해서는 양옆의 포크를 동시에 들어야 한다. 
 각각의 철학자가 왼쪽의 포크를 들고 난 후 오른쪽의 포크를 들어서 스파게티를 먹는 경우 다섯 철학자는 동시에 왼쪽의 포크를 들 수 있으나 오른쪽의 포크는 이미 다른 철학자가 가져간 상태이기 때문에 다섯 명 모두가 무한정 서로를 기다리는 교착 상태에 빠지게 될 수 있다.

#### 7.5 Windows dispatcher 객체의 signaled 상태와 nonsignaled 상태의 차이점을 설명하라.
->

#### 7.6 val이 Linux 시스템에서 원자적 정수라고 가정하자. 다음 연산이 완료된 후 val 값은 무엇인가?
` 
atomic_set(&val, 10);
atomic_sub(8, &val);
atomic_inc(&val);
atomic_inc(&val);
atomic_add(6, &val);
atomic_sub(3, &val);
`
->
10(set) – 8(sub) + 1(inc) + 1(inc) + 6(add) – 3(sub) = 7