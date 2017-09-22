/*************************************************************************
	> File Name: code/cf/#325/B.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月12日 星期一 16时51分10秒
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
const int N=55;
int a[3][N];
int b[N];
int t[N];
int n;
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   scanf("%d",&n);
   ms(a,0);
   for ( int i = 1 ; i <= n-1 ; i++) scanf("%d",&a[1][i]);
   for ( int i = 1 ; i <= n-1 ; i++) scanf("%d",&a[2][i]);
   for ( int i = 1 ; i <= n ; i++ ) scanf("%d",&b[i] );
   ms(t,0);
   for ( int i = 1 ; i <= n ; i++)
   {
       for (int j = n-1 ; j >= i; j--)
       {
	   t[i]+=a[2][j];
       }
       for ( int j = 1 ; j <= i-1  ; j++)
	{
	    t[i]+=a[1][j];
	}
       t[i]+=b[i];
   }
   sort(t+1,t+n+1);
  // for ( int i = 1 ;i <= n ; i++) cout<<"t[i]:"<<t[i]<<endl;
   int ans = 0;
   ans = t[1] + t[2];
   printf("%d\n",ans);
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
