/* ***********************************************
Author :111qqz
Created Time :2016年11月24日 星期四 09时17分48秒
File Name :code/cf/#381/D.cpp
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
const int N=2E5+7;
int n;
int a[N];
LL dis[N];
vector< pair<int,LL> >edge[N];
vector< pair<LL,int> >path;
int ans[N];
void dfs( int u,int pre)
{
    ans[u]++;
    int idx = lower_bound(path.begin(),path.end(),make_pair(dis[u]-a[u],-1))-path.begin()-1;
    if (idx>=0) ans[path[idx].sec]--;
    path.push_back(make_pair(dis[u],u));
    for ( auto x : edge[u])
    {
	int v  = x.first;
	if (v==pre) continue;
	dis[v] = dis[u] + x.sec;
	dfs(v,u);
	ans[u]+=ans[v];//后序遍历...链的起点原理根，终点靠近根
    }
    path.pop_back();
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	ms(dis,0);
	for ( int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);
	for ( int i =2 ; i <= n ; i++)
	{
	    int u,v;
	    LL w;
	    u = i ;
	    scanf("%d%lld",&v,&w);
	    edge[u].push_back(make_pair(v,w));
	    edge[v].push_back(make_pair(u,w));
	}
	dfs(1,0);
	for ( int i = 1 ; i <= n ; i++) printf("%d ",ans[i]-1);
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
