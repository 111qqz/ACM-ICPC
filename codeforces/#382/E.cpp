/* ***********************************************
Author :111qqz
Created Time :2016年12月07日 星期三 02时10分34秒
File Name :code/cf/#382/E.cpp
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
const int MOD = 1E9+7;
const int N=105;
int n,k,ans,f[N][50],g[50];
vector<int>edge[N];
int F( int x)
{
    return x+k;
}
int Add(LL x,LL y)
{
    return (x+y)%MOD;
}
int Mul(LL x,LL y)
{
    return x*y%MOD;
}
void dfs( int u,int pre)
{
    f[u][F(-k)]=f[u][F(1)] = 1;
    for ( auto v:edge[u])
    {
	if (v==pre) continue;
	dfs(v,u);
	ms(g,0);
	for ( int i = -k ; i <= k ; i++)
	{
	    if (!f[u][F(i)]) continue;
	    for ( int j = -k ; j <= k ; j++)
	    {
		int t = Mul(f[u][F(i)],f[v][F(j)]);
		if (i<=0&&j<=0)
		{
		    int A = min(i,j+1);
		    g[F(A)] = Add(g[F(A)],t);
		}else if (i>0&&j>0)
		{
		    int A = max(i,j+1);
		    g[F(A)] = Add(g[F(A)],t);
		}else if (i<=0&&j>0)
		{
		    int A = (-i>=j)?i:j+1;
		    g[F(A)] = Add(g[F(A)],t);
		}else if (i>0&&j<=0)
		{
		    int A = (-j>=i)?j+1:i;
		    g[F(A)] = Add(g[F(A)],t);
		}
	    }
	}
	memcpy(f[u],g,sizeof(g));
    }
}
int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
#endif
    cin>>n>>k;
    for ( int i = 1; i < n ; i++)
    {
	int x,y;
	scanf("%d%d",&x,&y);
	edge[x].push_back(y);
	edge[y].push_back(x);
    }
    dfs(1,-1);
    for (int i =  0 ;i  <= k ; i++)
	ans = (ans + f[1][i])%MOD;
    cout<<ans<<endl;
#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
