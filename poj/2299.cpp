/*************************************************************************
	> File Name: code/poj/2299.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月04日 星期二 12时27分32秒
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
int n;
int t[N];
int ref[N];

struct Q
{
    int val,id;
}q[N];


bool cmp(Q a,Q b)
{
    if (a.val<b.val) return true;
    return false;
}
int lowbit( int x)
{
    return x&(-x);
}
void update ( int x,int c)
{
    for ( int i = x ; i < N ; i = i + lowbit(i))
    {
	t[i] = t[i] + c;
    }
}
LL Sum( int x)
{
    LL res = 0;
    for ( int i = x; i >= 1 ; i = i - lowbit(i))
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
	for ( int i = 1 ; i  <= n ; i++ )
	{
	    scanf("%d",&q[i].val);  //离散化的时候相对大小不能打乱
	    q[i].id = i;
	}
	sort(q+1,q+n+1,cmp);
	for ( int i = 1 ; i <= n ; i++ )
	{
	    ref[q[i].id] = i;
	}
	LL ans = 0;
	for ( int i = 1 ; i <= n ; i++ )
	{
	    update(ref[i],1);
	    ans = ans + i-Sum(ref[i]);  
	  //  cout<<"ans:"<<ans<<endl;
	    
	}
	cout<<ans<<endl;
    }
	return 0;
}
