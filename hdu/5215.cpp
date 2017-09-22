/* ***********************************************
Author :111qqz
Created Time :2016年09月01日 星期四 14时47分32秒
File Name :code/hdu/5215.cpp
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
#define sec secon
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
const int M=3E5+7;
int n,m;
int col[N];
bool even,odd;
bool vis[N];
int cnt ;
int head[N];
struct Edge
{
    int v;
    int nxt;
    bool vis;
}edge[2*M];  
void addedge( int u,int v)
{
    edge[cnt].v = v;
    edge[cnt].nxt = head[u];
    edge[cnt].vis = false;
    head[u] = cnt;
    cnt++;
}
void dfs( int u,int x,int fa)
{
    col[u] = x;
    for ( int i = head[u] ; i !=-1 ; i = edge[i].nxt)
    {
	int v = edge[i].v;
	if (v==fa) continue;
	if (col[v]!=-1)
	{
	    if (col[v]==x) odd = true;
	    else even = true;
	}
	if (!edge[i].vis)
	{
	    edge[i].vis = true;
	    dfs(v,1-x,u);
	}
    }
    col[u] = -1;
}
void solve()
{
    odd = false;
    even = false;
    for ( int i = 1 ; i <= n ; i++){
	if (col[i]==-1) dfs(i,0,-1);
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%d%d",&n,&m);
	    ms(col,-1);
	    ms(head,-1);
	    cnt = 0 ;
	    for ( int i = 1 ;i <= m ; i++)
	    {
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	    }
	    solve();
	    if (odd) puts("YES");else puts("NO");
	    if (even) puts("YES");else  puts("NO");
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
