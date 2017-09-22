/* ***********************************************
Author :111qqz
Created Time :Sat 24 Sep 2016 02:16:33 PM CST
File Name :code/hdu/3507.cpp
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
const int N=5E5+7;
int a[N],sum[N];
int dp[N];
int n,m;
int q[N];
int head,tail;
int calDp( int i,int j)
{
    return dp[j] + m + ( sum[i] - sum[j] ) * ( sum[i] - sum[j] );
}
int calUp(int j,int k)
{
    return dp[j] + sum[j] * sum[j] - (dp[k] + sum[k] * sum[k]);
}
int calDown(int j,int k)
{
    return 2*(sum[j] - sum[k]);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%d%d",&n,&m))
	{
	    sum[0] =  0;
	    for  ( int i = 1  ; i <= n ; i++) scanf("%d",a+i),sum[i] = sum[i-1] + a[i];
	    dp[0] = 0 ;
	    head = tail = 0 ;
	    q[tail++] =  0;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		while (head+1<tail && calUp(q[head+1],q[head])<=sum[i]*calDown(q[head+1],q[head])) head++;
		dp[i] = calDp(i,q[head]);
		while (head+1<tail && calUp(i,q[tail-1])*calDown(q[tail-1],q[tail-2])<=calUp(q[tail-1],q[tail-2])*calDown(i,q[tail-1])) tail--;
		q[tail++] = i ;
	    }
	    printf("%d\n",dp[n]);
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
