/*************************************************************************
	> File Name: code/whust/#0.1/B.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月08日 星期六 14时08分25秒
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
int h1,h2,m1,m2,s1,s2;
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
	int ans = 0;
	scanf("%d:%d:%d",&h1,&m1,&s1);
	scanf("%d:%d:%d",&h2,&m2,&s2);
	if (h2<h1) h2 = h2 + 24;
	for ( int i = h1+1 ; i <= h2-1 ; i++)
	{
	    if (h1>=6&&h1<=9) continue;
	    if (h1>=16&&h1<=19) continue;
	    ans = ans + 6;
	}
	ans = ans + m2/11 + 1;
	if (m1!=0)
	{
	    ans = ans +6- (m1-1)/11-1;
	}
	else
	{
	    ans = ans + 6;
	}
	cout<<ans<<endl;
    }
  
	return 0;
}
