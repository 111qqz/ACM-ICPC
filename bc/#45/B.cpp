/*************************************************************************
	> File Name: code/bc/#45/B.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月04日 星期二 22时18分29秒
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
const int N=1E3+5;
int n,qu;
int ans [N];
int ref[N];
int t[N];
int sum[N];
struct Q
{
    int val,id;
}q[N];

bool cmp (Q a,Q b)
{
    return a.val<b.val;
}
int lowbit( int x)
{
    return x&(-x);
}

void update (int x,int c)
{
    for ( int i = x; i < N ; i = i + lowbit(i))
    {
	t[i] = t[i] + c;
    }
}
int Sum( int x)
{
    int res = 0;
    for ( int i = x ; i >= 1 ; i = i - lowbit(i))
    {
	res = res + t[i];}
    return res;
}

int main()
{
    scanf("%d %d",&n,&qu);
    for ( int i = 1 ; i <= n ; i++)
    {
	scanf("%d",&q[i].val);
	q[i].id = i;
    }
    sort(q+1,q+n+1,cmp);
    for ( int i = 1 ; i <= n ; i++ )
    {
	ref[q[i].id] = i;
    }
    memset(ans,0,sizeof(ans));
    memset(sum,0,sizeof(sum));
    for ( int i = 1 ; i <= n ; i++ )
    {
	update(ref[i],1);
	ans[i] = i-Sum(ref[i]);
	cout<<ans[i]<<endl;
	sum [i] = sum[i-1] + ans[i];
    }
    int x,y;
    for  ( int i = 1 ; i <= qu ; i++ )
    {
	scanf("%d %d",&x,&y);
	cout<<sum[y]-sum[x-1]<<endl;
    }
	return 0;
}
