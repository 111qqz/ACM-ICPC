/*************************************************************************
	> File Name: code/hdu/4630.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月11日 星期二 17时47分01秒
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
int a[N];
int n,q;
int b[N],c[N],ans[N];
struct NODE
{
    int l,r;
    int id;
}Q[N];

bool cmp(NODE a,NODE b)
{
    if (a.l>b.l) return true;
    return false;
}
int lowbit( int x)
{
    return x&(-x);
}

void update ( int x,int delta)
{
    for ( int i  = x; i <= n ; i = i + lowbit(i))
    {
	c[i] = max(c[i],delta);
    }
}
int sum( int x)
{
    int res  = 0;
    for ( int i = x ; i >= 1 ; i = i - lowbit(i))
    {
	res = max(res,c[i]);
    }
    return res;
}
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
	memset(c,0,sizeof(c));
	memset(b,0,sizeof(b));
	scanf("%d",&n);
	for ( int i = 1 ; i <= n ; i++)
	{
	    scanf("%d",&a[i]);
	}
	scanf("%d",&q);
	for ( int i = 0 ; i < q ; i++ )
	{
	    scanf("%d %d",&Q[i].l,&Q[i].r);
	    Q[i].id = i;
	}
	sort(Q,Q+q,cmp);
	int i = n;
	int j = 0;
	while (j<q)
	{
	    
	    while (i>0&&i>=Q[j].l)
	    {
		for ( int k = 1 ; k*k<=a[i]; k++)  //k为约数
		{
		    if (a[i]%k==0)
		    {
			if (b[k]!=0)
			{
			    update(b[k],k);
			}
			b[k] = i;  //b[k]纪录的是约数k最后一次出现的位置
			if (k!=a[i]/k)
			{
			    if (b[a[i]/k])
			    {
				update (b[a[i]/k],a[i]/k);
			    }
			    b[a[i]/k]=i;
		        }

		    }
		}
		i--;
	    }
	    while (j<q&&Q[j].l>i)
	    {
		ans[Q[j].id]=sum(Q[j].r);
		j++;
	    }
	
	}
	for ( int i = 0 ; i < q ; i ++)
	{
	    printf("%d\n",ans[i]);
	}
    }
  
	return 0;
}
