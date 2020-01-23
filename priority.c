#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n2;
    scanf("%d",&n2);
    printf("Enter number of processes:\n");
    int n,i,j,total=0,t;
    float avgwt,avgtat;
    scanf("%d",&n);
    int bt[20];
    int *p=(int*)malloc(sizeof(int)*n);
    int *pr=(int*)malloc(sizeof(int)*n);
    int *tat=(int*)malloc(sizeof(int)*n);
    int *wt=(int*)malloc(sizeof(int)*n);
    printf("Enter burst time:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }
    printf("Enter priority of processes\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&pr[i]);
    }
    if(n2==2)
    {
    for(i=0;i<n;i++)
    {

        int pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]>pr[pos])
                pos=j;
        }
        t=pr[i];
        pr[i]=pr[pos];
        pr[pos]=t;

        t=bt[i];
        bt[i]=bt[pos];
        bt[pos]=t;

        t=p[i];
        p[i]=p[pos];
        p[pos]=t;

    }
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
        {
            wt[i]+=bt[j];
        }
        total+=wt[i];
    }
    avgwt=(float)total/n;
    total=0;
    printf("Processes/t   Burst Time/t   Waiting Time/t   Turnaround Time\n");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        total+=tat[i];
        printf("%d   %d    %d   %d\n",p[i]+1,bt[i],wt[i],tat[i]);
    }
    avgtat=(float)total/n;
    printf("Average Waiting Time=%.2f\n",avgwt);
    printf("Average Turnaround Time=%.2f\n",avgtat);
    }
    else if(n2==1)
    {
        int *at=(int*)malloc(sizeof(int)*n);
        printf("Enter the arrival time of processes\n");
        for(i=0;i<n;i++)
        {
            scanf("%d",&at[i]);
        }
        for(i=0;i<n;i++)
        {
        int pos=i;
        for(j=i+1;j<n;j++)
        {
            if(at[j]<at[pos])
                pos=j;
            else if(at[j]==at[pos]&&pr[j]>pr[pos])
                pos=j;
            else if(at[j]==at[pos]&&pr[j]<pr[pos])
                pos=pos;
        }
        t=pr[i];
        pr[i]=pr[pos];
        pr[pos]=t;

        t=bt[i];
        bt[i]=bt[pos];
        bt[pos]=t;

        t=p[i];
        p[i]=p[pos];
        p[pos]=t;
        }
        wt[0]=0;
        for(i=1;i<n;i++)
        {
            wt[i]=0;
            for(j=0;j<i;j++)
            {
                wt[i]+=bt[j];
            }
            total+=wt[i];
        }
        avgwt=(float)total/n;
        total=0;
        printf("Processes/t   Burst Time/t   Waiting Time/t   Turnaround Time\n");
        for(i=0;i<n;i++)
        {
            tat[i]=bt[i]+wt[i];
            total+=tat[i];
            printf("%d   %d    %d   %d\n",p[i],bt[i],wt[i],tat[i]);
        }
        avgtat=(float)total/n;
        printf("Average Waiting Time=%.2f\n",avgwt);
        printf("Average Turnaround Time=%.2f\n",avgtat);
    }
    return 0;
}
