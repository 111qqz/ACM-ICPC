/* ***********************************************
Author :111qqz
Created Time :2015年12月05日 星期六 17时13分51秒
File Name :code/cf/problem/445/B.cpp
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
using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=55;
bool vis[N];
int n,m;
vector<int>edge[N];
LL ans;
LL tree_num;
void dfs( int cur)
{

    vis[cur] = true;
    for ( int i = 0 ; i < edge[cur].size();  i++)
    {
	int v = edge[cur][i];
	if (!vis[v])
	{
	    dfs(v);
	}
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d %d",&n,&m);
	ms(vis,false);
	for ( int i = 0 ; i < m ; i++)
	{
	    int u,v;
	    scanf("%d %d",&u,&v);
	    edge[u].push_back(v);
	    edge[v].push_back(u);
	}
	tree_num = 0 ;
	for ( int i = 1 ; i <= n ; i++)
	{
	    if (!vis[i])
	    {
		dfs(i);
		tree_num++;
	    }
	}
	ans = 1;
	ans = (LL)(1)<<(LL(n-tree_num));
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
