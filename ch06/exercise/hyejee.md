**6.9 The following program example can be used to sum the array values of size N elements in parallel on a system containing N computing cores (there is a separate processor for each array element):**  
```C
for j = 1 to log 2(N) { 
    for k = 1 to N {
        if ((k + 1) % pow(2,j) == 0) {
            values[k] += values[k - pow(2,(j-1))]
        }
    }
}
```  
**This has the effect of summing the elements in the array as a series of partial sums, as shown in Figure 6.16. After the code has executed, the sum of all elements in the array is stored in the last array location. Are there any race conditions in the above code example? If so, identify where they occur and illustrate with an example. If not, demonstrate why this algorithm is free from race conditions.**  
![CleanShot 2022-09-16 at 10 07 35@2x](https://user-images.githubusercontent.com/46441723/190534877-63ded16c-d893-4cc0-899c-2c8010f90d8d.png)  

* 중첩된 내부 for-loop(`for k = 1 to N`)만 parallel하게 실행되는 경우  
    * race condition이 발생하지 않는다. 각 thread는 동일한 배열이지만 서로 다른 위치의 원소들을 업데이트하기 때문에 race condition이 발생하지 않는다.  
* 외부, 내부 for-loop 모두 parallel하게 실행되는 경우  
    * 내부 for-loop의 순차적인 실행을 보장하는 locking을 도입하지 않는 경우 race condition이 발생한다. 외부 for-loop은 내부 for-loop를 통해 값이 업데이트된 배열에 대해 순차적으로 실행되어야 하는데, 외부 for-loop가 parallel하게 실행되면 업데이트가 되지 않은 배열에 대해 수행되는 등 race condition이 발생한다.  

**6.10 The compare and swap() instruction can be used to design lock-free data structures such as stacks, queues, and lists. The program example shown in Figure 6.17 presents a possible solution to a lock-free stack using CAS instructions, where the stack is represented as a linked list of Node elements with top representing the top of the stack. Is this implementation free from race conditions?**  
![CleanShot 2022-09-18 at 16 00 55@2x](https://user-images.githubusercontent.com/46441723/190889900-0e576e23-9815-4636-a719-669a0722b729.png)   