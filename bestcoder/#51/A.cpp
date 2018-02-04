/*************************************************************************
	> File Name: code/bc/#51/A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月15日 星期六 19时00分04秒
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

bool judge( int x)
{
    if (x==1) return false;
    if (x<=3) return true;
    for ( int i = 2 ; i*i<= x ; i++)
    {
	if (x%i==0) return false;
    }
    return true;
}
int main()
{
    int T;
    int n;
    int ans = 1;
    cin>>T;

    while (T--)
    {
	ans = 1;
	scanf("%d",&n);
	if (n>10)
	{
	    if (judge(n))
	    {
		printf("%d\n",n-1);
	    }
	    else
	    {
		printf("%d\n",0);
	    }
	    continue;
	}
	for ( LL i = 1 ; i <= n-1 ;i++)
	{
	    ans = (ans *i)%n;
	}
      printf("%d\n",ans);
	
    }
	return 0;
}
