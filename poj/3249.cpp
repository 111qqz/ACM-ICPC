/* ***********************************************
Author :111qqz
Created Time :2017年11月07日 星期二 13时52分27秒
File Name :3249.cpp
************************************************ */

#include <iostream>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
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
const int N=1E5+7;
vector <int>edge[N];
int in[N],out[N];
int n,m;
int dp[N];
int val[N];
void init()
{
    for ( int i = 0 ; i < N ; i++) edge[i].clear();
    ms(in,0);
    ms(out,0);
    ms(dp,0xca);
 //   cout<<"dp:"<<dp[1]<<endl;
}
void topo()
{
    queue<int>Q;
    for ( int i = 1 ; i <= n ; i++)
	if (in[i]==0) Q.push(i),dp[i] = val[i];

    while (!Q.empty())
    {
	int cur = Q.front();
//	cout<<"cur:"<<cur<<endl;
	Q.pop();
	int siz = edge[cur].size();
	for ( int i = 0 ; i < siz ; i++)
	{
	    int v = edge[cur][i];
	    dp[v] = max(dp[v],dp[cur]+val[v]);
	    in[v]--;
	    if (in[v]==0) Q.push(v);
	}
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	while (~scanf("%d %d",&n,&m))
	{
	    init();
	    for ( int i = 1 ; i <= n ; i++) scanf("%d",&val[i]);
	    while (m--)
	    {
		int x,y;
		scanf("%d %d",&x,&y);
//		cout<<"x:"<<x<<" y:"<<y<<endl;
		edge[x].PB(y);
		out[x]++;
		in[y]++;
	    }
	    topo();
	    int ans = -inf;
	    for ( int i = 1 ; i <= n ; i++) if (!out[i]&&dp[i]>ans) ans = dp[i];
	    printf("%d\n",ans);
	}



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
