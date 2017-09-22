/*************************************************************************
	> File Name: code/cf/#326/A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月22日 星期四 20时00分33秒
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
const int N=1E5+7;
int n;
int a[N],p[N];
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   scanf("%d",&n);
   for ( int i = 0 ;  i < n ; i++) scanf("%d %d",&a[i],&p[i]);
   int mi = inf;
   int ans = 0 ;
   for ( int i = 0 ; i < n ; i++)
   {
       if (p[i]<mi)
	   mi = p[i];
       
       ans += mi*a[i];
   }
   cout<<ans<<endl;
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
