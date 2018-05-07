/* ***********************************************
Author :111qqz
mail: hust.111qqz@gmail.com
Created Time :Mon 07 May 2018 02:30:33 PM EDT
File Name :E.cpp
************************************************ */

#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;
const int N=2E5+7;
vector<int>edge[N];
int n,m;
int deg[N];
bool vis[N];
vector<int>vec;
void dfs( int x )
{
	vec.push_back(x);
	vis[x] = true;
	for ( auto y : edge[x])
	{
		if (!vis[y]) dfs(y);
	}
}

int main()
{
//	freopen("./in.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	ms(deg,0);
	for  ( int i = 0 ; i < m ; i++)
	{
		int u,v;
		cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	
	ms(vis,false);
	int ans = 0 ;
	for ( int i = 1 ; i <= n ; i++)
	{
		vec.clear();
		if (!vis[i]){
			dfs(i);
			bool die = false;
			for ( auto x : vec)
			{
				if (deg[x]!=2) die = true;
			}
			if (!die) ans++;
		}
	}
	cout<<ans<<endl;
		
    return 0;
}
