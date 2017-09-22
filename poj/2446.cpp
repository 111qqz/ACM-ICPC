/* ***********************************************
Author :111qqz
Created Time :2016年05月25日 星期三 20时19分04秒
File Name :code/poj/2446.cpp
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
const int N = 40;
int n,m,k;
bool hole[N][N];
int f1[N][N],f2[N][N];
int tot1,tot2;
int head[N*N*2];
int cnt;
bool vis[N*N*2];
int link[N*N*2];
struct Edge
{
    int v;
    int nxt;
}edge[2*N*N];
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
    ms(link,-1);
    int res = 0;
    for ( int i = 1 ; i <= tot1 ; i++)
    {
	ms(vis,false);
	if (dfs(i)) res++;
    }

    return res; //无相边/2,一对匹配占两个格子，×2，抵消了。。

}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	scanf("%d%d%d",&n,&m,&k);
	ms(hole,false);
	ms(head,-1);
	for ( int i = 1 ; i <= k ; i++)
	{
	    int x,y;
	    scanf("%d%d",&x,&y);
	    swap(x,y);
	    hole[x][y] = true;
	}
	
	if ((n*m-k)%2==1)
	{
	    puts("NO");
	    return 0;
	}
	tot1 =  tot2 = 0 ;                       //根据奇偶性划分集合。
	for ( int i = 1 ; i <= n ; i++)
	    for ( int j = 1 ; j <= m ; j++)
		if (!hole[i][j])
		{
		    if ((i+j)%2==0)
		    {
			f1[i][j]=++tot1;
		    }
		    else
		    {
			f2[i][j]=++tot2;
		    }
		}
	
	cnt = 0 ;
	for ( int i = 1 ; i <= n ; i++)
	    for ( int j = 1 ; j <= m ; j++)
	    {
		if (!hole[i][j]&&j+1<=m&&!hole[i][j+1])
		{
		    int u = (i+j)%2==0?f1[i][j]:f2[i][j];
		    int v = (i+j+1)%2==0?f1[i][j+1]:f2[i][j+1];
		    if ((i+j)%2==1) swap(u,v);
		    addedge(u,v);  // 保证是f1的点连向f2的点。
		  //  addedge(v,u);
		}
		if (!hole[i][j]&&i+1<=n&&!hole[i+1][j])
		{
		    int u = (i+j)%2==0?f1[i][j]:f2[i][j];
		    int v = (i+j+1)%2==0?f1[i+1][j]:f2[i+1][j];
		    if ((i+j)%2==1) swap(u,v); 
		    addedge(u,v);  //无向图
		  //  addedge(v,u);
		}
	    }

	int ans = hung();
//	cout<<"ans:"<<ans<<endl;
	if (ans*2+k==m*n)
	{
	    puts("YES");
	}
	else
	{
	    puts("NO");
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
