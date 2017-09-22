/*************************************************************************
	> File Name: code/hdu/1166.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月06日 星期四 16时24分57秒
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
const int N=5E4+7;
string cmd;
int n;
int c[N];
int x,y;
int lowbit( int x)
{
    return x&(-x);
}
void update( int x,int delta)
{
    for ( int i = x; i < N ; i = i + lowbit(i))
    {
	c[i] = c[i] + delta;
    }
}
int Sum( int x)
{
    int res = 0;
    for ( int i = x; i >= 1 ; i = i - lowbit(i))
    {
	res  = res + c[i];
    }
    return res;
}
int main()
{
    int T;
    cin>>T;
    int cas = 0;
    while (T--)
    {
	cas++;
	printf("Case %d:\n",cas);
	memset(c,0,sizeof(c));
	scanf("%d",&n);
	for ( int i = 1; i  <= n ; i++ )
	{
	    scanf("%d",&x);
	    update(i,x);
	}
	while (cin>>cmd&&cmd!="End")
	{
	    scanf("%d %d",&x,&y);
	    if (cmd=="Query")
	    {
		cout<<Sum(y)-Sum(x-1)<<endl;
	    }
	    if (cmd=="Add")
	    {
		update(x,y);
	    }
	    if (cmd=="Sub")
	    {
		update(x,-y);
	    }
	}
    }
  
	return 0;
}
