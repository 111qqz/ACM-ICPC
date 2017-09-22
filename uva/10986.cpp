/* ***********************************************
Author :111qqz
Created Time :2016年05月25日 星期三 03时25分27秒
File Name :code/uva/10986.cpp
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
const int N=2E4+7;
int n,m;
int S,T;
vector < pi > edge[N];

int d[N];
bool inq[N];
bool spfa( int s,int t)
{
    ms(d,0x3f);
    ms(inq,false);
    queue<int>q;
    q.push(s);
    inq[s] = true;
    d[s] = 0;

    while (!q.empty())
    {
	int u = q.front();
	q.pop();
	inq[u] = false;

	int siz = edge[u].size();

	for ( int i = 0 ; i < siz ; i++)
	{
	    int v = edge[u][i].fst;
	    if (d[v]>d[u] + edge[u][i].sec)
	    {
		d[v] = d[u] + edge[u][i].sec;
		if (inq[v]) continue;
		inq[v] = true;
		q.push(v);
	    }
	}
    }
    return d[t]!=inf;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ios::sync_with_stdio(false);
	int TT;
	cin>>TT;
	int cas = 0 ;
	while (TT--)
	{
	    cin>>n>>m>>S>>T;
	    for ( int i = 0 ; i <= n ; i++) edge[i].clear();
	    for ( int i = 1 ; i <= m ; i++)
	    {
		int u,v,w;
		cin>>u>>v>>w;
		edge[u].push_back(make_pair(v,w));
		edge[v].push_back(make_pair(u,w));
	    }
	
	    if (spfa(S,T))
	    {
		printf("Case #%d: %d\n",++cas,d[T]);
	    }
	    else
	    {
		printf("Case #%d: unreachable\n",++cas);
	    }

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
