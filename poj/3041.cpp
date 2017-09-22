/* ***********************************************
Author :111qqz
Created Time :2016年05月30日 星期一 21时42分55秒
File Name :code/poj/3041.cpp
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
const int N=1E3+7;
const int M=1E4+7;
int n,k;
int cnt;
struct Edge
{
    int v;
    int nxt;
}edge[M];

int head[N];
bool vis[N];
int link[N];

void addedge( int u,int v)
{
    edge[cnt].v = v;
    edge[cnt].nxt = head[u];
    head[u] = cnt;
    cnt++;
}
void init()
{
    ms(head,-1);
    cnt = 0 ;
}

int find( int u)
{
    for ( int i = head[u] ; i !=-1 ; i = edge[i].nxt)
    {
	int v = edge[i].v;
	if (vis[v]) continue;
	vis[v] = true;
	if (link[v]==-1||find(link[v]))
	{
	    link[v] = u;
	    return true;
	}
    }
    return false;
}
int hungary()
{
    int res = 0 ;
    ms(link,-1);
    for ( int i = 1 ; i <= n ; i ++)
    {
	ms(vis,false);
	if (find(i)) res++;
    }
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	init();
	scanf("%d%d",&n,&k);
	for ( int i = 1 ; i <= k ; i++)
	{
	    int u,v;
	    scanf("%d%d",&u,&v);
	    addedge(u,v+n);
	}
	int ans = hungary();
	printf("%d\n",ans);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
