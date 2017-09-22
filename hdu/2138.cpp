/* ***********************************************
Author :111qqz
Created Time :2016年02月19日 星期五 16时54分19秒
File Name :code/hdu/2138.cpp
************************************************ */

#include <iostream>
#include <cmath>
#include <stdio.h>
#include <cstring>
 
using namespace std;
 
typedef long long LL;
LL power(LL m,LL n,LL k)
{
    int b = 1;
    while (n > 0)
    {
          if (n & 1)
             b = (b*m)%k;
          n = n >> 1 ;
          m = (m*m)%k;
    }
    return b;
}
bool judge(LL n)
{
    LL i;
    if (n<=3) return true;
    for (i=2;i<=ceil(sqrt(n))+1;i++)
        if (n %i==0) return false;
        return true;
}
 
int main()
{
    LL i,n,x;
 
    while (scanf("%I64d",&n)!=EOF)
    {   LL ans=0;
        for (i=1;i<=n;i++)
        {
            scanf("%I64d",&x);
          if ((power(61,x-1,x)==1)&&(power(11,x-1,x)==1)&&(power(31,x-1,x)==1)
                &&(power(97,x-1,x)==1))
                 ans++;
        }
          printf("%I64d\n",ans);
    }
    return 0;
}
