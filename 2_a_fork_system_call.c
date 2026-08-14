#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    printf("THIS LINE IS EXECUTED BY BOTH PROCESSES\n");

    if (pid == 0) {
        printf("I AM CHILD PROCESS AND MY ID IS %d\n", getpid());
        printf("MY PARENT PROCESS ID IS %d\n", getppid());
    } else {
        printf("I AM PARENT PROCESS AND MY ID IS %d\n", getpid());
        printf("MY PARENT PROCESS ID IS %d\n", getppid());
    }

    return 0;
}
