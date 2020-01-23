#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int power_sum(int num,int x,int n)
{
    if(pow(x,n)<num)
        return power_sum(num,x,n+1)+power_sum(num-pow(x,n),x,n+1);
    else if(pow(x,n)==num)
        return 1;
    else
        return 0;
}
int main()
{
    int num,x;
    scanf("%d",&num);
    scanf("%d",&x);
    printf("%d",power_sum(num,x,1));
    return 0;
}
