/* ***********************************************
Author :111qqz
Created Time :Fri 14 Oct 2016 05:47:50 PM CST
File Name :code/sy15/M.cpp
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
const int M=2E6+7;
const int N=1E5+7;
struct Edge
{
    int v;
    LL w;
    int nxt;
}edge[M];
int n,m;
LL d1[M],d2[M];
int cnt;
int head[M];
bool inq[M];
void addedge(int u,int v,LL w)
{
    edge[cnt].v = v;
    edge[cnt].w = w;
    edge[cnt].nxt = head[u];
    head[u] = cnt;
    cnt++;
}
void spfa( int s,LL *d)
{
    ms(inq,false);
    for ( int i = 1 ; i <= n+m ; i++) d[i] = 1E18;
    queue<int>q;
    q.push(s);
    inq[s] = true;
    d[s] = 0 ;
    while (!q.empty())
    {
	int u = q.front();
//	cout<<"u:"<<u<<endl;
	q.pop();
	inq[u] = false;
	for ( int i = head[u] ; i !=-1 ; i = edge[i].nxt)
	{
	    int v = edge[i].v;
//	    cout<<"v:"<<v<<endl;
	    LL w = edge[i].w;
	    if (d[v]>d[u]+w)
	    {
		d[v] = d[u] + w;
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

	int T;
	cin>>T;
	int cas = 0 ;
	while (T--)
	{
	    ms(head,-1);
	    scanf("%d %d",&n,&m);
	    cnt = 0 ;
	    for ( int i = 1 ; i <= m ; i++)
	    {
		int x;
		LL w;
		scanf("%lld%d",&w,&x);
		while (x--)
		{
		    int y;
		    scanf("%d",&y);
		    int u = i+n;
		    int v = y;
		    addedge(u,v,0LL);
		    addedge(v,u,w);
		}
	    }
	    spfa(1,d1);
	    spfa(n,d2);
//	    for ( int i = 1 ; i <= n+m ; i++) printf(" %lld",d2[i]);

	    if (d1[n]==1E18)
	    {
		printf("Case #%d: Evil John\n",++cas);
		continue;
	    }
//	    cout<<"222"<<endl;
	    LL mn = 1E18;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		LL tmp = max(d1[i],d2[i]);
//		cout<<"tmp:"<<tmp<<endl;
		if (tmp<mn) mn = tmp;
	    }
	    vector<int>ans;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		LL tmp = max(d1[i],d2[i]);
		if (tmp==mn) ans.push_back(i);
	    }
	    printf("Case #%d: %lld\n",++cas,mn);
	    int siz = ans.size();
	    for ( int i = 0 ; i < siz-1 ; i++) printf("%d ",ans[i]);
	    printf("%d\n",ans[siz-1]);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}

