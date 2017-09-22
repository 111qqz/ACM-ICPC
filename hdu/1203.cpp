/* ***********************************************
Author :111qqz
Created Time :2016年02月22日 星期一 22时50分40秒
File Name :code/hdu/1203.cpp
************************************************ */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;
    int n,m;
    const int N = 1E4+5;
    int a[N];
    double b[N],dp[N];
    double ans,mmax;

void solve(int cost,double value)
{
    for ( int i = n ; i >= cost ; i-- )
        dp[i] = min(dp[i],dp[i-cost]*value);
}

void init()
{
    for ( int i = 0 ; i <N ; i++ )
        dp[i]=1.0;
    mmax=-1;
    ans=1;
   // memset(a,0,sizeof(a));
   // memset(b,0,sizeof(b));
}
int main()
{
    while (scanf("%d %d",&n,&m)!=EOF)
    {
        init();
        if ( (n==0)&&(m==0) ) break;
        for ( int i = 1 ; i <= m ; i++ )
            scanf("%d %lf",&a[i],&b[i]);
        for ( int i = 1 ; i <= m ; i++ )
            b[i]=1-b[i];
        if ( n==0 )
        {
            for ( int i = 1 ; i <= m ; i++ )
                if ( a[i]==0 )
                    ans = ans*b[i];
            printf("%.1lf%%\n",(1-ans)*100);
            continue;
        }

        for ( int i = 1 ; i <= m ; i++ )
            solve(a[i],b[i]);
            ans = 1-dp[n];
            ans = ans*100;
      //  for ( int i = 1 ; i <= n ; i++ )
        //    printf("%lf ",dp[i]);
        printf("%.1lf%%\n",ans);
    }
    return 0;
}
