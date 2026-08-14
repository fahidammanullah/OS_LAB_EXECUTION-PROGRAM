#include <stdio.h>

int main(void)
{
    int n,m;
    int alloc[20][20], need[20][20], avail[20];
    int finish[20], dead[20], dcount=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter number of resources: ");
    scanf("%d",&m);

    printf("Enter Allocation Matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) scanf("%d",&alloc[i][j]);

    printf("Enter Need/Request Matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) scanf("%d",&need[i][j]);

    printf("Enter Available Resources:\n");
    for(int j=0;j<m;j++) scanf("%d",&avail[j]);

    for(int i=0;i<n;i++){
        finish[i]=1;
        for(int j=0;j<m;j++)
            if(alloc[i][j]!=0) finish[i]=0;
    }

    int changed=1;
    while(changed){
        changed=0;
        for(int i=0;i<n;i++){
            if(finish[i]) continue;
            int possible=1;
            for(int j=0;j<m;j++)
                if(need[i][j]>avail[j]) possible=0;

            if(possible){
                for(int j=0;j<m;j++) avail[j]+=alloc[i][j];
                finish[i]=1;
                changed=1;
            }
        }
    }

    for(int i=0;i<n;i++)
        if(!finish[i]) dead[dcount++]=i;

    if(dcount==0)
        printf("No Deadlock Occur\n");
    else{
        printf("System is in Deadlock. Deadlocked processes: ");
        for(int i=0;i<dcount;i++) printf("P%d ",dead[i]+1);
        printf("\n");
    }

    return 0;
}
