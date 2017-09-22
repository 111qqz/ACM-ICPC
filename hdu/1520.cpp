/* ***********************************************
Author :111qqz
Created Time :2016年11月30日 星期三 20时37分22秒
File Name :code/hdu/1520.cpp
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
int a[N];
int n;
int dp1[N],dp2[N];
vector <int>edge[N];
int in[N];
int root;

void dfs(int u,int pre)
{
    int sum1=0,sum2=0;
    for ( auto v: edge[u])
    {
	if (v==pre) continue;
	dfs(v,u);
	sum1+=dp2[v];
	sum2+=max(dp1[v],dp2[v]);
    }
    dp1[u] = a[u] + sum1;
    dp2[u] = sum2;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%d",&n))
	{
	    ms(in,0);
	    ms(dp1,0);
	    ms(dp2,0);
	    for ( int i = 1 ;i <= n ; i++) edge[i].clear();
	    for ( int i = 1; i <= n ; i++) scanf("%d",&a[i]);
	    int u,v;
	    while (~scanf("%d%d",&u,&v))
	    {
		if (u==0&&v==0) break;
		edge[u].push_back(v);
		edge[v].push_back(u);
		in[u]++;
	    }
	    for ( int i = 1 ; i <= n ; i++)
		if (in[i]==0)
		{
		    root = i;
		    break;
		}

	    dfs(root,-1);
	    int ans = max(dp1[root],dp2[root]);
	    printf("%d\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
