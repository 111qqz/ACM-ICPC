/*************************************************************************
	> File Name: code/51nod/learn/greedy/3.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月05日 星期一 19时42分15秒
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
const int N=1E4+5;
LL a[N];
int ans;
int n;
LL m;
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   scanf("%d %lld",&n,&m);
   for ( int  i  = 0 ; i < n ; i++) scanf("%lld",&a[i]);
   sort(a,a+n);
   int i = 0;
   int j = n-1;
   int cnt = 0;
   int ans = 0 ;
   
   while (cnt<n&&i<=j)
   {
       if (i==j)
       {
	   cnt++;
	   ans++;
	   break;
       }
	
       if (a[i]+a[j]<=m)
       {
	   i++;
	   j--;
	   cnt = cnt + 2;
	   ans++;
       }
       else
       {
	   j--;
	   cnt = cnt + 1;
	   ans++;
       }
   }
   printf("%d\n",ans);
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
