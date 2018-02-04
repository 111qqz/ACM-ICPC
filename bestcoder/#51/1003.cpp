/*************************************************************************
	> File Name: code/bc/#51/1003.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月15日 星期六 19时38分25秒
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
int ans;
const int LIM = 1E6+7;
LL next (LL x)
{
    return (k*x)+b % p;
}
int main()
{
    int T;
    while (T--)
    {
	scanf("%d %d %d %d",&k,&b,&x0,&p);
        LL x = next(x0);
	LL y = next(next(x0));
	int v = 1;
	while (v<=LIM &&x!=y)
	{
	    x = next(x);  //乌龟走一步
	    y = next(next(y)); //兔子走两步
	    v++;
	}
	if (v>LIM)   //在规定范围内找不到循环节（兔子没有和乌龟到同一个位置）
	{
	    puts("-1");  
	}
	else
	{
	    printf("%d\n",v);
	}

 /*   x = 1;
    int mu = 0;  //找到循环节的起点
    while (x!=y) 
    {
	 x = next(x);
	 y = next(y);
	 mu++;
    }
    
    int lam = 1; //循环节的长度
    y = next(x);
    while (mu+lam <= LIM  &&x!=y)
    {
    y = next(y);
    lam++;
    }
    if (mu+lam<=LIM)
    {
    printf("%d\n",mu+lam);
    }
    else
    {
    puts("-1");
    }  */
    }
    return 0;
}
