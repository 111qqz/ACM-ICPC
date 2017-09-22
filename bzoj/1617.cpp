/* ***********************************************
Author :111qqz
Created Time :2016年04月03日 星期日 16时17分03秒
File Name :code/bzoj/1617.cpp
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
const int N=2503;
int t[N];
int sum[N];
int n,m,T;
int dp[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n>>m;
	sum[0] = m ;   //sum[i]表示把i头奶牛运到对岸去的话费（初始sum[0]=m是因为算了自己）
	for ( int i = 1 ;i  <= n ; i++)
	{
	    cin>>t[i];
	    sum[i] = sum[i-1] + t[i];
	}

//	for ( int i = 1 ; i <= n ; i++) cout<<sum[i]<<endl;
	ms(dp,0x3f);
	dp[0] = 0 ;
	for ( int i = 1 ; i <= n ; i++)
	{
	    for ( int j = 1 ; j <= i ; j++)
	    {
		dp[i] = min(dp[i],dp[i-j]+sum[j]+m);
	    }
	}

	cout<<dp[n]-m<<endl;




  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
