/*************************************************************************
	> File Name: code/cf/#322/B.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月29日 星期二 00时27分25秒
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
const int N=1E5+7;
int a[N];
int ans[N];
int n;
int main()
{
  #ifndef  ONLINE_JUDGE 
//   freopen("in.txt","r",stdin);
  #endif
   cin>>n;
   for ( int i = 1 ; i <= n ; i++)
       scanf("%d",&a[i]);
   int mx ;
   ms(ans,0);
   mx = a[n];
   for ( int i = n-1 ; i >= 1 ; i--)
    {
	if (a[i]>mx)
	{
	    mx = a[i];
	    continue;
	}
	else
	{
	    ans[i] = mx-a[i]+1;
	}
    }
   for ( int i = 1 ; i < n ; i++)
       printf("%d ",ans[i]);
   printf("%d",0);
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
