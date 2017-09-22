/* ***********************************************
Author :111qqz
Created Time :2016年06月24日 星期五 14时58分14秒
File Name :code/poj/3342.cpp
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
const int N=205;
string boss;
map<string,int>mp;
int cnt;
int dp[N][2];
bool uni;
int n;
vector<int>edge[N];
void dfs( int u,int pre)
{
   cout<<"u:"<<u<<" pre:"<<pre<<endl; 
    int siz = edge[u].size();
    for ( int i = 0 ; i < siz ; i++)
    {
	int v = edge[u][i];
	if (v==pre) continue;
	dfs(v,u);


	if (dp[u][0]>dp[u][1])
	{
	    if (dp[v][1]==dp[v][0]) uni = false;
	}

	dp[u][1] += dp[v][0];
	dp[u][0] += max(dp[v][1],dp[v][0]);
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%d",&n)&&n!=0)
	{
	    
	    for ( int i = 1 ; i <= n ; i++) edge[i].clear();
	    cnt = 0 ;
	    mp.clear();
	    ms(dp,0);
	    uni = true;

	    for ( int i = 1 ;i <= n ; i++) dp[i][1] = 1;
	    cin>>boss;
	    mp[boss]=++cnt;

	    for ( int i = 1 ; i <= n-1 ; i++)
	    {
		string u,v;
		cin>>u>>v;
		if (!mp[u]) mp[u] = ++cnt;
		if (!mp[v]) mp[v] = ++cnt;

		int x = mp[u];
		int y = mp[v];

		edge[y].push_back(x);
	    }

	    dfs(mp[boss],-1);
	    int ans = max(dp[mp[boss]][0],dp[mp[boss]][1]);
	    
	    printf("%d ",ans);
	    if (uni)
	    {
		puts("Yes");
	    }
	    else
	    {
		puts("No");
	    }

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
