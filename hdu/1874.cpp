/* ***********************************************
Author :111qqz
Created Time :2016年05月21日 星期六 20时37分14秒
File Name :code/hdu/1874.cpp
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
vector < pi > edge[N];
int n;
int m;
bool inq[N];
int dis[N];
int s,t;

void spfa()
{
    queue<int>q;
    q.push(s);
    inq[s] = true;
    dis[s]  = 0;
    
    while (!q.empty())
    {
	int u = q.front();
	q.pop();
	inq[u] = false;

	int siz = edge[u].size();
	for ( int i = 0 ;  i< siz ; i++)
	{
	    int v = edge[u][i].fst;
	    if(dis[v]>dis[u]+edge[u][i].sec)
	    {
		dis[v] = dis[u] + edge[u][i].sec;
		if (inq[v]) continue;
		inq[v] = true;
		q.push(v);
	    }
	}
    }

    if (dis[t]==inf) puts("-1");
    else printf("%d\n",dis[t]);
}
void init()
{
    for ( int i = 0  ; i <= n ; i++) edge[i].clear();
    ms(inq,false);
    ms(dis,0x3f);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (scanf("%d%d",&n,&m)!=EOF)
	{
	    init();
	    for ( int i = 1 ; i <= m ; i++)
	    {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		edge[u].push_back(MP(v,w));
		edge[v].push_back(MP(u,w));
	    }

	    scanf("%d%d",&s,&t);
	    spfa();

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
