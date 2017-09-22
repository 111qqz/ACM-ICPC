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
int x,y,A,l,b,r,t;
int s;
int lowbit( int x)
{
    return x&(-x);
}
void update( int x,int y,int delta)
{
    for ( int i = x ; i <=s ; i = i + lowbit(i))
    {
	for ( int j = y ; j <= s;  j = j + lowbit(j))
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
  while (scanf("%d",&cmd)!=EOF)
  {
      if (cmd==3) break;
      if (cmd==0)
      {
	  scanf("%d",&s);
	  memset(a,0,sizeof(a));
      }
      if (cmd==1)
      {
	  scanf("%d %d %d",&x,&y,&A);
	  a[x][y] +=A;
	  update(x+1,y+1,A);
      }
      if (cmd==2)
      {
	  scanf("%d %d %d %d",&l,&b,&r,&t);
	  cout<<Sum(r+1,t+1)-Sum(l,t+1)-Sum(r+1,b)+Sum(l,b)<<endl;
      }
  }   
	return 0;
}
