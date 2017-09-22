/*************************************************************************
	> File Name: code/whust/#4/B.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月26日 星期日 12时42分44秒
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
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int N=1E6+7;
int a[N];
int n;
int sum[N];

int main()
{
    while (scanf("%d",&n)!=EOF&&n)
    {

    
	  int x;	  
	  int ans = n;
	  memset(sum,0,sizeof(sum));
	  for ( int i = 1 ; i <= n ; i++ )
	  {
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	  }
	  if (sum[n]<0) //无论怎么变换,sum[N]是不变的
	  {
		printf("%d\n",0);
		continue;
	  }
	  for ( int i = 1 ;  i <= n;  i++ )
	  {
		if (a[i]<0)
		    ans--;
		
	  }
	  for ( int i = 2 ; i <= n-1 ; i++ )
	  {
		if (sum[i]<sum[i-1])
		{
		    ans--;
		}
	  }
	  printf("%d\n",ans);
    }
	return 0;
}
