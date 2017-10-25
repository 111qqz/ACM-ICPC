/* ***********************************************
Author :111qqz
Created Time :2017年10月24日 星期二 21时14分51秒
File Name :A_dfs.cpp
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
const int N=101;
const int M=10001;
int mon,n,m1,m2,t1,t2,ans=-1;
int h1[N],h2[N],vis[N],dis[N],f[N];
struct edge {int len,w,to,ne;}e1[M],e2[M];
void add1( int x,int y,int z,int t)
{
    e1[++t1].to = y;e1[t1].ne = h1[x];
    h1[x] = t1;e1[t1].len=z;e1[t1].w = t;
}
void add2( int x,int y,int z,int t)
{
    e2[++t2].to = y; e2[t1].ne = h2[x];
    h2[x] = t2; e2[t2].len = z; e2[t2].w = t2;
}
void dij()
{
    int i,j,k,mx;
    for ( i = 1 ; i <= n ; i++) dis[i] =1E8+5;
    dis[n] = 0;
    for ( i = 1 ; i <= n ; i++)
    {
    	k = 0,mx=1E8+5;
	 for ( j = 1 ; j <= n ; j++)
		if (!vis[j]&&dis[j]<mx) mx = dis[j],k=j;
	    if (!k) break; vis[k] = 1;
	for (j=h2[k];j!=-1;j=e2[j].ne)
	    if (e2[j].w + dis[k] < dis[e2[j].to])
	     dis[e2[j].to] = e2[j].w + dis[k];
    }
}

void dfs( int x,int cost ,int num)
{
    if (ans!=-1&&num>=ans) return;
    if (mon-cost<dis[x]) return;
    if (num>=f[x]) return;
    f[x] = num;
    if (x==n)
    {
	ans = num;
	return;
    }
    for ( int i = h1[x] ; i!=-1 ; i=e1[i].ne)
	if (!vis[e1[i].to])
	{
	    vis[e1[i].to] = 1;
	    dfs(e1[i].to,cost+e1[i].w,num+e1[i].len);
	    vis[e1[i].to] = 0;
	}
}

void init()
{
    ms(h1,-1);
    ms(h2,-1);
}
int  main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	int T;
	scanf("%d",&T);
	while (T--)
	{
	    init();
	    scanf("%d %d %d %d",&n,&m1,&m2,&mon);
	    while (m1--)
	    {
		int a,b;
		scanf("%d %d",&a,&b);
		add1(a,b,0,1);
		add1(b,a,0,1);
		add2(b,a,0,1);
		add2(a,b,0,1);
	    }
	    while (m2--)
	    {
		int x,y,len;
		scanf("%d%d%d",&x,&y,&len);
		add1(x,y,len,len);
		add1(y,x,len,len);
		add2(y,x,len,len);
		add2(x,y,len,len);
	    }
	    dij();
	    for ( int i = 1 ;  i <= n ; i++) vis[i] = 0, f[i]=1E8+5;
	    vis[1] = 1;
	    dfs(1,0,0);
	    printf("%d\n",ans);
	}
		
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
