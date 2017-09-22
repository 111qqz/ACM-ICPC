/* ***********************************************
Author :111qqz
Created Time :2016年06月24日 星期五 16时50分51秒
File Name :code/hdoj/1532.cpp
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
int n,m;
int flow[N][N];
int ans;
bool vis[N];
int pre[N]; //记录增广路。

void max_flow()
{
    while (1)
    {
	ms(pre,0);
	ms(vis,false);
	queue<int>q;
	q.push(1);
	vis[1] = true;
	while (!q.empty())
	{
	    int cur = q.front(); q.pop();
	    if (cur==n) //说明找到增广路
		 break;

	    for ( int i = 1 ; i <= n ; i++)
	    {
		if (flow[cur][i]>0&&!vis[i])
		{
		    vis[i] = true;
		    q.push(i);
		    pre[i] = cur;
		}
	    }
	}

	if (!vis[n]) break; //没有找到增广路。。。说明当前已经是最大流。。。。
	
	int minf = inf;
	for ( int i = n ; i != 1 ; i = pre[i])
	{
	    minf = min(minf,flow[pre[i]][i]);
	}

	for ( int i = n ; i != 1 ; i = pre[i])
	{
	    flow[pre[i]][i] -= minf;
	    flow[i][pre[i]] += minf;
	}

	ans += minf;

    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%d%d",&m,&n))
	{
	    
	    ms(flow,0);
	    for ( int i = 1 ; i <= m ; i++)
	    {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		flow[u][v] += w; //有重边
	    }

	    ans  = 0;
	    max_flow();

	    printf("%d\n",ans);
	}
	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}

