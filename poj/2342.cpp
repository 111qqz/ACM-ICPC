/* ***********************************************
Author :111qqz
Created Time :2016年06月24日 星期五 13时07分51秒
File Name :code/poj/2342.cpp
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
const int N=6E3+7;
int n;
int a[N];
int in[N];
vector <int> edge[N];

int dp[N][2];
int root;
void debug()
{
    for ( int i = 1 ; i <= n ; i++)
	printf("%d %d %d\n",i,dp[i][0],dp[i][1]);
}
void dfs ( int u,int pre)
{
    
   // cout<<"u:"<<u<<endl;
    int siz = edge[u].size();
    for ( int i = 0 ; i < siz ; i ++)
    {
	int v = edge[u][i];
	if (v==pre) continue;
	
		
	dfs(v,u);
	dp[u][0] +=max(dp[v][0],dp[v][1]);  //如果父节点没选，那么当前节点可以有两种选择。	
	dp[u][1] +=dp[v][0];              //如果父亲节点选了，那么当前节点只能不选。

	
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	
	ms(dp,0);
	ms(in,0);
	scanf("%d",&n);
	for ( int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);
	
	int u,v;
	while (~scanf("%d%d",&u,&v))
	{
	    if (u==0&&v==0) break;
	    in[u] ++;
	    edge[v].push_back(u);
	}
	for ( int i = 1 ; i <= n; i++) if (in[i]==0) root = i ;
	for ( int i = 1 ; i <= n ; i++) dp[i][1] = a[i];

	dfs(root,-1);
	
	int mx = -inf;
	mx = max(dp[root][0],dp[root][1]);
	debug();
	printf("%d\n",mx);


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
