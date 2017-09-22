/*************************************************************************
	> File Name: code/zoj/3631.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月19日 星期一 19时21分29秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#include<cctype>
                 
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int M=1E7+5;
int dp[M];
int n,m;
int a[33];
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   while (scanf("%d %d",&n,&m)!=EOF)
   {
       ms(dp,0);
       for ( int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
    

	for ( int i = 0 ; i < n ; i++ )
	    for ( int v = m ; v >=a[i] ; v--)
		dp[v] = max(dp[v],dp[v-a[i]]+a[i]);
	
	
	
	int ans = -1;
	for ( int i = 0 ; i <= m ; i++)
	{
	    ans = max(ans,dp[i]);
	}
	printf("%d\n",ans);
   }
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
