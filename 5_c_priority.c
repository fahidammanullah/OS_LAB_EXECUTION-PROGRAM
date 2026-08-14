#include <stdio.h>

int main(void)
{
    int n, pid[20], at[20], bt[20], pr[20], ct[20], wt[20], tat[20], done[20]={0};
    float awt=0, atat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        pid[i]=i+1;
        printf("Enter AT, BT and Priority for P%d: ",pid[i]);
        scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
    }

    int time=0, completed=0;
    while(completed<n){
        int idx=-1;
        for(int i=0;i<n;i++)
            if(!done[i] && at[i]<=time &&
               (idx==-1 || pr[i]<pr[idx]))
                idx=i;

        if(idx==-1){ time++; continue; }

        wt[idx]=time-at[idx];
        time += bt[idx];
        ct[idx]=time;
        tat[idx]=ct[idx]-at[idx];
        done[idx]=1;
        completed++;
        awt+=wt[idx];
        atat+=tat[idx];
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tWT\tTAT\n");
    for(int i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i],at[i],bt[i],pr[i],ct[i],wt[i],tat[i]);

    printf("Average Waiting Time = %.2f\n",awt/n);
    printf("Average Turnaround Time = %.2f\n",atat/n);
    return 0;
}
