/* ***********************************************
Author :111qqz
Created Time :2016年09月01日 星期四 14时24分36秒
File Name :code/hdu/2444.cpp
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
const int N=205;
int n,m;
vector<int>edge[N];
int col[N];
int link[N];
bool vis[N];
void init()
{
    for ( int i = 0 ; i <= n ; i++) edge[i].clear();
    ms(col,-1);
}
bool dfs( int u,int x)
{
    col[u] = x;
    int siz = edge[u].size();
    for ( int i = 0 ; i < siz;  i++)
    {
	int v = edge[u][i];
	if (col[v]==1-x) continue;
	if (col[v]==x)  return false;
	if (!dfs(v,1-x)) return false;
    }
    return true;
}
bool solve()
{
    for ( int i = 1 ; i <= n ; i++) if (col[i]==-1) if (!dfs(i,0)) return false;
    return  true;
}
bool Find( int u)
{
     int siz = edge[u].size();
     for ( int i = 0 ; i < siz; i ++)
	{
	    int v = edge[u][i];
	    if (vis[v]) continue;
	    vis[v] = true;
	    if (link[v]==-1||Find(link[v]))
	    {
		link[v] = u;
		return true;
	    }
	}
     return false;
}
int hung( int n)
{
    int ans = 0 ;
    ms(link,-1);
    for ( int i = 1 ; i <= n ; i++)
    {
	ms(vis,false);
	if (Find(i)) ans++;
    }
    return ans;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%d %d",&n,&m))
	{
	    init();
	    for ( int i = 1 ; i <= m ; i++)
	    {
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
	    }
	    if (!solve())
	    {
		puts("No");
	    }
	    else
	    {
		int ans = hung(n);
		printf("%d\n",ans);
	    }
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
