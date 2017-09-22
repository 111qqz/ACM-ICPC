/* ***********************************************
Author :111qqz
Created Time :Mon 26 Sep 2016 04:02:24 AM CST
File Name :code/hdu/5904.cpp
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
const int N=1E6+7;
int dp[N],dp2[N];
int n,m;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	scanf("%d",&T);
	while (T--)
	{
	    ms(dp,0);
	    ms(dp2,0);
	    scanf("%d%d",&n,&m);
	    int mx = 0;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		int x;
		scanf("%d",&x);
		dp[x] = dp[x-1] + 1;
		mx = max(x,mx);
	    }

	    for ( int i = 1 ; i <= m ; i++)
	    {
		int x;
		scanf("%d",&x);
		dp2[x] = dp2[x-1] + 1;
		mx = max(x,mx);
	    }

	    int ans = 0 ;
	    for ( int i = 1 ; i <= mx  ; i++) ans = max(ans,min(dp[i],dp2[i]));
	    printf("%d\n",ans);

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
