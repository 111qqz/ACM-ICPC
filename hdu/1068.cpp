/* ***********************************************
Author :111qqz
Created Time :2016年05月28日 星期六 08时42分19秒
File Name :code/hdu/1068.cpp
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
int n;
int head[N];
//vector <int>edge[N];
int link[N];
bool vis[N];

int cnt;
struct Edge
{
    int v;
    int nxt;
}edge[10005];

void addedge( int u,int v)
{
    edge[cnt].v = v;
    edge[cnt].nxt = head[u];
    head[u] = cnt;
    cnt++;
}
/*int find( int u)
{
    int siz = edge[u].size();
    for ( int i = 0 ; i < siz ; i++)
    {
	int v = edge[u][i];
	if (vis[v]) continue;
	vis[v] = true;
	
	if (link[v]==-1||find(link[v]))
	{
	    link[v] = u ;
	    return true;
	}
    }

    return false;
}  */

int dfs ( int u)
{
    for ( int i = head[u] ; i !=-1 ; i = edge[i].nxt)
    {
	int v = edge[i].v;
	if (vis[v]) continue;
	vis[v] = true;

	if (link[v]==-1||dfs(link[v]))
	{
	    link[v] = u ;
	    return true;
	}
    }
    return false;
}
int hungary()
{
    ms(link,-1);
    
    int res = 0 ;
    for ( int i = 1 ; i <= n ; i++)
    {
	ms(vis,false);
	if (dfs(i)) res++;
    }
    return res/2;
}
 
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (scanf("%d",&n)!=EOF)
	{
	    
	    cnt = 0 ;
	    ms(head,-1);

//	    for ( int i = 1 ; i <= n ; i++) edge[i].clear();
	    for ( int i = 1 ; i <= n ; i++)
	    {
		int id,num;
		scanf("%d: (%d)",&id,&num);
	//	cout<<" id :"<<id<<" num:"<<num<<endl;
		id++;
		while (num--)
		{
		    int x;
		    scanf("%d",&x);
		    x++;
	//	    cout<<"x:"<<x<<endl;
		  //  edge[id].push_back(x);
		   addedge(id,x);
		}
	//	cout<<endl;
	    }

	    int ans =  n-hungary();
	    
	  //  for ( int i = 1 ; i <= n ; i++) cout<<i<<" "<<link[i]<<endl;
	    printf("%d\n",ans);
	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
