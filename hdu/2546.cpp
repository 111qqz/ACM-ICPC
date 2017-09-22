/* ***********************************************
Author :111qqz
Created Time :2016年02月22日 星期一 22时44分27秒
File Name :code/hdu/2546.cpp
************************************************ */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

const int  N=2E3+5;
int mmax;
int a[N],dp[N],posi;
int n,m;

void ZeroOnePack(int value ,int cost)
{
     for ( int i = m - 5 ; i >= cost ; i-- )
        dp[i]=max(dp[i],dp[i-cost]+value);

}

int main()
{
    while (scanf("%d",&n)!=EOF&&n)
    {   mmax = -1;
       memset(dp,0,sizeof(dp));
       memset(a,0,sizeof(a));
        for ( int i = 1 ; i <= n ; i++)
            scanf("%d",&a[i]);
        for ( int i = 1 ; i <= n ; i++)
            if ( a[i] > mmax )
            {
                mmax=a[i];
                posi=i;
            }
        scanf("%d",&m);
        if ( m< 5) {printf("%d\n",m);continue;}


        for ( int i = 1 ; i <= n ; i++ )
            if ( i!=posi )
            ZeroOnePack(a[i],a[i]);
            printf("%d\n",m-dp[m-5]-mmax);
    }
    return 0;
}
