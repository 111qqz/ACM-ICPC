/* ***********************************************
Author :111qqz
Created Time :2016年04月04日 星期一 19时36分38秒
File Name :code/bzoj/1631.cpp
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
const int M=1E5+7;
int n,m,X;

vector < pi > edge[N];
bool inq[N];
int d1[N],d2[N];
int ans;
struct road
{
    int u,v,w;
}r[M];

void spfa( int s,int *d)
{
    queue<int>q;
    q.push(s);
    inq[s] = true;
    d[s] = 0 ;

    while (!q.empty())
    {
	int u = q.front();
	q.pop();
	inq[u] = false;

	int siz  = edge[u].size();

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
    

}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d%d%d",&n,&m,&X);
	for ( int i = 1 ; i <= m ; i++)
	{
	    int x,y,z;
	    scanf("%d%d%d",&x,&y,&z);
	    r[i].u = x;
	    r[i].v = y;
	    r[i].w = z;

	    edge[x].push_back(MP(y,z));  //单向边
	}

	ans = 0 ;
	ms(inq,false);
	ms(d1,0x3f);
	spfa(X,d1);

	for ( int i = 1 ; i <= n ; i++) edge[i].clear(); //重新反向连边再跑一次。

	for ( int i = 1 ; i <= m ; i++)
	{
	    edge[r[i].v].push_back(MP(r[i].u,r[i].w));
	}
	ms(inq,false);
	ms(d2,0x3f);
	spfa(X,d2);

	int ans = -1;
	for ( int i = 1 ; i <= n ; i++) ans = max(ans,d1[i]+d2[i]);

	printf("%d\n",ans);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
