/* ***********************************************
Author :111qqz
Created Time :2016年05月26日 星期四 19时28分05秒
File Name :code/poj/2594.cpp
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
const int N=5005;
struct Edge
{
    int v;
    int nxt;
}edge[5005];

int head[N];
int link[N];
int n,m;
int cnt;
bool vis[N];
bool le[N];
int tot;
bool conc[505][505];
void addedge( int u,int v)
{
    edge[cnt].v = v;
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
int hung()
{
    int res = 0 ;
    ms(link,-1);

    for ( int i = 1 ; i <= n ; i++)
    {
	if (!le[i]) continue;
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

	while (scanf("%d%d",&n,&m)!=EOF)
	{
	    if (n==0&&m==0) break;
	    cnt = 0 ;
	    ms(head,-1);
	    ms(edge,0);
	    ms(conc,false);
	    ms(le,false);
	    tot = 0 ;
	    for ( int i = 0  ; i < m ; i++)
	    {
		int u,v;
		scanf("%d%d",&u,&v);
		if (conc[u][v]) continue;
		addedge(u,v);
		le[u] = true; 
		conc[u][v] = true;
		
	    }

	    int ans = hung();
	    printf("%d\n",n-ans);
	}



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
