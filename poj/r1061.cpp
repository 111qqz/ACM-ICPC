#include<stdio.h>
using namespace std;
__int64 exgcd(__int64 a,__int64 b,__int64 &x,__int64 &y)//欧几里得算法的扩展
{
    __int64 r,t;
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    r=exgcd(b,a%b,x,y);
    t=x;
    x=y; 
    y=t-a/b*y;
    return r;
}
int main()
{
    __int64 x,y,m,n,l,xx,yy,d,r;
    scanf("%I64d%I64d%I64d%I64d%I64d",&x,&y,&m,&n,&l);
    d=exgcd(n-m,l,xx,yy);
    if((x-y)%d!=0) printf("Impossible\n");
    else {
            xx=xx*((x-y)/d);
            r=l/d;
            xx=(xx%r+r)%r;//求出最小非负整数解
            printf("%I64d\n",xx);
        }
    return 0;
}
