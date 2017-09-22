/* ***********************************************
Author :111qqz
Created Time :2016年05月26日 星期四 21时41分11秒
File Name :code/poj/1325.cpp
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
const int N=1E3+7;
int n,m,k;
int cnt;
struct Edge
{
    int v;
    int nxt;
}edge[N];


int head[N];
int link[N];
bool vis[N];

void addedge( int u,int v)
{
    edge[cnt] .v = v;
    edge[cnt].nxt = head[u];
    head[u] = cnt;
    cnt++;
}


bool dfs( int u)
{
    for ( int i = head[u] ; i!=-1 ; i = edge[i].nxt)
    {
	int v = edge[i].v;
	if (vis[v]) continue;
	vis[v] = true;

	if (link[v]==-1||dfs(link[v]))
	{
	    link[v] = u;
	    return true;
	}
    }

    return false;
}
int hungary()
{
    int res = 0 ;
    ms(link,-1);

    for ( int i = 1 ; i <= n;  i++)
    {
	ms(vis,false);
	if (dfs(i)) res++;
    }
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (scanf("%d",&n)!=EOF)
	{
	    if (n==0) break;
	    scanf("%d %d",&m,&k);
	    ms(edge,0);
	    cnt = 0 ;
	    ms(head,-1);
	    int ans = 0 ;
	    for ( int i = 1 ; i <= k ; i++)
	    {
		int id,u,v;
		scanf("%d%d%d",&id,&u,&v);
		if (u==0||v==0) continue ;//初始在0，那么只要边的一个端点是0，我们就可以选择在0完成，而不去重启。
		u++;
		v++;

		v = v + n;
		addedge(u,v);
	    }

	    ans = ans+hungary();
	    printf("%d\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
