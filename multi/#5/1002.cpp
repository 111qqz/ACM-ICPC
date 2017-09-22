/*************************************************************************
	> File Name: code/multi/#5/1002.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月04日 星期二 13时51分14秒
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
const int inf = 0x7fffffff;
const int N=5E5+7;
LL a[N];
LL ans;
int n,m,z,l;
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
	scanf("%d %d %d %d",&n,&m,&z,&l);
	a[1] = 0;
	for ( int i = 2; i <= n ; i++ )
	{
	    a[i] = (a[i-1]*m+z)%l;
	}
	
	ans = 0;
	for ( int i = 1 ;i <= n;  i++ )
	{
	    ans = ans ^ (a[i]+a[i]);
	}
	printf("%lld\n",ans);
    }
  
	return 0;
}
