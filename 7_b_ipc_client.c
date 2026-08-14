#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main(void)
{
    key_t key = 1234;
    int shmid = shmget(key, SHM_SIZE, 0666);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    char *shm = shmat(shmid, NULL, 0);
    if (shm == (char *)-1) {
        perror("shmat");
        return 1;
    }

    printf("MESSAGE : %s IS RECEIVED\n", shm);

    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
