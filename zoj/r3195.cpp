/* ***********************************************
Author :111qqz
Created Time :2016年05月21日 星期六 14时44分39秒
File Name :code/zoj/3195.cpp
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
const int N=1E5+7;
vector< pi > edge[2*N];
int E[2*N],R[2*N],depth[2*N];
int dp[2*N][20];
int dis[N];
int p;
int n,q;
void dfs(int u,int dep,int d,int pre)
{

   // cout<<"u:"<<u<<" dep:"<<dep<<" d:"<<d<<" pre:"<<pre<<endl;
    p++;
    E[p] = u;
    depth[p] = dep;
    dis[u] = d;

    R[u] = p;

    int siz = edge[u].size();
    for ( int i = 0 ; i < siz ; i++)
    {
	int v = edge[u][i].fst;
	if (v==pre) continue;
	dfs(v,dep+1,d+edge[u][i].sec,u);

	p++;
	E[p] =  u;
	depth[p] = dep;
    }

}

int _min(int l,int r)
{
    if (depth[l]<depth[r]) return l;
    return r;
}
void rmq_init(int n)
{

  //  for ( int i = 1 ; i <= n ; i++) if (R[E[i]]==0) R[E[i]] = i; //for what?
    for ( int i = 1 ; i <= n ; i++) dp[i][0] = i;

    for ( int j = 1 ; (1<<j) <= n ; j++)
	for ( int i = 1 ; i + (1<<j)-1 <= n ; i++)
	    dp[i][j] = _min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}

int rmq_min(int l,int r)
{
    if (l>r) swap(l,r);

    int k = 0 ;
    while (1<<(k+1)<=r-l+1) k++;
    return _min(dp[l][k],dp[r-(1<<k)+1][k]);
}
int mindis( int x,int y)
{
    int LCA = E[rmq_min(R[x],R[y])];
    int res=dis[x]+dis[y]-2*dis[LCA];
  //  cout<<"res:"<<res<<endl;
    return res;
}

void init()
{
    for ( int i = 0 ; i <= n ; i++) edge[i].clear();
    ms(E,0);
    ms(R,0);
    ms(dp,0);
    ms(depth,0);
    ms(dis,0);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("code/in.txt","r",stdin);
  #endif
	bool fst = true;
	while (scanf("%d",&n)!=EOF)
	{
	    if (!fst) printf("\n");
	    fst = false;
	    init();
	    for ( int i = 1 ; i <= n-1; i++)
	    {
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
	//	u++;
	//	v++;
		edge[u].push_back(make_pair(v,w));
		edge[v].push_back(make_pair(u,w));
	    }

	    dfs(0,0,0,-1);
	    rmq_init(2*n+2);


	    scanf("%d",&q);
	 //   cout<<"q:"<<q<<endl;
	    while (q--)
	    {
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
	//	x++;y++;z++;

		int ans = mindis(x,y)+mindis(y,z)+mindis(x,z);
		ans/=2;
		printf("%d\n",ans);
	    }



	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
