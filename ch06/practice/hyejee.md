**6.1 In Section 6.4, we mentioned that disabling interrupts frequently can affect the system’s clock. Explain why this can occur and how such effects can be minimized.**  

**6.2 What is the meaning of the term busy waiting? What other kinds of waiting are there in an operating system? Can busy waiting be avoided altogether? Explain your answer.**  

**6.3 Explain why spinlocks are not appropriate for single-processor systems yet are often used in multiprocessor systems.**  

**6.4 Show that, if the wait() and signal() semaphore operations are not executed atomically, then mutual exclusion may be violated.**  

**6.5 Illustrate how a binary semaphore can be used to implement mutual exclusion among n processes.**  

**6.6 Race conditions are possible in many computer systems. Consider a banking system that maintains an account balance with two functions: deposit(amount) and withdraw(amount). These two functions are passed the amount that is to be deposited or withdrawn from the bank account balance. Assume that a husband and wife share a bank account. Concurrently, the husband calls the withdraw() function, and the wife calls deposit(). Describe how a race condition is possible and what might be done to prevent the race condition from occurring.**  