/*************************************************************************
	> File Name: code/2015summer/0716/O.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月16日 星期四 10时41分16秒
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
const  int N=1E4+5;
const int inf = 88888888;
int E,F,v,p[N],w[N],dp[N],n;
void init()
{
    for ( int i = 1 ; i < N ; i++)
	  dp[i]=inf;
    dp[0]=0;
    cin>>E>>F;
    cin>>n;
    v=F-E;
    for ( int i = 1  ; i <= n ;i++ )
	  scanf("%d %d",&p[i],&w[i]);
}   

void pack(int cost,int weight)
{
    for ( int i = cost ; i <= v ; i++)
	  if (dp[i]>0)
	  dp[i]=min(dp[i],dp[i-cost]+weight);
}
int main()
{
    int cas;
    cin>>cas;
    while (cas--)
    {
	  init();
	  for ( int i = 1 ; i <= n ; i++)
		pack(w[i],p[i]);
	  if (dp[v]==inf)
	  {
		printf("This is impossible.\n");
	  }
	  else
	  {
		printf("The minimum amount of money in the piggy-bank is %d.\n",dp[v]);
	  }
    }
  
	return 0;
}
