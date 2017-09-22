/* ***********************************************
Author :111qqz
Created Time :2016年05月20日 星期五 19时31分44秒
File Name :code/hdu/2874.cpp
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
const int N=2E4+7;
int n,m,q;
vector < pi > edge[N];
int dis[N];
int E[2*N],depth[2*N],R[2*N];
int p;
int dp[2*N][20];
int f[N];
/*int root2 ( int a)
{
    int x = a,ret;
    while (x!=f[x]) x = f[x];
    ret = x;
    while (a!=ret)
    {
	x = a;
	a = f[a];
	f[x] = ret;
    }
    return ret;
}  */
int root( int x)
{
    if (f[x]!=x) f[x] = root (f[x]);
    return f[x];
}
void merge( int x,int y)
{
    int rx = root(x);
    int ry = root(y);
    if (rx==ry) return ;
    if (rx<ry) f[ry] = rx;
    else f[rx]=ry;
}
void dfs( int u,int dep,int d,int pre)
{
  //  cout<<"u:"<<u<<" dep:"<<dep<<" d:"<<d<<" pre:"<<pre<<endl;
    p++;
    E[p] = u ;
    depth[p] = dep;
    dis[u] = d;

     R[u] = p;

    int siz = edge[u].size();
    for ( int i = 0 ; i < siz ; i++)
    {
	int v = edge[u][i].fst;
	if (v==pre) continue;
	dfs(v,dep+1,d+edge[u][i].sec,u);

	p++;
	E[p] =  u;
	depth[p] = dep;
    }
}

int _min(int l,int r)
{
    if (depth[l]<depth[r]) return l;
    return r;
}
void rmq_init( int n)
{
    for ( int i = 1 ; i <= n ; i++) dp[i][0] = i;

    for ( int j = 1 ; (1<<j) <= n ; j++)
	for ( int i = 1 ; i + (1<<j)-1 <= n ; i++)
	    dp[i][j] = _min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}

int rmq_min(int l,int r)
{
    if (l>r) swap(l,r);
  //  cout<<"l:"<<l<<" r:"<<r<<endl;
    int k = 0 ;
    while (1<<(k+1) <=r-l+1) k++;

    return _min(dp[l][k],dp[r-(1<<k)+1][k]);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (scanf("%d %d %d",&n,&m,&q)!=EOF)
	{
	    ms(dp,0);
	    ms(E,0);
	    ms(R,0);
	    ms(depth,0);
	    ms(dis,0);
	    for ( int i = 0 ; i <= n ; i++) edge[i].clear();
	    for ( int i = 0 ; i <= n ; i++) f[i]  =  i;
	    for ( int i  =1 ; i <= m ; i++)
	    {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		if (u>v) swap(u,v);
		edge[u].push_back(make_pair(v,w));
		edge[v].push_back(make_pair(u,w));

		merge(u,v);
	    }
	    

	    for ( int i = 1 ; i  <= n ; i++)
	    {
		if (i==f[i])   //添加虚点0，把每棵树的根连边到虚点0上。
		{
		    edge[0].push_back(make_pair(i,0));
		    edge[i].push_back(make_pair(0,0));
		}
	    }

	  //  cout<<"asd"<<endl;
	    p = 0 ;
	    dfs(0,0,0,-1);
	    rmq_init(2*n+2);
	    while (q--)
	    {
		int u,v;
		scanf("%d %d",&u,&v);
	//	cout<<u<<" "<<v<<" R[u]:"<<R[u]<<" R[v]:"<<R[v]<<endl;
		int LCA = E[rmq_min(R[u],R[v])]; 
//		cout<<"LCA:"<<LCA<<endl;
		if (LCA==0)
		{
		    puts("Not connected");
		    continue;
		}
		int ans = dis[u]+dis[v]-2*dis[LCA];
		printf("%d\n",ans);
	    }
	}
	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
