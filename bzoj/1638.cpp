/* ***********************************************
Author :111qqz
Created Time :2016年04月08日 星期五 15时06分38秒
File Name :code/bzoj/1638.cpp
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
const int N=5005;
int cnt[N][N];
bool vis[N];
int n,m;
int in[N];
vector < int > edge[N];
int p[N];
int ans;


void dfs( int x)
{
    if (x==n) return;
    vis[x] = true;
    for ( int i = 0 ; i < int(edge[x].size()) ; i++)
    {
	int v = edge[x][i];
	if (v>x)
	{
	    cnt[x][v]++;
	    dfs(v);
	}
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	cin>>n>>m;
	ms(in,0);
	ms(cnt,0);
	for ( int i = 1 ;i  <= m ; i++ )
	{
	    int u,v;
	    cin>>u>>v;
	    edge[u].push_back(v);
	    in[v]++;
	}

	int num = 0 ;
	for ( int i = 1 ;i  <= n ; i++)
	{
	    if (in[i]==0)
	    {
		p[++num] = i;
	    }
	}

	for ( int i = 1 ; i <= num ; i++)
	{

	    ms(vis,false);
	    dfs(p[i]);
	}

	ans = -1;
	for ( int i = 1; i <= n ; i++)
	    for ( int j = 1 ; j <= n ; j++) ans = max(ans,cnt[i][j]);


	cout<<ans<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
