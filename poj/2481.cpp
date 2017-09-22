/*************************************************************************
	> File Name: code/poj/2481.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月04日 星期二 02时06分05秒
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
const int N=1E5+7;
int n;
int a[N],t[N];
struct Q
{
    int s,e,id;
}q[N];
bool cmp (Q a,Q b)
{
    if (a.e>b.e) return true;
    if (a.e==b.e&&a.s<b.s) return true;
    return false;
}

int lowbit(int x)
{
    return x&(-x);
}
void update ( int x,int c)
{
    for ( int i = x ; i <  N ; i = i + lowbit(i))
    {
	t[i] = t[i] + c;
    }
}
int Sum ( int x)
{
    int res = 0;
    for (  int i = x ; i >= 1 ; i = i - lowbit(i))
    {
	res = res + t[i];
    }
    return res;
}
int main()
{
    while (~scanf("%d",&n)&&n)
    {
	memset(t,0,sizeof(t));
	memset(a,0,sizeof(a));

	for ( int i = 0 ; i  < n; i ++ )
	{
	    scanf("%d %d",&q[i].s,&q[i].e);
	    q[i].id = i;
	}
	sort(q,q+n,cmp);
	a[q[0].id] = 0; //0是最强的...
	update(q[0].s+1,1);
	for ( int i = 1 ; i < n ;  i++)
	{
	    if (q[i].e==q[i-1].e&&q[i].s==q[i-1].s)
	    {
		a[q[i].id]=a[q[i-1].id];  // 完全一样，区间长度为0，不计数。
	    }
	    else
		a[q[i].id] = Sum (q[i].s+1);
	    update(q[i].s+1,1);
	}
	for ( int i = 0 ; i < n-1 ; i++ )
	    cout<<a[i]<<" ";
	    cout<<a[n-1]<<endl;
    }
  	return 0;
}
