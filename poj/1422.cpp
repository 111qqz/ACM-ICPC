/* ***********************************************
Author :111qqz
Created Time :2016年05月26日 星期四 20时46分29秒
File Name :code/poj/1422.cpp
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
const int N=125;
int n,m;
int head[N];
int cnt;
int link[N];
bool vis[N];
struct  Edge
{
    int v;
    int nxt;
}edge[N*N*2];

void addedge(int u,int v)
{
    edge[cnt].v = v;
    edge[cnt].nxt = head[u];
    head[u] = cnt;
    cnt++;
}

bool dfs( int u)
{
    for ( int i = head[u] ; i!=-1 ; i = edge[i].nxt )
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
    ms(link,-1);
    int res = 0 ;
    for ( int i = 1 ; i <= n ; i++)
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

	int T;
	scanf("%d",&T);
	while (T--)
	{
	    scanf("%d %d",&n,&m);
	    cnt = 0 ;
	    ms(head,-1);

	    for ( int i = 1 ; i <= m ; i++)
	    {
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
	    }

	    int  ans = n-hungary();
	    printf("%d\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
