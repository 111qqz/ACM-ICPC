/* ***********************************************
Author :111qqz
Created Time :2016年04月01日 星期五 13时03分19秒
File Name :code/bzoj/1609.cpp
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
const int N=3E4+7;
int a[N];
int dp[N];
int g[N];
int n;
int solve ()
{
    ms(g,0x3f);
    int res = 0 ;
    for ( int i = 1 ; i <= n ; i++)
    {
	int k = upper_bound(g+1,g+n+1,a[i])-g;
	dp[i] = k;
	g[k] = a[i];
	res = max(res,dp[i]);
    }
    return n - res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ios::sync_with_stdio(false);
	cin>>n;
	for ( int i = 1 ; i <= n ; i++) cin>>a[i];
	int ans = inf ;
	ans = min(ans,solve());
	reverse(a+1,a+n+1);
	ans = min (ans,solve());
	cout<<ans<<endl;

	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
