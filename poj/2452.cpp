/* ***********************************************
Author :111qqz
Created Time :2016年05月16日 星期一 13时42分56秒
File Name :code/poj/2452.cpp
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
int n;
int a[N];
int dp[N][20];
int dp2[N][20];


int _min(int l,int r)
{
    if (a[l]<a[r]) return l;
    return r;
}
int _max( int l,int r)
{
    if (a[l]>a[r]) return l;
    else return r;
}
void max_init()
{
    for ( int i = 1 ; i <= n ; i++) dp[i][0] = i;

    for ( int j = 1 ; (1<<j)<=n ; j++)
	for (int i = 1 ; i + (1<<j)-1 <= n ;i++)
	    dp[i][j] = _max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}

void min_init()
{
    for ( int i = 1 ;i  <= n ; i++) dp2[i][0] = i;

    for ( int j = 1 ; (1<<j)<= n ; j++)
	for ( int i = 1 ; i + (1<<j) -1 <= n ; i++)
	    dp2[i][j] = _min(dp2[i][j-1],dp2[i+(1<<(j-1))][j-1]);
}

int rmq_max(int l,int r)
{
    int k = 0 ;
    while (1<<(k+1)<=r-l+1) k++;
    return _max(dp[l][k],dp[r-(1<<k)+1][k]);
}

int rmq_min( int l,int r)
{
    int k = 0  ;
    while (1<<(k+1)<=r-l+1) k++;
    return _min(dp2[l][k],dp2[r-(1<<k)+1][k]);
}

int bin (int x,int l,int r)
{
    while (l<=r)
    {
	if (l==r) return l;
	int m = (l+r)>>1;
	if (a[x]<a[rmq_min(l,m)])
	    l = m + 1;
	else r = m;
    }
}
void solve()
{

    int ans = 0;
    for ( int i = 1 ; i+ans < n ; i++)
    {
	int r = bin(i,i+1,n);
	int k = rmq_max(i,r);
	if (a[k]>a[i])
	    ans = max(ans,k-i);
    }
    if (ans==0) puts("-1");
    else printf("%d\n",ans);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	 while (scanf("%d",&n)!=EOF)
	{
	    for ( int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);
	    max_init();
	    min_init();

	    solve();
	//    cout<<"sadsad"<<endl;

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
