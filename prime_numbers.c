#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,j;
    scanf("%d",&n);
    int a[n+1];
    for(i=1;i<=n;i++)
    {
        a[i]=1;
    }
    for(i=2;i*i<=n;i++)
    {
        if(a[i]==1)
        {
        for(j=i*i;j<=n;j+=i)
        {
            a[j]=0;
        }
        }
    }
    for(i=2;i<=n;i++)
    {
        if(a[i]==1)
            printf("%d",i);
    }
    return 0;
}
