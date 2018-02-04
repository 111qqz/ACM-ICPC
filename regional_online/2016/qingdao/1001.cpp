/* ***********************************************
Author :111qqz
Created Time :Sat 17 Sep 2016 12:28:38 PM CST
File Name :code/net/2016/qingdao/1001.cpp
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
int dp[100005];
int t;
int MIN( int a,int b,int c,int d)
{
    int res = inf;
    res = min(a,b);
    res = min(res,c);
    res = min(res,d);
    return res;
}
void init()
{
    dp[0] = 1;
    t = 1;
    int p1 ,p2,p3,p4;
    p1=p2=p3=p4=0;
    while (dp[t-1]<=1e9)
    {
	dp[t++]=MIN(dp[p1]*2,dp[p2]*3,dp[p3]*5,dp[p4]*7);
	if (dp[t-1]==dp[p1]*2) p1++;
	if (dp[t-1]==dp[p2]*3) p2++;
	if (dp[t-1]==dp[p3]*5) p3++;
	if (dp[t-1]==dp[p4]*7) p4++;
    }
}
int cal( int a,int b,int c,int d)
{
    int res = 1;
    for ( int i = 1 ; i <= a ; i++) res*=2;
    for ( int i = 1 ; i <= b ; i++) res*=3;
    for ( int i = 1 ; i <= c ; i++) res*=5;
    for ( int i = 1 ; i <= d ; i++) res*=7;
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	init();
	while (T--)
	{
	    int n;
	    scanf("%d",&n);
	    if (n==1)
	    {
		printf("%d\n",1);
		continue;
	    }
	    int ans = lower_bound(dp+1,dp+t+1,n)-dp;
	    printf("%d\n",dp[ans]);
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
