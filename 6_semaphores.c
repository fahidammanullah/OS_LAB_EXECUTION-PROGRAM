#include <stdio.h>

int main(void)
{
    int n, tq;
    int at[20], bt[20], rem[20], ct[20], wt[20], tat[20];
    int q[1000], front=0, rear=0, added[20]={0};
    float awt=0, atat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter arrival time and burst time for P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
        rem[i]=bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d",&tq);

    int time=0, completed=0;
    while(completed<n){
        for(int i=0;i<n;i++)
            if(!added[i] && at[i]<=time){
                q[rear++]=i;
                added[i]=1;
            }

        if(front==rear){
            time++;
            continue;
        }

        int p=q[front++];
        int run=(rem[p]<tq)?rem[p]:tq;
        time+=run;
        rem[p]-=run;

        for(int i=0;i<n;i++)
            if(!added[i] && at[i]<=time){
                q[rear++]=i;
                added[i]=1;
            }

        if(rem[p]>0)
            q[rear++]=p;
        else{
            ct[p]=time;
            tat[p]=ct[p]-at[p];
            wt[p]=tat[p]-bt[p];
            awt+=wt[p];
            atat+=tat[p];
            completed++;
        }
    }

    printf("\nPID\tAT\tBT\tWT\tTAT\tCT\n");
    for(int i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1,at[i],bt[i],wt[i],tat[i],ct[i]);

    printf("Average Waiting Time = %.2f\n",awt/n);
    printf("Average Turnaround Time = %.2f\n",atat/n);
    return 0;
}
