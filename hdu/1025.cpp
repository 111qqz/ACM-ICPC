/* ***********************************************
Author :111qqz
Created Time :2016年04月02日 星期六 13时35分36秒
File Name :code/hdu/1025.cpp
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
int n;
int dp[N],g[N];
pi a[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int cas = 0 ;
	while (scanf("%d",&n)!=EOF)
	{
	    for ( int i = 1 ; i <= n ; i++) scanf("%d %d",&a[i].fst,&a[i].sec);
	    sort(a+1,a+n+1);

	    ms(g,0x3f);
	    ms(dp,0);
	    int ans = 0 ; 
	    for ( int i = 1 ; i  <= n ; i++)
	    {
		int k = lower_bound(g+1,g+n+1,a[i].sec)-g;
		dp[i] = k;
		g[k] = a[i].sec;
		ans = max(ans,dp[i]);
	    }
	    printf("Case %d:\n",++cas);
	    if (ans==1)
	    printf("My king, at most %d road can be built.\n",ans);  //road的单复数。。。。坑死。
	    else   printf("My king, at most %d roads can be built.\n",ans);
	    printf("\n");
	}



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
