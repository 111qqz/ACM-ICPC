/* ***********************************************
Author :111qqz
Created Time :2016年04月12日 星期二 19时39分38秒
File Name :code/hdu/2586.cpp
************************************************ */
#pragma comment(linker, "/STACK:1024000000,1024000000") 
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
const int N = 4E4+7;
int n,q;
vector < pi > edge[N];
vector < pi >query[N];
bool vis[N];
int f[N];
int ans[N];
int dis[N];
void init()
{
    for ( int i = 1 ; i <= n ; i++) edge[i].clear();
    for ( int i = 1 ; i <= q ; i++) query[i].clear();
    ms(vis,false);
    for ( int i = 1 ; i <= n ; i++) f[i] = i ;
    ms(ans,0);
    ms(dis,0);
}

int root ( int x)
{
    if (x!=f[x]) f[x]=root(f[x]);
    return f[x];
}

void merge(int x,int y)
{
    int rx = root (x);
    int ry = root (y);
    if (rx!=ry)
    {
	f[ry] = rx;
    }

}


void tarjan( int u,int val)
{
    vis[u] = true;
    dis[u] = val;
    int siz = edge[u].size();
    for ( int i = 0 ; i < siz ; i++)
    {
	int v = edge[u][i].fst;
	if (vis[v]) continue;
	tarjan(v,val+edge[u][i].sec);
	merge(u,v);
    }
    siz = query[u].size();
    for ( int i = 0 ; i < siz ; i++)
    {
	int v = query[u][i].fst;
	int id = query[u][i].sec;
	if (!vis[v]) continue;
	ans[id] = dis[u] + dis[v] -2*dis[root(v)];
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
	    cin>>n>>q;
	    init();
	    for ( int i = 1 ; i <= n-1 ; i++)
	    {
		int u,v,w;
		cin>>u>>v>>w;
		edge[u].push_back(make_pair(v,w));
		edge[v].push_back(make_pair(u,w));
	    }

	    for ( int i = 1 ; i <= q ; i++)
	    {
		int u,v;
		cin>>u>>v;
		query[u].push_back(make_pair(v,i));
		query[v].push_back(make_pair(u,i));
	    }

	    tarjan(1,0);

	    for ( int i = 1 ;i <= q ; i++) cout<<ans[i]<<endl;



	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
