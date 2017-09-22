/* ***********************************************
Author :111qqz
Created Time :2016年02月22日 星期一 23时18分21秒
File Name :code/hdu/1176.cpp
************************************************ */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int n,t,x,maxtime;
long long ans;
const int N=1E5+7;
int a[N][15],dp[N][15];

int MAX(int a,int b,int c)
{
    int res = -1;
    if ( a>res )
        res = a;
    if ( b>res )
        res = b;
    if ( c>res )
        res = c;
    return res;
}

int main()
{
    while ( scanf("%d",&n)!=EOF&&n )
    {
        ans = -1 ;
        maxtime = -1;
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        for ( int i = 1 ; i <= n ; i++ )
        {
            scanf("%d %d",&x,&t);
            a[t][x]++;
            if ( t>maxtime )
                maxtime = t;
        }
        dp[1][4] = a[1][4];
        dp[1][5] = a[1][5];
        dp[1][6] = a[1][6];
        for ( int i = 2 ; i <= maxtime ; i++ )
            for ( int j = 0 ; j <= 10 ; j++ )
            {
                if ( j==0 )
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j+1]) + a[i][j];
                    else if ( j==10 )
                            dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + a[i][j];
                            else  dp[i][j] = MAX(dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1])+a[i][j];
               // if ( dp[i][j]>ans )
              //      ans = dp[i][j];
             
            }
            for ( int i = 0 ; i <= 10 ; i++)
                if ( dp[maxtime][i]>ans )
                   ans = dp[maxtime][i];
        printf("%I64d\n",ans);

    }
    return 0;
}
