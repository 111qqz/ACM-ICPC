/* ***********************************************
Author :111qqz
Created Time :2016年07月14日 星期四 20时11分18秒
File Name :code/hdu/3873.cpp
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
const int N=3005;
int n,m;
LL d[N];
bool inq[N];
int pre[N]; //记录路径
vector < pair<int,LL> > edge[N];
vector <int>prec[N];
void init()
{
    for ( int i = 1 ;i  <= n ; i++) edge[i].clear();
    for ( int i = 1 ; i <= n ; i++) prec[i].clear();
    ms(pre,-1);
}

LL getdis( int u)
{
   if (u!=2) cout<<"u:"<<u<<endl;
    int siz = edge[u].size();

    for ( int i = 0 ; i < siz ; i++)
    {
	int v = edge[u][i].fst;
	d[u] = max(d[u],getdis(v));
    }
    return d[u];

}
void spfa( int s)
{
    ms(d,0x3f);
    ms(inq,false);
    queue<int>q;
    q.push(s);
    inq[s] = true;
    d[s] =  0 ;

    while (!q.empty())
    {
	int u = q.front();
	q.pop();
	inq[u] = false;

	int siz = edge[u].size();
	for ( int i = 0 ; i < siz ; i++)
	{
	    int v = edge[u][i].fst;
	    LL w = edge[u][i].sec;

	    if (d[v]>d[u]+w)
	    {
		d[v] = d[u] + w;
		pre[v] = u;
		if (inq[v]) continue;
		
	    inq[v] = true;
		q.push(v);
	    }
	}
    }
    LL ret = getdis(n);
    printf("%lld\n",ret);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%d%d",&n,&m);
	    init();

	    for ( int i = 1 ;i  <= m ; i ++)
	    {
		int u,v;
		LL w;
		scanf("%d%d%lld",&u,&v,&w);
		edge[u].push_back(make_pair(v,w));
		edge[v].push_back(make_pair(u,w));
	    }

	    for ( int i = 1 ; i <= n ; i++)
	    {
		int x;
		scanf("%d",&x);
		while (x--)
		{
		    int y;
		    scanf("%d",&y);
		    prec[i].push_back(y);
		}
	    }
	    cout<<"aaa"<<endl;
	    spfa(1);
	    cout<<"bbb"<<endl;
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
