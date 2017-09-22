/* ***********************************************
Author :111qqz
Created Time :2016年04月14日 星期四 19时33分09秒
File Name :code/bzoj/3407.cpp
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
const int N=5E4+7;
int n,V;
int a[505];
int dp[N];

void solve ( int cost,int val)
{
    for ( int i = V ; i >= cost ; i--)
	dp[i] = max(dp[i],dp[i-cost]+val);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d %d",&V,&n);
	for ( int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);

	ms(dp,0);
	for ( int i = 1 ; i <= n ; i++)
	{
	    solve(a[i],a[i]);
	}

	int ans = 0 ;
	for ( int i = V ; i >= 0 ; i--) ans = max(ans,dp[i]);
	printf("%d\n",ans);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
