/*************************************************************************
	> File Name: code/sgu/180.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月06日 星期四 16时40分53秒
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
const int N=7E4+7;
struct Q
{
    int val;
    int id;
}q[N];
int c[N];
int ref[N];
int n;
bool cmp(Q a,Q b)
{
    if (a.val<b.val)
	return true;
    return false;
}

int lowbit( int x)
{
    return x&(-x);
}
void update( int x,int delta)
{
    for ( int i = x; i < N ; i=i+lowbit(i) )
    {
	c[i] = c[i] + delta;
    }
}
int Sum( int x)
{
    int res  =0;
    for ( int i = x; i >= 1 ; i = i-lowbit(i))
    {
	res = res + c[i];
    }
    return res;
}
int main()
{
    while (scanf("%d",&n)!=EOF)
    {

      memset(c,0,sizeof(c));
      for ( int i = 1; i <= n ; i++ )
      {
    	scanf("%d",&q[i].val);
	q[i].id  = i ;
    }
    sort(q+1,q+n+1,cmp);
    for ( int i = 1; i <= n ; i++ )
    {
	if (q[i].val!=q[i-1].val)
	{
	    ref[q[i].id]=i;
	}
	else
	{
	    ref[q[i].id]=ref[q[i-1].id];
	}
    }

    for ( int i = 1 ;i <= n ; i ++) cout<<ref[i]<<endl;
    LL  ans = 0;
    for ( int i = 1 ; i <= n ; i++ )
    {
	update(ref[i],1);
	ans = ans + i-Sum(ref[i]);
    }
    cout<<ans<<endl;
    }
  
	return 0;
}
