/* ***********************************************
Author :111qqz
Created Time :2016年05月30日 星期一 20时44分59秒
File Name :code/poj/1719.cpp
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
char maze[N][N];
int head[2*N];
int cnt;
int link[2*N];
int vis[2*N];
pi white[N];
struct Edge
{
    int v;
    int nxt;
}edge[N*2];

void addedge( int u,int v)
{
    edge[cnt].v = v;
    edge[cnt].nxt = head[u];
    head[u] = cnt;
    cnt++;
}
void init()
{
    cnt =  0;
    ms(head,-1);

}


int find( int u)
{
    for ( int i = head[u] ; i!=-1 ; i = edge[i].nxt)
    {
	int v = edge[i].v;
	if (vis[v]) continue;
	vis[v] = true;
	if (link[v]==-1||find(link[v]))
	{
	    link[v] = u ;
	    return true;
	}
    }
    return false;
}
int hungary()
{
    int res = 0 ;
    ms(link,-1);

    for ( int i = 1 ; i <= n ; i++)
    {
	ms(vis,false);
	if (find(i)) res++;
    }
  //  cout<<"res:"<<res<<endl;
    return res;
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
	    init();
	    scanf("%d%d",&n,&m);
	    int tot = 0;
	    for ( int i = 1 ; i <= m ; i++)
	    {
		int x1,x2;
		scanf("%d %d",&x1,&x2);
		white[++tot]=make_pair(x1,x2);

		addedge(x1,i+n);
		addedge(x2,i+n);
	    }

	    int ans = hungary();
	    if (ans<n)
	    {
		puts("NO");
	    }
	    else
	    {
		//for ( int i = n+1 ; i <= n+m ; i++) cout<<"link[i]:"<<link[i]<<endl;
		for ( int i = n+1 ; i <= n+m ; i++)
		{
		    if (link[i]==-1)
		    {
			printf("%d ",white[i-n].fst);
		    }
		    else
		    {
			printf("%d ",link[i]);
		    }
		}
		printf("\n");
	    }

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
