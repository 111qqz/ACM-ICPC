/* ***********************************************
Author :111qqz
Created Time :2016年02月25日 星期四 18时22分15秒
File Name :code/bzoj/1606.cpp
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
const int N=5E3+7;
int v[N];
int c;
int n;
int dp[N*10];

void solve( int val,int cost)
{
    for ( int v = c ; v >= cost ; v--)
	dp[v] = max(dp[v],dp[v-cost]+val);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>c>>n;
	ms(dp,0);
	for ( int i = 0 ; i < n ; i++) cin>>v[i];

	for ( int i = 0 ; i < n ; i++)
	    solve(v[i],v[i]);

	cout<<dp[c]<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
