#include<stdio.h>
#include<stdlib.h>
int gcd(int x,int y)
{
    if(x==0)
        return y;
    return gcd(y%x,x);
}
int main()
{
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    int res =gcd(n,m);
    printf("%d",res);
    return 0;
}
