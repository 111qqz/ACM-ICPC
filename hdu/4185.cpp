/* ***********************************************
Author :111qqz
Created Time :2016年05月30日 星期一 12时53分34秒
File Name :code/hdu/4185.cpp
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
const int N=1000;
int n;
char maze[N][N];
int f1[N][N],f2[N][N];
int tot1;
int tot2;
int cnt;
int link[N*N];
bool vis[N*N];
int head[N*N];
struct Edge
{
    int v;
    int nxt;
}edge[N*N*2];

void addedge( int u,int v)
{
    edge[cnt].v = v;
    edge[cnt].nxt = head[u];
    head[u] = cnt;
    cnt++;
}

bool find( int u)
{
    for ( int i = head[u] ; i !=-1 ; i = edge[i].nxt)
    {
	int v = edge[i].v;
	//cout<<"u:"<<u<<" v:"<<v<<endl;
	if (vis[v]) continue;
	vis[v] = true;
	if (link[v]==-1||find(link[v]))
	{
	    link[v] = u;
	    return true;
	}
    }

    return false;
}
int hungary()
{
    ms(link,-1);
    int res =  0;
    for ( int i = 1 ; i <= tot1 ; i++)
    {
	ms(vis,false);
	if (find(i)) res++;
    }
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	int cas = 0 ;
	scanf("%d",&T);
	while (T--)
	{
	    ms(f1,0);
	    ms(f2,0);
	    tot1 = 0 ;
	    tot2 = 0 ;
	    cnt = 0 ;
	    ms(head,-1);

	    scanf("%d",&n);
	    for ( int i = 0 ; i < n ; i++)
		scanf("%s",maze[i]);

	    for ( int i = 0 ; i < n ; i++)
		for ( int j = 0 ; j < n ; j++)
		{
		    if (maze[i][j]=='.') continue;
		    if ((i+j)%2==0)
		    {
			f1[i][j] = ++tot1;	
		    }
		    else
		    {
			f2[i][j] = ++tot2;
		    }

		}

	  //  cout<<"tot1:"<<tot1<<endl;
	  //  cout<<"tot2:"<<tot2<<endl;

	    for ( int i = 0 ;  i < n ; i++)
		for ( int j = 0 ; j < n;  j++)
		{
		    if (j+1<n&&maze[i][j]=='#'&&maze[i][j+1]=='#')
		    {
			int u = (i+j)%2==0?f1[i][j]:f2[i][j];
			int v = (i+j+1)%2==0?f1[i][j+1]:f2[i][j+1];
			if ((i+j)%2==1) swap(u,v);
			v+=tot1;
			addedge(u,v);
		    }
		    if (i+1<n&&maze[i][j]=='#'&&maze[i+1][j]=='#')
		    {
			int u = (i+j)%2==0?f1[i][j]:f2[i][j];
			int v = (i+1+j)%2==0?f1[i+1][j]:f2[i+1][j];
			if ((i+j)%2==1) swap(u,v);
			v+=tot1;
			addedge(u,v);
		    }
		}

		int ans = hungary();
		printf("Case %d: %d\n",++cas,ans);


	}
		

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
