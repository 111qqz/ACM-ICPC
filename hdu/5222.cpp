/* ***********************************************
Author :111qqz
Created Time :2016年09月02日 星期五 12时50分58秒
File Name :code/hdu/5222.cpp
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
const int M=4E6+7;
const int N=1E6+7;
int n,m1,m2;
int cnt;
int col[N];
struct edge
{
    int v;
    int nxt;
    bool vis;
}edge[M];

int head[N];
bool ok;
void addedge( int u,int v)
{
    edge[cnt].v=  v;
    edge[cnt].nxt = head[u];
    edge[cnt].vis = false;
    head[u] = cnt;
    cnt++;
}
void dfs( int u,int x,int fa)
{
    col[u] = x;
   // cout<<"u:"<<u<<" fa:"<<fa<<endl;
    for ( int i = head[u] ; i !=-1 ; i = edge[i].nxt)
    {
	int v = edge[i].v;
	printf("%d->%d\n",u,v);
//	if (v==fa) continue; //因为两点之间可能有重边，所以反向是可以的。
	if (col[v]!=-1)
	{
	    ok = true;
	    return;
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
    ok = false;
    for ( int i = 1 ; i <= n ; i++) if (col[i]==-1) dfs(i,0,-1);
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
	    scanf("%d%d%d",&n,&m1,&m2);
	    cnt = 0 ;
	    ms(head,-1);
	    ms(col,-1);

	    for ( int i = 1 ; i <= m1;  i++)
	    {
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	    }
	    for ( int i = 1 ; i <= m2 ; i++)
	    {
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
	    }
	    solve();
	    if (ok) puts("YES");else puts("NO");
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
