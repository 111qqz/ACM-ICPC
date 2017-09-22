/* ***********************************************
Author :111qqz
Created Time :2016年05月26日 星期四 20时24分15秒
File Name :code/poj/r2594.cpp
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
const int N=505;
int n,m;
bool conc[N][N];
bool vis[N];
int link[N];
void floyd()
{
    for ( int k = 1 ; k <= n ; k++)
	for ( int i = 1 ; i <= n ; i++)
	    for ( int j = 1 ; j <= n ; j++)
		if (conc[i][k]&&conc[k][j]) conc[i][j] = true; 
}


bool dfs( int u)
{
    for ( int i = 1 ; i <= n ; i++)
    {
	if (conc[u][i])
	{
	    if (vis[i]) continue;
	    vis[i] = true;
	    if (link[i]==-1||dfs(link[i]))
	    {
		link[i] = u;
		return true;
	    }
	}
    }
    return false;
}
int hungary()
{
    int res = 0 ;
    ms(link,-1);
    for ( int i = 1 ; i <= n ; i++)
    {
	ms(vis,false);
	if (dfs(i)) res++;
    }
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	
	while (scanf("%d%d",&n,&m)!=EOF)
	{
	    if (n==0&&m==0) break;
	    ms(conc,false);
	    for ( int i = 1 ; i <= m ; i++)
	    {
		int u,v;
		scanf("%d%d",&u,&v);
		conc[u][v] = true;
	    }

	    floyd();
	    int ans = hungary();
	    printf("%d\n",n-ans);

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
