/*************************************************************************
	> File Name: code/2015summer/0716/I.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月16日 星期四 11时09分50秒
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
int cash,n,sum,num[N],d[N],dp[N],a[N];
void pack(int cost,int value)
{
    for ( int i = cash ; i >=cost ; i--)
	  dp[i]=max(dp[i],dp[i-cost]+value);
}
int main()
{
 
    while (scanf("%d %d",&cash,&n)!=EOF)
    {
	  memset(dp,0,sizeof(dp));
	   sum = 0;
	   int k=1;
	  for ( int i = 1 ; i <= n ; i++)
	  {
		scanf("%d %d",&num[i],&d[i]);
		if (num[i]==0) continue;
		for ( int j = k ; j < k+num[i];j++)
		{
		    sum++;
		    a[j] = d[i];
//		    cout<<j<<"  "<<d[j]<<endl;
		}
		k = k + num[i];
	  }
	//  for ( int i = 1 ; i <= sum ;i++)
	//	cout<<"d[i]:"<<d[i]<<endl;
//	  cout<<"sum:"<<sum<<endl;
	  for ( int i = 1 ; i <= sum ; i++ )
		pack(a[i],a[i]);
	  cout<<dp[cash]<<endl;

    }
	return 0;
}
