/*************************************************************************
	> File Name: code/bc/#56/1002.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月22日 星期二 10时47分20秒
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
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
#define lr dying111qqz
using namespace std;
#define For(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N = 1E3+5;
const int MOD = 1E9+7;
LL a[N],dp[N][N];
int n,p;
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
   int T;
   cin>>T;
   while (T--)
    {
	scanf("%d %d",&n,&p);
	for ( int i = 1 ; i <= n ; i++) scanf("%lld",&a[i]);
	ms(dp,0);
	dp[0][0] = 1;

	for ( int i  = 1 ; i <= n ; i++)
	{
	    for ( int j = 0 ; j < p ; j ++)
		dp[i][j] = dp[i-1][j];
	

	for ( int j = 0 ; j < p ; j++)
	    dp[i][((j+a[i])%p+p)%p] +=dp[i-1][j];
	for ( int j = 0 ; j < p ; j++)
	    dp[i][j]%=MOD;
	}
	printf("%lld\n",dp[n][0]);
    }
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
