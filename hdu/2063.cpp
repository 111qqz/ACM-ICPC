/* ***********************************************
Author :111qqz
Created Time :2016年05月25日 星期三 16时51分32秒
File Name :code/hdu/2063.cpp
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
int n,m,k;
int head[N];
int link[N];
bool vis[N];
int cnt;
int tot;
struct Edge
{
    int to;
    int nxt;
}edge[N];
void addedge( int u,int v)
{
    edge[cnt].to = v;
    edge[cnt].nxt = head[u];
    head[u] = cnt;
    cnt++;
}

bool dfs(int u)
{
 //   cout<<"u:"<<u<<endl;
    for ( int i = head[u] ; i!=-1 ; i = edge[i].nxt)
    {
	int v = edge[i].to;
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
int hung(int n)
{
    int ans = 0 ;
    ms(link,-1);
   // cout<<"asdsad"<<endl;
    for ( int i = 1 ; i <= n ; i++)
    {
	ms(vis,false);
//	cout<<"sadsad"<<endl;
	if (dfs(i)) ans++;
    }
    return ans;
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	
	while (scanf("%d",&k)!=EOF)
	{
	    if (k==0) break;
	    scanf("%d%d",&m,&n);
	    ms(head,-1);
	    cnt = 0 ;
//	    cout<<"k:"<<k<<endl;
	    for ( int i = 1 ; i <= k ; i++)
	    {
		int u,v;
		scanf("%d%d",&u,&v);
		v = v + m; //调整编号，男生编号在女生之后。
		addedge(u,v);
//		cout<<"sadasdasdasd"<<endl;
	    }
	    int ans = hung(m);
	    printf("%d\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
