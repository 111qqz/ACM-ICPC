/* ***********************************************
Author :111qqz
Created Time :2016年02月22日 星期一 23时13分34秒
File Name :code/hdu/1114.cpp
************************************************ */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;
int T,E,F,V,n;
const int N=1E4+5;
int dp[N],w[N],p[N];
const int inf=99999999;

void solve (int cost,int value)
{
    for ( int i = cost ; i <= V ; i++)
        if (dp[i]>0)
        dp[i] = min(dp[i],dp[i-cost]+value);
}

void init()
{
    for ( int i = 0 ; i <= N ; i++)
        dp[i] = inf ;
    dp[0]=0;
}

int main()
{
    scanf("%d",&T);
    while ( T--)
    {
        init();
        scanf("%d %d",&E,&F);
        V =F - E;
        scanf("%d",&n);
        for ( int i = 1 ; i <= n ; i++ )
            scanf("%d %d",&p[i],&w[i]);
        for ( int i = 1 ; i <= n ; i++ )
            solve(w[i],p[i]);
      //  for ( int i = 1 ; i <= V ; i++)
      //      if (dp[i]>0)
       //     cout<<"dp[i]:"<<dp[i]<<endl;

        if (dp[V]==inf)
        {
            printf("This is impossible.\n");
        }
        else
        {
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[V]);
        }

    }
    return 0;
}
