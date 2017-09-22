/* ***********************************************
Author :111qqz
Created Time :2016年12月01日 星期四 09时03分08秒
File Name :code/hdu/r2196.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define fst first
#define sec second
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;
#define pi pair < int ,int >
#define MP make_pair

using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=1E4+7;
int n;
vector < pi > edge[N];
int dp[3][N]; 
//dp[0][i]:从节点i出发第一步向下走能达到的最远距离。
//,dp[1][i]：从节点i出发第一步向下走，能达到的次远距离（要求与最远距离的路径不相交）
//dp[2][i]:从节点i出发第一步向上走，能达到的最远距离。
void dfs( int u,int pre)
{
    for ( auto x : edge[u])
    {
	int v = x.fst;
	int w = x.sec;
	if (v==pre) continue;
	dfs(v,u);
	if (w+dp[0][v]>dp[0][u])
	{
	    dp[1][u] = dp[0][u];
	    dp[0][u] = w + dp[0][v];
	}else if (w + dp[0][v]>dp[1][u]) 
		dp[1][u] = w + dp[0][v];
    }
}
void dfs2( int u,int pre)
{
  //  cout<<"u:"<<u<<" pre:"<<pre<<endl;
    for ( auto x : edge[u])
    {
	int v = x.fst;
	int w = x.sec;
//	cout<<"v:"<<v<<" pre"<<pre<<endl;
	if (v == pre) continue;
	if (w + dp[0][v]==dp[0][u])
	    dp[2][v] = max(dp[2][v],dp[1][u] + w);
	else dp[2][v] = max(dp[2][v],dp[0][u] + w);
	dp[2][v] = max(dp[2][v],dp[2][u] + w);
	dfs2(v,u); //调用成了dfs，调试了半天。。。智力－２
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%d",&n))
	{
	    ms(dp,0);
	    for ( int i = 1 ; i<= n ; i++) edge[i].clear();
	    for ( int i = 2 ;i  <= n ; i++)
	    {
		int u,v,w;
		u = i ;
		scanf("%d %d",&v,&w);
		edge[u].push_back(MP(v,w));
		edge[v].push_back(MP(u,w));
		
	    }

	    dfs(1,-1);
	    //for ( int i = 1 ;i <= n ; i++) printf("%d ",dp[2][i]);
	   // printf("\n");
	    dfs2(1,-1);
	    for ( int i = 1 ; i <= n ; i++) printf("%d\n",max(dp[0][i],dp[2][i]));
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
