/*************************************************************************
	> File Name: code/bc/#56/r1003.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月22日 星期二 11时10分06秒
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
#include<cctype>
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
#define lr dying111qqz
using namespace std;
#define For(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=5E2+5;
int c[N][N];
int a[N][N];
int n,m,q;
int lowbit ( int x)
{
    return x&(-x);
}
void update (int x,int y,int delta)
{
    for ( int i = x ; i <= n ; i = i + lowbit(i))
    {
	for ( int j =  y ;  j <= m ; j = j + lowbit(j))
	{
	    c[i][j]^=delta;
	}
    }
}

int sum( int x,int y)
{
    int res = 0;
    for ( int i = x; i >= 1 ; i = i - lowbit(i))
    {
	for ( int j = y ; j >= 1 ; j = j - lowbit(j))
	{
	    res ^= c[i][j];
	}
    }
    return res;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   int T;
   scanf("%d",&T);
   while (T--)
    {
	scanf("%d %d %d",&n,&m,&q);
	for ( int i = 1 ; i <= n ; i++)
	{
	    for ( int j = 1 ; j <= m ; j++)
	    {
		scanf("%d",&a[i][j]);
		update (i,j,a[i][j]);
	    }
	}

	for (int  i = 0 ; i < q ; i++)
	{
	    int opt;
	    scanf("%d",&opt);
	    if (opt==1)
	    {
		int x1,x2,y1,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		int tmp = sum(x2,y2)^sum(x2,y1-1)^sum(x1-1,y2)^sum(x1-1,y1-1);
		if (tmp>0)
		{
		    puts("Yes");
		}
		else
		{
		    puts("No");
		}
	    }
	    else
	    {
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		update (x,y,a[x][y]); //清零
		a[x][y] = z;
		update (x,y,a[x][y]);
	    }
	}
    }
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
