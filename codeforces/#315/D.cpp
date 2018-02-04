/*************************************************************************
	> File Name: code/cf/#315/D.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月15日 星期六 06时01分22秒
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
const int MOD=1E9+7;
const int N=4E3+5;
LL dp[N][N],c[N][N];
void init()
{
    dp[0][0] = 1;
    dp[1][1] = 1;
    for ( int i = 2; i < N; i++)
    {
	dp[i][1] = dp[i-1][i-1];
	for ( int j = 2 ; j <= i ; j++)
	{
	    dp[i][j] = (dp[i][j-1] + dp[i-1][j-1]) %MOD;
	}
    }

    for ( int i = 1 ; i< N ;i++)
    {
	c[i][0] = 1;
	c[i][i] = 1;
	for ( int j = 1 ; j<i ; j++)
	{
	    c[i][j] = (c[i-1][j-1] + c[i-1][j])%MOD;

	}
    }
}
int main()
{
    init();
    int n;
    int ans = 0;
    scanf("%d",&n);
    for ( int i = 0 ; i < n ; i++)
    {
	ans = ans + c[n][i] * dp[i][i];
	ans = ans % MOD;
    }
    cout<<ans<<endl;
  
	return 0;
}
