/*************************************************************************
	> File Name: code/2015summer/0713A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月13日 星期一 22时55分27秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int N=2E5+7;
const int inf=0x7fffffff;
struct edge
{
    int to,w;
    
};
vector<edge> adjmap[N];
int d[N];
bool  vis[N];
int cnt[N];
int n,m;
void spfa()
{
    queue<int> q;
    int i;
    for ( int i = 2 ; i <=2*n ; i++ )
	  d[i] = inf ;
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    d[1] = 0;
    vis[1] = true;
    cnt[1]++;
    q.push(1);
    int top;
    while (!q.empty())
    {
	  top = q.front();
	  q.pop();
	  vis[top] = false;
	  for (i = 0 ; i<adjmap[top].size();i++)
	  {
		int to=adjmap[top][i].to;
		if (top<inf&&d[to]>d[top]+adjmap[top][i].w)
		{
		    d[to] = d[top]+adjmap[top][i].w;
		    if (!vis[to])
		    {
			  vis[to]=true;
			  cnt[to]++;
			  if (cnt[to]>=n) return ;
			  q.push(to);
		    }
		}
	  }
    }
    cout<<d[2*n]*1.0/2<<endl;
}
int main()
{
     int T;
     cin>>T;
     while (T--)
     {
	   scanf("%d %d",&n,&m);
	   int i;
	   int s,e,w;
	   edge tmp;
	   for ( int i = 1 ; i <=2*n ; i++)
	   {
		 adjmap[i].clear();
	   }
	   for ( int i = 1 ; i <= m ; i++)
	   {
		 scanf("%d%d%d",&s,&e,&w);
		 tmp.to = e;
		 tmp .w = w*2;
		 adjmap[s].push_back(tmp);
		 tmp.to=e+n;
		 tmp.w = w*2;
		 adjmap[s+n].push_back(tmp);
		 tmp.to=e+n;
		 tmp.w=w;
		 adjmap[s].push_back(tmp);

	   }
	   spfa();
     } 
    
	return 0;
}
