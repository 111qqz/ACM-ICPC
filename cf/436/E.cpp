/* ***********************************************
Author :111qqz
Created Time :2017年10月25日 星期三 13时30分17秒
File Name :E.cpp
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
#define PB push_back
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
const int M=2E5+7;
int t[N],d[N],p[N];
int dp[M]; 
int n;
void solve(int cost,int limit,int value)
{
    for ( int i = limit ; i >= cost ; i--)
	dp[i] = max(dp[i],dp[i-cost]+value);
}

struct node
{
    int t,d,p;
    bool operator < (node b)
    {
	return d<b.d;
    }
}a[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif 
	cin>>n;
	for ( int i = 1 ; i <= n ; i++) cin>>a[i].t>>a[i].d>>a[i].p;
	sort(a+1,a+n+1);
	ms(dp,0);
	
	int cur = 0 ;
	for ( int i = 1 ; i <= n ; i++)
	{
	    cur+=a[i].d;
	    solve(a[i].t,cur,a[i].p);
	}
	int ans = 0 ;
	for ( int i =  0 ; i <= cur ; i++) ans = max(ans,dp[i]);
	cout<<ans<<endl;
	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
