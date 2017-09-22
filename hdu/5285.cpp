/* ***********************************************
Author :111qqz
Created Time :2016年09月02日 星期五 14时41分35秒
File Name :code/hdu/5285.cpp
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
const int M = 2E5+7;
const int N = 1E5+7;
int n,m;
int head[N];
int col[N];
struct Edge
{
    int v;
    int nxt;
}edge[M];
int cnt;
int cnt0,cnt1;
void addedge(int u ,int v)
{
    edge[cnt].v = v;
    edge[cnt].nxt = head[u];
    head[u] = cnt;
    cnt++;
}
int dfs( int u,int x,int fa)
{
    col[u] = x;
    if (x==0) cnt0++;else cnt1++;
    for ( int i = head[u] ; i !=-1 ; i = edge[i].nxt)
    {
	int v = edge[i].v;
	if (v==fa) continue;
	if (col[v]==1-x) continue;
	if (col[v]==x) return -1;
	if (!dfs(v,1-x,u)) return -1;
    }
    return max(cnt0,cnt1);
}
int  solve()
{
    int res = 0  ;
    for ( int i = 1 ; i <= n ; i++)
    {
	if (col[i]!=-1) continue;
	cnt0 = cnt1 = 0 ;
	int tmp = dfs(i,0,-1);
	if (tmp==-1) return -1;
	res+=tmp;
    }
    return res;
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
	    cnt = 0 ;
	    ms(head,-1);
	    ms(col,-1);
	    for ( int i = 1 ; i <= m ; i++)
	    {
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	    }
	    if (n<2)
	    {
		puts("Poor wyh");
		continue;
	    }
	    if (m<=1)
	    {
		printf("%d %d\n",n-1,1);
		continue;
	    }
	    int ans = solve();
	    if (ans==-1) puts("Poor wyh");
	    else printf("%d %d\n",ans,n-ans);
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
