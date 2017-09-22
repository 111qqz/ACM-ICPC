/* ***********************************************
Author :111qqz
Created Time :2016年04月03日 星期日 19时40分29秒
File Name :code/bzoj/1618.cpp
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
const int N=105;
int p[N],c[N];
int n;
int V;
int dp[100005];

void solve (int val,int cost)
{
    for ( int i = val ; i <= V ; i++)
	dp[i] = min(dp[i],dp[i-val]+cost);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n>>V;
	//V*=2;
	for  ( int i = 1 ; i <= n ; i++) cin>>p[i]>>c[i];

	ms(dp,0x3f);
	dp[0]=0;
	for ( int i = 1 ; i <= n ; i++) solve(p[i],c[i]);
	cout<<dp[V]<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
