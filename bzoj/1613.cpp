/* ***********************************************
Author :111qqz
Created Time :2016年04月02日 星期六 16时08分47秒
File Name :code/bzoj/1613.cpp
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
const int N=1E4+7;
int n;
int M;
int d[N];
int mx;  //mx[i]表示到i分钟开始的时候疲劳度最多为多少
int dp[N][505];
void print()
{
    for ( int i = 0 ;  i <= n ; i++)
    {
	int mx = n-i;
	mx = min(i,mx);
	for ( int j = 0 ; j <= mx ; j++)
	{
	    cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
	}
	cout<<endl;
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	cin>>n>>M;
	for ( int i = 1 ; i <= n  ; i++) cin>>d[i];
	ms(dp,0);
	for ( int i = 1 ; i <= n ; i++)
	{
	    dp[i][0] = dp[i-1][0];
	    for ( int j = 1 ; j <= M ; j++)
	    {
		if (i>=j)
		dp[i][0] = max(dp[i][0],dp[i-j][j]);  //从第i-j天连续休息j天到第i天疲劳度为0
		dp[i][j] = max(dp[i][j],dp[i-1][j-1]+d[i]);
	    }
	}
//	print();
	cout<<dp[n][0]<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
