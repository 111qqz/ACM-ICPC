/*************************************************************************
	> File Name: code/whust/#8/E.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月03日 星期一 15时26分58秒
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
int main()
{
    int n;
    while (~scanf("%d",&n))         //Lucas定理，orzorz
    {
	int g = 1 ;
	int s = 0 ;
	while (n)
	{
	    s = s + (n&1);
	    n = n / 2;
	}
	for ( int i = 1 ; i <= s; i ++)
	{
	    g = g * 2;
	}
	printf("%d\n",g);
    }
	return 0;
}
