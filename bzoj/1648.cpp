/* ***********************************************
Author :111qqz
Created Time :2016年04月11日 星期一 15时45分34秒
File Name :code/bzoj/1648.cpp
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
int n,m,k;

vector <int> edge[N];
bool vis[N];

int cow[105];
int num;
int cnt[N];
void dfs(int x)
{
    vis[x] = true;
    cnt[x]++;
    for ( int i = 0 ; i < (int)edge[x].size() ; i++)
    {
	int v = edge[x][i];
	if (!vis[v])
	{
	    dfs(v);
	}
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d %d %d",&k,&n,&m);
	for ( int i = 1 ;i  <= k ; i++)
	{
	    scanf("%d",&cow[i]);
	}
	for ( int i = 1 ; i <= m ; i++)
	{

	    int u,v;
	    scanf("%d %d",&u,&v);
	    edge[u].push_back(v);
	}
	
	ms(cnt,0);
	for (  int i = 1 ; i <= k ; i++)
	{
	    ms(vis,false);
	    dfs(cow[i]);
	}

	int ans = 0 ;
	for  ( int i = 1 ; i <= n ; i++) if (cnt[i]==k) ans++;  //不需要知道到底是哪个牛，只需要个数。
	printf("%d\n",ans);
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
