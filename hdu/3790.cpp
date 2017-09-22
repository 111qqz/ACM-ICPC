/* ***********************************************
Author :111qqz
Created Time :2016年05月21日 星期六 18时42分24秒
File Name :code/hdu/3790.cpp
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
int n,m;
int d[N];
int p[N];
bool inq[N];
vector < pair<int,pair<int,int> > > edge[N];

int s,t;

void init()
{
    ms(inq,false);
    ms(d,0x3f);
    ms(p,0x3f);

    for ( int i = 0 ; i <=n ; i++) edge[i].clear();
}

void spfa()
{
    queue<int>q;
    q.push(s);
    d[s] = 0 ;
    p[s] = 0;
    inq[s]=true;
    
    while (!q.empty())
    {
	int now = q.front();
//	cout<<"now:"<<now<<endl;
	q.pop();
	inq[now] = false;
	
	int siz = edge[now].size();
	for ( int i = 0 ; i < siz ; i ++)
	{
	    int v = edge[now][i].fst;
	    int nd = edge[now][i].sec.fst;
	    int nw = edge[now][i].sec.sec;
	//    cout<<"v:"<<v<<" nd:"<<nd<<" nw:"<<nw<<endl;
	    if (d[v]>d[now]+nd||((d[v]==d[now]+nd)&&(p[v]>p[now]+nw)))
	    {
		d[v] = d[now] + nd;
		p[v] = p[now] + nw;

		if (inq[v]) continue;
		q.push(v);
		inq[v] = true;
	    }
	}
    }

}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (scanf("%d%d",&n,&m)!=EOF)
	{
	    if (n==0&&m==0) break;
	    init();
	    for ( int i = 1 ; i <= m ; i++)
	    {
		int u,v,d,w;
		scanf("%d%d%d%d",&u,&v,&d,&w);
		edge[u].push_back(MP(v,MP(d,w)));
		edge[v].push_back(MP(u,MP(d,w)));
	    }

	    scanf("%d%d",&s,&t);


	    spfa();

	    printf("%d %d\n",d[t],p[t]);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
