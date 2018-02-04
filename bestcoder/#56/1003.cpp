/*************************************************************************
    > File Name: code/poj/1195.cpp
    > Author: 111qqz
    > Email: rkz2013@126.com 
    > Created Time: 2015年08月06日 星期四 15时54分03秒
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
const int N=1E3+99;
int a[N][N];
int c[N][N];
int n,m,q;
int l,b,r,t;
int s;
int lowbit( int x)
{
    return x&(-x);
}
void update( int x,int y,int delta)
{
    for ( int i = x ; i <=n ; i = i + lowbit(i))
    {
    for ( int j = y ; j <= m;  j = j + lowbit(j))
    {
        c[i][j] = c[i][j] + delta;
    }
    }
}
int Sum( int x,int y)
{
    int res = 0 ;
    for ( int i = x; i >= 1;  i = i - lowbit(i))
    {
    for ( int j = y ; j >= 1 ; j = j - lowbit(j))
    {
        res  = res + c[i][j];
    }
    }
    return res;
}
int main()
{
  int cmd ;
  int T;
  
  cin>>T;
  while (T--)
  {
      memset(c,0,sizeof(c));
      scanf("%d %d %d",&n,&m,&q);
      for ( int i = 0 ; i < n ; i++)
	{
	    for ( int j = 0 ; j < m ; j ++)
	    {
		scanf("%d",&a[i][j]);
		update (i+1,j+1,a[i][j]);
	    }
	    
	}
    
      for ( int i = 0 ; i < q ; i++)
      {

	  int cmd;
	    scanf("%d",&cmd);
	 if (cmd==2)
	 {
	     int x,y,z;
	    scanf("%d %d %d",&x,&y,&z);
	    int tmp = z-a[x][y];
	     a[x][y] = z;
	 update(x,y,tmp);
	 }
	 if (cmd==1)
	 {
	     scanf("%d %d %d %d",&l,&b,&r,&t);
	     int tmp= (b-l+1)*(t-r+1);
	     if ( tmp %2==1)
		{
		    puts("Yes");
		    continue;
		}
	     int sum =Sum(r+1,t+1)-Sum(l,t+1)-Sum(r+1,b)+Sum(l,b);
	     if (sum>tmp)
		{
		    puts("Yes");
		    continue;
		}
	     puts("No");
	 }
	}
  }   
    return 0;
}
