/*************************************************************************
	> File Name: code/zoj/r3623.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月19日 星期一 17时30分42秒
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
const int N=4E2+7;
int n,v;
int t[40],l[40];
int dp[N];
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   while (scanf("%d %d",&n,&v)!=EOF)
   {
       ms(dp,0);
       for ( int i = 0 ; i < n ; i++) scanf("%d %d",&t[i],&l[i]);
       
       for ( int j = 0 ; j < N-25 ; j++)
	{
	    for ( int i = 0 ; i < n ; i++)
		dp[j+t[i]] = max(dp[j+t[i]],dp[j]+j*l[i]);
	}
       for ( int i = 0 ; i < N ; i++)
	   if (dp[i]>=v)
	    {
		printf("%d\n",i);
		break;
	    }
   }
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
