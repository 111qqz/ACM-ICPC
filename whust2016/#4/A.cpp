/* ***********************************************
Author :111qqz
Created Time :2016年08月13日 星期六 16时58分59秒
File Name :code/whust2016/#4/A.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <deque>
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
const int N=5E3+7;
int l,r,n,m;
vector <int>edge[N];
int in[N];
int vis[N];
int d[N];
int cnt[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%d%d%d%d",&l,&r,&n,&m))
	{
	    for ( int i = 1 ; i <= n ; i++) edge[i].clear();
	    ms(in,0);
	    ms(vis,0);
	    ms(d,0);
	    for ( int i = 1 ; i <= m ; i++)
	    {
		int u,v;
		scanf("%d %d",&u,&v);
		u++;
		v++;
		edge[u].push_back(v);
		in[v]++;
	    }

	    queue<int>q;
	    for ( int i = 1 ; i <= n ;  i++)
		if (in[i]==0)
		{
		    q.push(i);
		    cout<<"i:"<<i<<endl;
		    d[i] = 1;
		    vis[i] = 1;
		}

	    while (!q.empty())
	    {
		int u  = q.front(); q.pop();
		int siz =  edge[u].size();
		for ( int i = 0 ; i < siz ; i++)
		{
		    int v = edge[u][i];
		    if (vis[v]+1>in[v]) continue;
		    vis[v]++;
		    d[v] = d[v] + d[u] + 1;
		    q.push(v);
		}
	    }

	    for ( int i = 1 ; i <= n ; i++) d[i] = d[i]-vis[i]+1;
	    for ( int i = 1 ; i <= n ; i++) cout<<"i:"<<i-1<<" d[i]:"<<d[i]<<endl;
	    int ans1,ans2,ans3;
	    ans1=ans2=ans3=0;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		if (d[i]<=l)
		{
		    ans1++;
		    continue;
		}
		if (d[i]<=r)
		{
		    ans2++;
		    continue;
		
		}
		if (d[i]>r)
		{
		    ans3++;
		}
	    }
	    printf("%d\n%d\n%d\n",ans1,ans2,ans3);




	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
