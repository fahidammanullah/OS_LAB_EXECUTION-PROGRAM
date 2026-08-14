#include <stdio.h>

int main(void)
{
    int n, pid[20], at[20], bt[20], ct[20], wt[20], tat[20];
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter arrival time and burst time for P%d: ", pid[i]);
        scanf("%d%d", &at[i], &bt[i]);
    }

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (at[i] > at[j]) {
                int t;
                t=at[i]; at[i]=at[j]; at[j]=t;
                t=bt[i]; bt[i]=bt[j]; bt[j]=t;
                t=pid[i]; pid[i]=pid[j]; pid[j]=t;
            }

    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time < at[i])
            time = at[i];

        wt[i] = time - at[i];
        time += bt[i];
        ct[i] = time;
        tat[i] = ct[i] - at[i];

        awt += wt[i];
        atat += tat[i];
    }

    printf("\nPID\tAT\tBT\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], wt[i], tat[i]);

    printf("Average Waiting Time = %.2f\n", awt / n);
    printf("Average Turnaround Time = %.2f\n", atat / n);

    return 0;
}
