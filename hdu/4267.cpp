/*************************************************************************
	> File Name: code/hdu/4267.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月07日 星期五 14时27分58秒
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
const int N=5E4+3;
int c[N][11][11];
int a[N];
int n,m,k,del,x,q,y;
bool flag;
int lowbit( int x)
{
    return x&(-x);
}
void update ( int a,int b,int x, int delta)
{
    for ( int i = x; i <= n ; i = i + lowbit (i))
    {
	c[i][a][b] += delta;
    }
}
int sum ( int a,int b,int x)
{
    int res =  0;
    for ( int i  = x;  i >= 1; i = i - lowbit (i))
    {
	res = res + c[i][a][b];
    }
    return res;
}
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
	memset(c,0,sizeof(c));
	flag = true;

	for ( int i = 1 ;i <= n ; i++ )
	{
	    scanf("%d",&a[i]);
	}
	scanf("%d",&q);
	flag = false;
	int op;
	for ( int i = 1 ; i <= q ; i ++)
	{
	    scanf("%d",&op);
	    if (op==1)
	    {
		scanf("%d %d %d %d",&x,&y,&k,&del);
		update (k,x%k,x,del);
		update(k,x%k,y+1,-del);
	    }
	    else
	    {
		scanf("%d",&x);
		int ans  = a[x];
		for ( int i = 1 ; i <= 10 ; i++)
		{
		    ans = ans +sum(i,x%i,x);
		}
		cout<<ans<<endl;
	    }
	}
    }
	return 0;
}
