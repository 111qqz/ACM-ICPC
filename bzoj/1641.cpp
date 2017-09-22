/* ***********************************************
Author :111qqz
Created Time :2016年04月09日 星期六 20时39分07秒
File Name :code/bzoj/1641.cpp
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
const int N=305;
int n;
int dp[N][N];
int m,t;
int main()
{

	cin>>n>>m>>t;
	//scanf("%d %d %d",&n,&m,&t);
	ms(dp,0x3f);
//	cout<<dp[0][0]<<endl;
	for ( int i = 1 ; i <= m ; i++)
	{
	    int u,v,w;
	    cin>>u>>v>>w;
	   // scanf("%d %d %d",&u,&v,&w);
	    dp[u][v] = min(dp[u][v],w);
	}

	for ( int k = 1 ; k <= n ; k++)
	    for ( int i = 1 ; i <= n ; i++)
		for ( int j = 1 ; j <= n ; j++)
		    dp[i][j] = min(dp[i][j],max(dp[i][k],dp[k][j]));

	while (t--)
	{
	    int u,v;
	    cin>>u>>v;
	   // scanf("%d %d",&u,&v);
	    if (dp[u][v]==inf)  dp[u][v] = -1;
	    cout<<dp[u][v]<<endl;
	   // printf("%d\n",dp[u][v]);
	}
//  #ifndef ONLINE_JUDGE  
//  fclose(stdin);
//  #endif
    return 0;
}
