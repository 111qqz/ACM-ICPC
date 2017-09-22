/*************************************************************************
	> File Name: code/bc/r1003.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月15日 星期六 19时49分26秒
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
int k,b,x0,p;
int next(int x)
{
    return (k*x+b)%p;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
	scanf("%d %d %d %d",&k,&b,&x0,&p);
	int x = x0;
	int LIM = 0;
	int v = 0;
	while ((x!=x0||v==0)&&LIM<=p)
	{   
	    v++;
	    LIM++;
	    x = next (x);
	}
	if (LIM>p)
	{
	    printf("%d\n",-1);
	}
	else
	{
	    printf("%d",v);
	}
    }	
	return 0;
}
