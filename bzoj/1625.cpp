/* ***********************************************
Author :111qqz
Created Time :2016年02月28日 星期日 02时48分06秒
File Name :code/bzoj/1625.cpp
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

const int N=4E3+7;
int w[N],d[N];
int dp[14000];
int n,m;

void solve(int cost,int value)
{
   // cout<<"cost:"<<cost<<" value:"<<value<<endl;
    for ( int v = m ;  v >=cost ; v--)
	dp[v]=max(dp[v],dp[v-cost]+value);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ms(dp,0);
	scanf("%d %d",&n,&m);
	for ( int i = 1; i <= n ; i++) scanf("%d %d",&w[i],&d[i]);
	
	for ( int i  = 1 ; i <= n ; i++)
	{
	    solve(w[i],d[i]);
	}


	int ans = 0;
	for ( int i = 1 ; i <= m ; i++) ans = max(ans,dp[i]);

	printf("%d\n",ans);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
