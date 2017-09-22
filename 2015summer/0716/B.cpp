/*************************************************************************
	> File Name: code/2015summer/0716/B.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月16日 星期四 19时55分50秒
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
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int MOD=9937;
const int N=1E5+9;
int dp[85][N];
int m,n;
void solve()
{
    memset(dp,0,sizeof(dp));
    dp[2][1]=2;   
    dp[1][0]=1;  
    for(int i=3;i<=80;i++)  
	  for(int j=0;j<=N;j++)
	  {
		if(j>=2)  
		    dp[i][j]=(dp[i-1][j-2]*(i-2))%MOD;  
		if(j>=1)  
		    dp[i][j]=(dp[i][j]+dp[i-1][j-1]*2)%MOD;  

	  }
}
int main()
{
    solve();
    while (scanf("%d %d",&n,&m)!=EOF)
    {
	  if (n==0&&m==0) break;
	  cout<<dp[n][m]<<endl;

    }
	return 0;
}
