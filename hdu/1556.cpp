/*************************************************************************
	> File Name: code/hdu/1556.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月07日 星期五 01时56分51秒
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
const int N=1E6+7;

int n;
int c[N];
int lowbit( int x)
{
    return x&(-x);
}
void update ( int x,int delta)
{
    for ( int i = x; i <= N ; i = i + lowbit (i))
    {
	c[i] = c[i] + delta;
    }
}
int sum ( int x)
{
    int res = 0;
    for ( int i = x ; i >= 1 ; i = i - lowbit (i))
    {
	res  = res + c[i];
    }
    return res;
}
int main()
{
    while (scanf("%d",&n)!=EOF && n)
    {
	memset(c,0,sizeof(c));
	for ( int i = 1; i <= n ; i ++)
	{
	    int a,b;
	    scanf("%d %d",&a,&b);
	    update (a,1);
	    update (b+1,-1);
	}
	cout<<sum(1);
	for ( int i = 2 ; i <= n ; i ++)
	{
	    cout<<" "<<sum(i);   //sum(i) 就是位置i的值，而不是和，
				//因为update 并没有更新区间，而是做了一个标记，具体可以用普通数组模拟一遍就明白了
	}
	cout<<endl;
    }
  
	return 0;
}
