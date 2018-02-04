/*************************************************************************
	> File Name: code/bc/#42/C.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月01日 星期六 10时52分24秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x7fffffff;
const int N=1E2+5;
int a[N][N];
int n,m,k;
int dp[N][N][N];

int mx(int x1,int x2,int x3,int x4)
{
    int  res = -1;
    if (x1>res) res = x1;
    if (x2>res) res = x2;
    if (x3>res) res = x3;
    if (x4>res) res = x4;
    return res;
}
void solve (int x,int y,int cost, int value)
{
    for ( int v = k ; v >= cost ; v--)
    {
	dp[x][y][v]=mx(dp[x-1][y][v],dp[x][y-1][v],dp[x-1][y][v-cost]+value,dp[x][y-1][v-cost]+value);
    }
}
int main()
{
    while (scanf("%d %d %d",&n,&m,&k)!=EOF)
    {
	for ( int i = 1 ; i <= n ; i++ )
	{
	    for ( int j = 1;  j <= m ; j++ )
	    {
		scanf("%d",&a[i][j]);
	    }
	}
	memset(dp,0,sizeof(dp));
	for ( int i = 1 ; i <= n ; i++ )
	{
	    for ( int j = 1 ; j <= m ; j++ )
	    {
		solve(i,j,a[i][j],a[i][j]);
	    }
	}
	int ans = -1;
	for ( int i = 1 ; i <= k ; i++)
	{
	    ans = max (ans,dp[n][m][i]);
	}
	cout<<ans<<endl;
    }
  
	return 0;
}
