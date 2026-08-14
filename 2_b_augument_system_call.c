#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        printf("CHILD PROCESS IS IN PROGRESS\n");
        for (int i = 0; i < 5; i++)
            printf("THE CHILD PROCESSING VALUE IS: %d\n", i);

        execlp("ls", "ls", (char *)NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    printf("PARENT PROCESS IS WAITING\n");
    waitpid(pid, NULL, 0);
    printf("CHILD PROCESS COMPLETED ITS TASK\n");

    return 0;
}
