/* ***********************************************
Author :111qqz
Created Time :2017年10月25日 星期三 20时57分54秒
File Name :E.cpp
************************************************ */

#include <bits/stdc++.h>
#define PB push_back
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
const int N = 1E5+7;
vector <int>edge[N];
bool vis[N];

bool dfs( int u,int pre)
{
    vis[u] = true;
 //   cout<<"u:"<<u<<" pre:"<<pre<<endl;
    int siz = edge[u].size();
    for ( int i = 0 ; i < siz ; i++)
    {
	int v  =  edge[u][i];
	if (v==pre) continue; //无向边
	if (vis[v]||dfs(v,u)) return true;
    }
    return false;
}
int n,m;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif

	ms(vis,false);
	cin>>n>>m;
	while (m--)
	{
	    int x,y;
	    scanf("%d %d",&x,&y);
	    edge[x].PB(y);
	    edge[y].PB(x);
	}

	int ans = 0 ;
	for ( int i = 1 ; i <= n  ; i++)
	    if (!dfs(i,-1)) ans++;

	cout<<ans<<endl;



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
