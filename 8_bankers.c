#include <stdio.h>

int main(void)
{
    int n,m;
    int max[20][20], alloc[20][20], need[20][20], avail[20];
    int finish[20]={0}, safe[20], count=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter number of resources: ");
    scanf("%d",&m);

    printf("Enter Max Matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) scanf("%d",&max[i][j]);

    printf("Enter Allocation Matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) scanf("%d",&alloc[i][j]);

    printf("Enter Available Resources:\n");
    for(int j=0;j<m;j++) scanf("%d",&avail[j]);

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            need[i][j]=max[i][j]-alloc[i][j];

    while(count<n){
        int found=0;
        for(int i=0;i<n;i++){
            if(finish[i]) continue;
            int possible=1;
            for(int j=0;j<m;j++)
                if(need[i][j]>avail[j]) possible=0;

            if(possible){
                for(int j=0;j<m;j++) avail[j]+=alloc[i][j];
                finish[i]=1;
                safe[count++]=i;
                found=1;
            }
        }
        if(!found) break;
    }

    if(count==n){
        printf("System is in SAFE state.\nSafe sequence: ");
        for(int i=0;i<n;i++) printf("P%d%s",safe[i]+1,(i==n-1)?"\n":" -> ");
    }else{
        printf("System is in UNSAFE state.\n");
    }

    return 0;
}
