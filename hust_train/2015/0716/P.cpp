/*************************************************************************
	> File Name: code/2015summer/0715/P.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月16日 星期四 10时29分10秒
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
const int N=4E3+5;
int w[N],d[N];
int dp[N];
int n,v;
void pack(int cost,int weight)
{
    for ( int i = v ; i>=cost;i--)
    {
	  dp[i]=max(dp[i],dp[i-cost]+weight);
    }
}
void init()
{
    cin>>n>>v;
    memset(dp,0,sizeof(dp));
    for ( int i = 1 ;  i <= n ;i++)
	  cin>>w[i]>>d[i];
}
int main()
{
    init();
    for ( int i = 1 ; i <= n ; i++)
	  pack(w[i],d[i]);
    cout<<dp[v]<<endl;
	return 0;
}

