#include<stdio.h>
#include<stdlib.h>
int  power(int m,int n)
{
    if(n==0)
        return 1;
    int num=power(m,n/2);
    if(n%2==0)
        num=num*num;
    else
        num=m*num*num;
    return num;
}
int main()
{
    int m,n;
    scanf("%d",&m);
    scanf("%d",&n);
    printf("%d",power(m,n));
    return 0;
}
