[Programming Problems 3.18]

좀비 프로세스를 만드는 예시 1) 
```
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    // Fork returns process id
    // in parent process
    pid_t child_pid = fork();
  
    // Parent process 
    if (child_pid > 0)
        sleep(50);
  
    // Child process
    else        
        exit(0);
  
    return 0;
}
```
-> 부모 프로세스가 wait 시스템 콜을 사용하여 자식 프로세스가 끝나기를 대기해야 하는데 50초 sleep 하는 동안 자식 프로세스는 exit 함수를 호출하여 실행을 종료하기 때문에 하위 프로세스 항목이 프로세스 테이블에 여전히 존재하게 되면서 자식 프로세스가 좀비 프로세스가 된다. 

좀비 프로세스를 만드는 예시 2)
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int main() { 
    pid_t childPid;   
    childPid = fork();
    
    // Parent process 
    if(childPid > 0) {  
        printf("부모 PID : %ld, pid : %d\n",(long)getpid(), childPid);
        sleep(30);
        printf("부모 종료\n");
        exit(0);
    }

    // Child process
    else if(childPid == 0){  
        printf("자식 시작 PID : %ld\n", (long)getpid());
        sleep(1);
        printf("자식 종료\n");
        exit(0);
    }
    else {  // fork 실패
        perror("fork Fail! \n");
        return -1;
    }
    return 0;
}
```
-> 위 경우 또한 자식 프로세스가 부모 프로세스 보다 먼저 종료되면서 자식 프로세스가 좀비 프로세스가 되는 경우이다.

*정리
 자식 프로세스가 exit 시스템 콜을 호출하면서 종료해야 해당 프로세스와 관련된 모든 메모리와 자원이 해제되어 다른 프로세스가 사용할 수 있게 된다. 자식 프로세스가 종료된 이후에도 부모 프로세스가 자식 프로세스의 상태를 알고 싶은 경우가 발생할 수 있으므로 커널은 자식 프로세스가 종료되더라도 최소한의 정보(PID, 프로세스 종료 상태 등)를 가지고 있게 된다. 이렇게 프로세스는 종료되었지만, 프로세스 테이블에서 제거되지 않은 프로세스를 좀비 프로세스라 한다. 이러한 좀비 프로세스는 1) 인자를 전달하면서 exit를 호출하는 경우 2) main 함수에서 return문을 실행하면서 값을 반환하는 경우 만들어진다.
 좀비 프로세스가 쌓이게 되면 리소스의 유출을 일으킬 수 있어서 좀비 프로세스 상태를 오래 유지되지 않도록 부모 프로세스는 wait 시스템 콜 함수를 사용하여 자식 프로세스의 종료 상태를 읽어 들이는 것이 필요하다.