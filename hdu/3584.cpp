/*************************************************************************
	> File Name: code/hdu/3584.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月07日 星期五 14时01分53秒
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
const int N=1E2+5;
int c[N][N][N];
int n,m;
int x1,y1,z1,x2,y2,z2;
int lowbit( int x)
{
    return x&(-x);
}
void update ( int x,int y,int z,int delta)
{
    for ( int i = x; i <= n ; i = i + lowbit(i))
    {
	for ( int j =  y ; j <= n ; j = j + lowbit(j))
	{
	    for ( int  k = z ; k  <= n ; k = k + lowbit(k))
	    {
		c[i][j][k] += delta;
	    }
	}
    }
}

int sum (int x,int y,int z)
{
    int res = 0;
    for ( int i = x; i >= 1 ; i -= lowbit(i))
    {
	for ( int j = y ; j >= 1 ; j -= lowbit(j))
	{
	    for ( int k = z ; k >= 1 ; k -= lowbit(k))
	    {
		res = res + c[i][j][k];
	    }
	}
    }
    return res;
}
int main()
{
    int op;
    while (scanf("%d %d",&n,&m)!=EOF)
    {
	memset(c,0,sizeof(c));
	for ( int i = 1 ; i <= m ; i ++ )
	{
	    scanf("%d",&op);
	    if (op)
	    {
		scanf("%d %d %d %d %d %d",&x1,&y1,&z1,&x2,&y2,&z2);
		update (x1,y1,z1,1);
		update (x1,y1,z2+1,1);
		update (x1,y2+1,z1,1);
		update (x2+1,y1,z1,1);

		update (x2+1,y2+1,z1,1);
		update (x2+1,y1,z2+1,1);
		update (x1,y2+1,z2+1,1);
		update (x2+1,y2+1,z2+1,1);

	    }
	    else
	    {
		scanf("%d %d %d",&x1,&y1,&z1);
		cout<<sum(x1,y1,z1)%2<<endl;
	    }
	}
    }
  
	return 0;
}
