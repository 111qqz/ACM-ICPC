/* ***********************************************
Author :111qqz
Created Time :2016年05月25日 星期三 04时20分27秒
File Name :code/cf/problem/449B.cpp
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
#define pi pair < int ,long long>
#define MP make_pair

using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=1E5+7;
int n,m,k;
vector < pi > edge[N];
LL d[N];
bool inq[N];
int cnt[N];
LL tr[N];
int in[N];
struct Edge
{
    int u,v;
    LL w;

    bool operator < (Edge b) const
    {
	if (u==b.u&&v==b.v) return w<b.w;
	if (u==b.u) return v<b.v;
	return u<b.u;
    }
}e[3*N];

void spfa( int s)
{
    ms(inq,false);
    for ( int i = 1 ; i <= n ; i++) d[i] = 1E18;

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

	for ( int i = 0 ; i < siz;  i++)
	{
	    int v = edge[u][i].fst;
	    int w = edge[u][i].sec;
	    if (d[v]>d[u] + w)
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

	ios::sync_with_stdio(false);
	ms(in,0);
	cin>>n>>m>>k;
	ms(cnt,0);
	for ( int i = 1 ; i <= m ; i++)
	{
	    cin>>e[i].u>>e[i].v>>e[i].w;
	    if (e[i].u>e[i].v)  swap(e[i].u,e[i].v);
	}

	sort(e+1,e+m+1);

//	for ( int i = 1 ; i <= m ; i ++) cout<<"e:"<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;

	for  ( int i = 1 ; i <= m ; i++)
	{
	    int u = e[i].u;
	    int v = e[i].v;
	    int w = e[i].w;
	    if (i==1)
	    {
		edge[u].push_back(MP(v,w));
		edge[v].push_back(MP(u,w));
		in[u]++;
		in[v]++;
		continue;
	    }
	    if (u!=e[i-1].u||v!=e[i-1].v)
	    {
		//cout<<"sad"<<endl;
		edge[u].push_back(MP(v,w));
		edge[v].push_back(MP(u,w));
		in[u]++;
		in[v]++;
	    }
	}
	for ( int i = 1 ; i <= n ; i++) d[i] = tr[i] = 1E18;
    //for ( int i = 1 ; i <= 10 ; i++) cout<<tr[i].id<<" "<<tr[i].val<<endl;
	for ( int i = 1 ; i <= k ; i++)
	{
	    int id;
	    LL val;
	    cin>>id>>val;
	    tr[id] = min(tr[id],val);
	}

	spfa(1);
	int ans = 0;
	for ( int i = 1 ; i <= n ;i++)
	{
	    //cout<<i<<" "<<"d[i]:"<<d[i]<<" tr[i]:"<<tr[i]<<endl;
	    if (d[i]<tr[i]) ans++;
	    else if (d[i]==tr[i]&&in[i]>=2) ans++;
	}
	printf("%d\n",ans);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
