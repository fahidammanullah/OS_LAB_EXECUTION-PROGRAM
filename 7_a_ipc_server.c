#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main(void)
{
    key_t key = 1234;
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    char *shm = shmat(shmid, NULL, 0);
    if (shm == (char *)-1) {
        perror("shmat");
        return 1;
    }

    printf("Enter message: ");
    fgets(shm, SHM_SIZE, stdin);
    shm[strcspn(shm, "\n")] = '\0';

    printf("MESSAGE : %s IS SENT\n", shm);

    shmdt(shm);
    return 0;
}
