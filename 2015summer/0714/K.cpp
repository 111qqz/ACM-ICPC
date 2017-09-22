/*************************************************************************
	> File Name: code/2015summer/0714/K.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月16日 星期四 01时03分01秒
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
const int N=20;
int n,t;
int a[N];
int ans;
int k;
int rec[N];
bool vis[105];
bool ok;
void dfs(int x,int sum,int k)
{
    if (sum==t)
    {
	  ok=true;
	  for ( int i = 0 ; i < k ; i++)
	  {
		if (i)
		{
		    printf("+%d",rec[i]);
		}
		else
		{
		    printf("%d",rec[i]);
		}
	  }
	  printf("\n");
	  return;
    }
    int pre = -1;
    for ( int i = x ; i < n ; i++)
    {
	  if (sum+a[i]<=t&&a[i]!=pre)
	  {
		pre = a[i];
		rec[k] = a[i];
		dfs(i+1,sum+a[i],k+1);
	  }
    }
}
int main()
{
    while (scanf("%d %d",&t,&n)!=EOF&&n)
    {
	   ok = false;
	  memset(vis,false,sizeof(vis));
	  ans  = 0 ;
	  k = 0;
	  for ( int i = 0 ; i < n ; i++)
		scanf("%d",&a[i]);
	  printf("Sums of %d:\n",t);
	  dfs(0,0,0);
	  if (!ok) printf("NONE\n");
    }
  
	return 0;
}
