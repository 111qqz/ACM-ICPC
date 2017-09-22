/* ***********************************************
Author :111qqz
Created Time :2016年05月23日 星期一 20时31分19秒
File Name :code/poj/1511.cpp
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
const int N=1E7+7;
LL d[N];
bool inq[N];
int n,m;
struct Edge
{
    int v,w;
    int nxt;
}edge1[N],edge2[N]; //反向存一次
int head1[N],head2[N];
int cnt;
void addedge(Edge *edge,int *head,int  u,int v,int w)
{
    edge[cnt].v = v;
    edge[cnt].w = w;
    edge[cnt].nxt = head[u];
    head[u] = cnt;
    cnt++;
}

int spfa(Edge *edge,int *head)
{

    ms(inq,false);
    for ( int i = 0 ; i <= n ; i++) d[i] = 1E18;
    queue<int>q;
    q.push(1);
    d[1] = 0 ;
    inq[1] = true;

    while (!q.empty())
    {
	int u = q.front();
	q.pop();
	inq[u] = false;

	for ( int i = head[u]; i !=-1 ;i=edge[i].nxt)
	{
	    int v = edge[i].v;
	    int w = edge[i].w;

	    if (d[v]>d[u]+w)
	    {
		d[v] = d[u] + w;
		if (inq[v]) continue;
		inq[v] = true;
		q.push(v);
	    }
	}

//	cout<<"sadsad"<<endl;

    }
    LL res = 0 ;
    for ( int i = 2 ; i <= n ; i++) res +=d[i];
  //  cout<<"res:"<<res<<endl;
  //
  
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

//	ios::sync_with_stdio(false);
	int T;
	scanf("%d",&T);
	while (T--)
	{
	    scanf("%d%d",&n,&m);
	    cnt = 0;
	    ms(head1,-1);
	    ms(head2,-1); //忘记初始化，智力-2
	    for ( int i = 1 ; i <= m ; i++)
	    {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(edge1,head1,u,v,w);
		addedge(edge2,head2,v,u,w);
		
	    }
	 //   cout<<"sadasdadsasd"<<endl;

	    LL ans = 0 ;
	    ans = spfa(edge1,head1)+spfa(edge2,head2);
	    printf("%lld\n",ans);
	    
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
