/*************************************************************************
	> File Name: code/uva/116.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月22日 星期六 23时52分45秒
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
int n,m;
int a[11][101];
int dp[11][101];
int Min(int x,int y,int z)
{
    int res =  inf;
    if (x<res) res = x;
    if (y<res) res = y;
    if (z<res) res = z;
    return res;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
    freopen("in.txt","r",stdin); 
  #endif
    while (~scanf("%d %d",&n,&m)){
	For(i,n){
	    For(j,m){
		scanf("%d",&a[i][j]);
	}
	}
	ms(dp,inf);
	for ( int i = 0 ; i < n ; i++)
	    dp[m-1][i] = a[i][m-1];
	for ( int i = m-2 ; i >= 0; i--){
	    for (int j = 0 ; j <= n-1 ; j++){
		dp[i][j]=Min(dp[i+1][(j+n-1)%n],dp[i+1][j%n],dp[i+1][(j+1)%n])+a[i][j];
	    }
	}
	int ans = inf;
	for (int i  = 0 ; i < n ; i++){
	    ans = min(ans,dp[0][i]);
	}
	printf("%d\n",ans);

    }
  
  
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
