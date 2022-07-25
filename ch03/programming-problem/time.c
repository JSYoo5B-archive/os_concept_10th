#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/ipc.h>
#include <sys/shm.h>

const int MAXARGS = 100;

float time_diff(struct timeval *start, struct timeval *end) {
    return (end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
}

int checkNumberOfArgs(int argc) {
    if (MAXARGS < argc - 1) {
        return -1;
    }
    else {
        return 0;
    }
}

int main(int argc, char *argv[]) {
    if (checkNumberOfArgs(argc) == -1) {
        printf("Too many arguments.\n");
        return -1;
    }

    pid_t pid;
    int status;

    // key_t key = ftok("~/shared", 65);
    key_t key = 1234;
    
    if (key == -1) {
        printf("key!!!!!\n");
        return -1;
    }

    int shmid = shmget(key, sizeof(struct timeval), 0666 | IPC_CREAT);

    if (shmid == -1) {
        printf("fail!!!!!\n");
        return -1;
    }

    struct timeval * startTime = (struct timeval *) shmat(shmid, NULL, 0);
    
    pid = fork();

    if (pid == -1) {
        printf("can't fork, error occurred\n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) { // child process
        gettimeofday(startTime, NULL);

        shmdt(startTime);

        char * argv_list[MAXARGS] = {NULL};

        for (int i = 1; i < argc; i++) {
            argv_list[i - 1] = argv[i];
        }

        execvp(argv_list[0], argv_list);
    }
    else { // parent process
        wait(&status);

        if (status == -1) {
            shmdt(startTime);
            shmctl(shmid, IPC_RMID, NULL);
        }
        else {
            struct timeval endTime;
            gettimeofday(&endTime, NULL);

            float elapsedTime = time_diff(startTime, &endTime);
            printf("--------------------------------\n");
            printf("Elapsed time: %fs\n", elapsedTime);

            shmdt(startTime);
            shmctl(shmid, IPC_RMID, NULL);
        }
    }

    return 0;
}