### [공룡책 6장 exercise 문제풀이]

#### 6.9 The following program example can be used to sum the array values of size N elements in parallel on a system containing N computing cores (there is a separate processor for each array element):
```c
  for j = 1 to log 2(N) {
    for k = 1 to N {
      if ((k + 1) % pow(2,j) == 0) {
        values[k] += values[k - pow(2,(j-1))]
      }
    }
  }
```
#### This has the effect of summing the elements in the array as a series of partial sums, as shown in Figure 6.16. After the code has executed, the sum of all elements in the array is stored in the last array location. Are there any race conditions in the above code example? If so, identify where they occur and illustrate with an example. If not, demonstrate why this algorithm is free from race conditions.
->
가정 1) `for j = 1 to log 2(N)` 문이 병렬적으로 수행되는 경우 : 가장 바깥쪽의 for 문은 그림 6.17에서 각 세로줄의 연산 수행을 의미한다. 즉, for 문 하나에 배열 안에서 일어나는 모든 연산을 포함하고 있으므로 각각의 스레드에서 병렬적으로 연산이 이루어져도 race condition이 일어나지 않는다.  
가정 2) `for k = 1 to N` 문이 병렬적으로 수행되는 경우 : 안쪽 for 문은 배열 내에서 조건에 맞는 index의 배열 값끼리 연산을 수행 후 배열 값을 갱신한다. 즉, for 문을 전부 돌아야 하나의 배열 안에서 일어나는 모든 연산을 포함하게 되는데 이런 for 문을 각각의 스레드에서 병렬적으로 수행하게 되면 상호 배제를 위반하게 된다.

#### 6.10 The compare and swap() instruction can be used to design lock-free data structures such as stacks, queues, and lists. The program example shown in Figure 6.17 presents a possible solution to a lock-free stack using CAS instructions, where the stack is represented as a linked list of Node elements with top representing the top of the stack. Is this implementation free from race conditions?
-> 
compare_and_swap 함수에서는 변경할 값과 기댓값을 비교한 후 값을 갱신하기 때문에 상호 배제를 위해 변수를 lock할 필요가 없다. 하지만 이러한 compare_and_swap 함수는 ABA problem이 발생하기 때문에 값의 정확성을 보장할 수 없다.
 ABA problem란 compare_and_swap 함수를 사용해 자료구조의 아이템을 변경할 때, 포인터가 시스템에 의해 재사용되면서 발생하는 문제이다. 
 
📌 ABA problem을 이해하기 위해 아래 링크들을 참고하였다.  
    http://15418.courses.cs.cmu.edu/spring2013/article/46  
    https://blog.naver.com/jjoommnn/130040068875  
    https://chfhrqnfrhc.tistory.com/entry/ABA-Problem-1  
    https://wannabe-gosu.tistory.com/29
