/* ***********************************************
Author :111qqz
Created Time :2016年03月31日 星期四 20时27分01秒
File Name :code/bzoj/1602.cpp
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
const int N=1E3+5;
int n,q;
vector< pi >edge[N];
bool vis[N];
int d[N];

struct node
{
    int x;
    int d;
    
    bool operator < (node b)const
    {
	return d>b.d;
    }
};

int bfs( int s,int t)
{
    queue<node>q;
    ms(vis,false);
    node tmp;
    tmp.x = s;
    tmp.d = 0 ;
    q.push(tmp);
    vis[s] = true;
    while (!q.empty())
    {
	node pre = q.front();q.pop();
	if (pre.x==t) return pre.d;
	for ( int i = 0 ; i < int(edge[pre.x].size()) ; i++)
	{
	    node nxt;
	    nxt.x= edge[pre.x][i].fst;
	    nxt.d = pre.d + edge[pre.x][i].sec;
	    if (!vis[nxt.x])
	    {

		q.push(nxt);
		vis[nxt.x] = true;
	    }
	}
    }
    return -1;

}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	cin>>n>>q;
	for ( int i = 1 ; i <= n-1 ; i++)
	{
	    int u,v,w;
	    cin>>u>>v>>w;
	    edge[u].push_back(make_pair(v,w));
	    edge[v].push_back(make_pair(u,w));
	}

	while (q--)
	{
	    int s,t;
	    cin>>s>>t;
	    int ans = bfs(s,t);
	    cout<<ans<<endl;
	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
