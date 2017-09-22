/* ***********************************************
Author :111qqz
Created Time :2016年05月19日 星期四 15时44分12秒
File Name :code/poj/1470.cpp
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
const int N=905;
int n;
vector <int> edge[N];
int in[N];
int E[2*N],R[2*N];
int depth[2*N];
int p;
int dp[2*N][12];
int cnt[N];
void dfs( int u,int dep)
{
    p++;
    E[p] = u ;
    depth[p] =  dep;
    R[u] = p;
    int siz = edge[u].size();
    for ( int i = 0 ; i < siz ; i ++)
    {
	int v  = edge[u][i];

	dfs(v,dep+1);
	p++;
	E[p] =  u;
	depth[p] = dep;
    }
}

int _min( int l,int r)
{
    if (depth[l]<depth[r]) return l;
    return r;
}
void rmq_init()
{
    for ( int i = 1 ; i <=2*n+2 ; i++) dp[i][0] =  i;

    for ( int j = 1 ; (1<<j) <= 2*n+2 ; j++)
	for ( int i = 1 ; i + (1<<j)-1 <= 2*n+2 ; i++)
	    dp[i][j] = _min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}

int rmq_min( int l,int r)
{
    if (l>r) swap(l,r);
    int k = 0;
    while (1<<(k+1) <= r-l+1) k++;
    return _min(dp[l][k],dp[r-(1<<k)+1][k]);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	
	while (scanf("%d",&n)!=EOF)
	{
	    ms(in,0);
	    for ( int i = 1 ; i <= n ; i++) edge[i].clear();
	    for ( int i = 1 ; i <= n ; i++)
	    {
		char ch[5];
		int x,num;
		scanf("%d%2s%d%1s",&x,ch,&num,ch);
//		cout<<"x:"<<x<<" num:"<<num<<endl;
		
		for ( int i = 1 ; i <= num ; i++)
		{
		    int y;
		    scanf("%d",&y);
		    edge[x].push_back(y);
		    in[y]++;
//		    cout<<"y:"<<y<<endl;
		}
	    }

	    int root ;
	    for ( int i = 1 ; i <= n ; i++) if (in[i]==0) root = i ;
//	    cout<<"root:"<<root<<endl;
	    p = 0;
	    dfs(root,0);
	    rmq_init();

	    ms(cnt,0);

	    int q;
	    scanf("%d",&q);
//	    cout<<"q:"<<q<<endl;
	    while (q--)
	    {
		char ch[5];
		int x,y;
		scanf("%1s%d%d%1s",ch,&x,&y,ch);
		int LCA = E[rmq_min(R[x],R[y])];
//		cout<<"x:"<<x<<" y:"<<y<<" LCA:"<<LCA<<endl;
		cnt[LCA]++;
	    }
//	    cout<<"n:"<<n<<endl;
	    for ( int i = 1 ; i <= n ; i++)
	    {
//		cout<<"cnt[i]:"<<cnt[i]<<endl;
		if (cnt[i]==0) continue;
		printf("%d:%d\n",i,cnt[i]);
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
