/*************************************************************************
	> File Name: code/2015summer/0716/II.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月16日 星期四 17时44分32秒
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
const int N=1E5+7;
int num[N],d[N],dp[N];
int n,cash;
void pack1(int cost,int value)
{
    for ( int i = cash ; i >= cost ; i--)
	  dp[i]=max(dp[i],dp[i-cost]+value);
}
void pack2(int cost,int value)
{
    for ( int i =cost ; i <= cash ; i++ )
	  dp[i]=max(dp[i],dp[i-cost]+value);
}
void pack3(int cost,int value,int amount)
{
    if (cost*amount>=cash)
    {
	  pack2(cost,value);
	  return ;
    }
    int k = 1;
    while (k<amount)
    {
	  pack1(k*cost,k*value);
	  amount-=k;
	  k*=2;
    }
    pack1(amount*cost,amount*value);

}
int main()
{
    while (scanf("%d %d",&cash,&n)!=EOF)
    {
	  memset(dp,0,sizeof(dp));
	  for ( int i = 1 ; i <= n ;i++ )
	  {
		scanf("%d %d",&num[i],&d[i]);
	  }
	  for ( int i = 1 ; i <= n ; i++)
	  {
		pack3(d[i],d[i],num[i]);
	  }
	  cout<<dp[cash]<<endl;
    }


  
	return 0;
}
