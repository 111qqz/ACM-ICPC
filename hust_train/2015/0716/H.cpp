/*************************************************************************
	> File Name: code/2015summer/0716/H.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月16日 星期四 11时43分04秒
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
const int N=1E3+5;
int a[N][N];
int n;
int dp[N][N];
int main()
{
    cin>>n;
    int i,j;
    for (  i = 1 ; i <= n ; i++)
    {
	  for (  j = 1  ; j <= i ; j++)
	  {
		scanf("%d",&a[i][j]);
	  }
    }
    memset(dp,0,sizeof(dp));
    for ( int i = 1 ; i <= n ;i++)
	  dp[n][i]=a[n][i];
    for (  i = n - 1 ; i >= 1 ; i++)
    {
	  for ( j = 1 ; j <= i ; j++)
	  {
		dp[i][j]=max(dp[i+1][j],dp[i+1][j+1]+a[i][j]);
	  }
    }
	  
    
    cout<<dp[1][1]<<endl;
	return 0;

}
