/* ***********************************************
Author :111qqz
Created Time :2016年03月19日 星期六 09时57分45秒
File Name :code/cf/croc2016/D.cpp
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
const int N=1E5+7;
vector< pi >edge[N];
vector< int > topo;
int n ,m;
bool vis[N];
void dfs( int u)
{
    vis[u] = true;

    for (  int i =  0 ; i < edge[u].size() ; i++)
    {
	int v = edge[u][i].first;
	if (!vis[v]) dfs(v);
    }

    topo.push_back(u);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	cin>>n>>m;
	for ( int i = 1 ; i <= m ; i++)
	{
	    int u,v;
	    cin>>u>>v;
	    edge[u].push_back(MP(v,i));
	}
	ms(vis,false);
	
	for ( int i = 1 ; i <= n ; i++)
	{
	    if (!vis[i])
		dfs(i);
	}

	int ans = 0  ;
	reverse(topo.begin(),topo.end());
	for ( int i = 1 ; i < topo.size() ; i++)
	{
	    int u = topo[i-1];
	    int v = topo[i];
	    int cur = -1;
	    for ( int j =  0 ; j < edge[u].size() ; j ++)
	    {
		if (edge[u][j].fst==v)
		{
		    cur = edge[u][j].sec;
		    break;
		}
	    }
	    if (cur==-1)
	    {
		puts("-1");
		return 0;
	    }

	    ans = max(ans,cur);
	}

	cout<<ans<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
