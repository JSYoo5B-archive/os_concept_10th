## [Practice Problems]

#### 4.1 다중 스레딩이 단일 스레딩보다 더 나은 성능을 제공하는 세 가지 프로그래밍 예시를 제시하라.
->
1. 병렬로 실행될 수 있는 태스크들이 전체 작업에 균등한 기여도를 갖도록 할 수 있으며, 태스크가 접근하고 조작하는 데이터가 개별 코어에서 균등하게 나뉘어 처리될 수 있다.
2. 스레드의 생성은 프로세스 생성보다 시간과 메모리를 덜 소비하고, 문맥 교환 또한 프로세스 사이보다 스레드 사이에서 더 빠르게 수행된다. 따라서 요청이 들어올 때마다 스레드를 생성하는 웹서버에 적합하다.
3. 응용 프로그램 일부분이 봉쇄되거나, 긴 작업을 수행하더라도 프로그램의 수행이 계속될 수 있어 사용자에 대한 응답성을 증가시킨다. 따라서 대화형 응용 프로그래밍의 경우 적합하다.

#### 4.2 Amdahl의 법칙을 사용하여 (a) 2개의 처리 코어와 (b) 4개의 처리 코어에 대한 60%의 병렬 구성요소를 가진 응용 프로그램의 속도 향상 이득을 계산하라.
->
(a) 1 / ((1-0.6) + 0.6/2) = 1 / 0.7 = 1.43 = 43%의 성능 향상
(b) 1 / ((1-0.6) + 0.6/4) = 1 / 0.55 = 1.82 = 82%의 성능 향상

#### 4.3 4.1절에 설명된 다중 스레드 웹 서버는 작업 병렬 처리인가 혹은 데이터 병렬 처리인가?
->
각 스레드는 같은 작업을 수행하지만 다루는 데이터는 다르므로 데이터 병렬 처리이다.

#### 4.4 사용자 수준 스레드와 커널 수준 스레드의 2가지 차이점은 무엇인가? 한 유령의 스레드가 다른 유형의 스레드보다 유리한 상황은 언제인가?
->
1. 사용자 수준 스레드는 사용자가 라이브러리를 통해 만들고 관리하는 반면, 커널 수준 스레드는 커널이 만들고 관리하는 스레드이다.
2. 사용자 수준 스레드는 스레드와 관련된 모든 행위를 사용자 영역에서 수행하기 때문에, 커널은 사용자 수준 스레드의 존재를 알지 못하며, 스레드 교환에 개입하지 않는다. 커널 스레드는 커널이 직접 스케줄링하고 실행하기 때문에 커널의 관리 지원을 많이 받을 수 있지만, 그만큼 오버헤드가 늘어난다.

사용자 수준 스레드는 커널 수준 스레드와는 다르게 스레드 교체 등으로 인한 오버헤드가 발생하지 않는다.
커널 수준 스레드는 사용자 수준 스레드와는 다르게 커널이 각 스레드를 개별적으로 관리하기 때문에 스레드가 병행 실행될 수 있다.

#### 4.5 커널 수준 스레드 사이에서 문맥 교환을 위해 커널이 해야 할 일을 설명하라.
->
CPU의 레지스터 값을 저장하고 문맥 교환이 일어날 대상의 CPU 레지스터 값을 가져온다.

#### 4.6 스레드가 생성될 때 어떤 자원이 사용되는가? 프로세스가 생성될 때 사용되는 자원과의 차이점은 무엇인가?
->
 스레드가 생성될 때 멀티 스레드가 공유하고 있는 코드, 데이터, 파일 정보와 레지스터, 스택 등의 자원이 필요하다. 반면에 프로세스가 생성될 때는 프로세스 상태, 프로세스 번호, 프로그램 카운터 등의 정보를 담고 있는 PCB가 필요하다.

#### 4.7 다대다 모델을 사용하여 운영체제가 사용자 수준 스레드를 커널에 매핑하고 매핑은 LWP를 사용한다고 가정하자. 또한, 개발자는 실시간 시스템에서 사용할 실시간 스레드를 만들 수 있다고 하자. 실시간 스레드를 LWP에 바인딩해야 하는가? 
-> 
