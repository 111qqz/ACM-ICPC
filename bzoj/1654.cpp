/* ***********************************************
Author :111qqz
Created Time :2016年04月14日 星期四 15时19分38秒
File Name :code/bzoj/1654.cpp
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
const int N=1E5+7;
vector < int >edge[N];
bool vis[N];
int ans;
int n,m;
bool dfs( int u)
{
    vis[u] = true;
    int siz = edge[u].size();
    for ( int i = 0 ; i < siz ; i++)
    {
	int v = edge[u][i];
	if (!vis[v])
	{
	    dfs(v);
	}
	else
	{
	    return true;
	}
    }
    return false;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d %d",&n,&m);
	for ( int i = 1 ;i <=  m ; i++)
	{
	    int u,v;
	    scanf("%d %d",&u,&v);
	    edge[u].push_back(v);
	    edge[v].push_back(u);
	}

	ms(vis,false);
	ans = 0 ;
	for ( int i = 1 ; i <= n ; i++)
	{
	    if (!vis[i])
	    {
		if (dfs(i)) ans++;
	    }
	}

	printf("%d\n",ans);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
