/* ***********************************************
Author :111qqz
Created Time :2017年10月12日 星期四 17时06分57秒
File Name :G.cpp
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
#define PB push_back
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
int n,q;
int val[N];
vector < int > edge[N];
int in[N];
int E[2*N],R[2*N],dis[N],depth[2*N];
int p;
int fa[N];
int dp[2*N][20];
int siz[N]; //siz[i]表示以i为根的子树的叶子数量。
int FA[N]; //将树根去掉之后，每棵子树最上面能到达的顶点。
set<int>T[N];//T[i]表示与根节点直接连接的节点i 切掉的点的dfs序 id
int a[N];
void dfs( int u,int dep,int d,int pre)
{
    fa[u] = pre;
    p++;
    E[p] = u;
    depth[p] = dep;
    R[u] = p;
    dis[u] = d;
    int SIZ = edge[u].size();
    if (SIZ==0) siz[u] = 1;
    for ( int i = 0 ; i < SIZ ; i++)
    {
	int v = edge[u][i];
	if (v==pre) continue;
	if (u==1) FA[v] = v; //把树根去掉，原树分裂乘若干个子树
	else FA[v] = FA[u];

	dfs(v,dep+1,d+1,u);
	siz[u] += siz[v];
	p++;
	E[p] = u;
	depth[p] = dep;
    }
}
int _min( int l,int r)
{
    if (depth[l] < depth[r]) return l;
    return r;
}
void rmq_init()
{
    for ( int i = 1 ; i <= 2*n+2 ; i++) dp[i][0] = i;
    
    for ( int j = 1 ; (1<<j) <= 2*n+2 ; j++)
	for ( int i = 1 ; i + (1<<j)-1 <= 2*n+2 ; i++)
	    dp[i][j] = _min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
int rmq_min(int l,int r)
{
    if (l>r) swap(l,r);
    int k = 0 ;
    while (1<<(k+1)<=r-l+1) k++;
    return _min(dp[l][k],dp[r-(1<<k)+1][k]);
}
int ans1=0,ans2=0;
int main()
{
	#ifndef  ONLINE_JUDGE 
	//freopen("./in.txt","r",stdin);
	
  #endif
	freopen("gangsters.in","r",stdin);
	freopen("gangsters.out","w",stdout);
	ms(a,0);
	ms(siz,0);
	scanf("%d %d",&n,&q);
	for ( int i = 2 ; i <= n ; i++)
	{
	    int x;
	    scanf("%d",&x);
	  //  cout<<"x:"<<x<<endl;
	    edge[x].PB(i);
	}
	p = 0;
	dfs(1,0,0,-1);
	rmq_init();
	while (q--)
	{
	    char opt[3];
	    int x;
	    scanf("%s%d",opt,&x);
	   // cout<<opt<<" "<<x<<endl;
	    if (opt[0]=='+')
	    {
		int fx = FA[x];
		if (T[fx].size()==0) ++ans1;
		T[fx].insert(R[x]);
		ans2-=a[fx];//因为切掉了，先去掉之前的影响
		
		int fi = *T[fx].begin();
		int la = *T[fx].rbegin(); 
		int LCA = E[rmq_min(fi,la)]; //尽量往低了切，才可能影响小。
	//	printf( "(LCA(%d %d)=%d,siz[LCA]=%d \n",R[fi],R[la],LCA,siz[LCA]);
		a[fx] = siz[LCA] - T[fx].size();
	    
		ans2 += a[fx];//再考虑新的影响
	//	cout<<"ans2:"<<ans2<<endl;
	    }
	    else
	    {
		int fx = FA[x];
		if (T[fx].size()==1) ans1--;
		T[fx].erase(R[x]);
		ans2-=a[fx];
		if (T[fx].size()!=0)
		{
		    int fi = *T[fx].begin();
		    int la = *T[fx].rbegin();
		    int LCA = E[rmq_min(fi,la)];
		    a[fx] = siz[LCA] - T[fx].size();
	//	    printf( "(LCA(%d %d)=%d\n",R[fi],R[la],LCA);
		}
		else a[fx] = 0;

		ans2 +=a[fx];
	    }
	    printf("%d %d\n",ans1,ans2);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
