/*************************************************************************
	> File Name: code/bc/#57/1002.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月26日 星期六 19时31分10秒
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
const int N=1E5+7;
int c[N],d[N];
int n,m,K,Q;
bool vx[N],vy[N];

int lowbit(int x)
{
    return x&(-x);
}

void update ( int x,int delta)
{
    for ( int i = x ; i  <= n ; i = i + lowbit(i))
    {
	c[i] = c[i] + delta;
    }
}

LL sum ( int x)
{
    LL res = 0 ;
    for ( int i = x ; i >= 1 ; i = i - lowbit(i))
    {
	 res  = res  + c[i];
    }
    return res;
}

void update2( int y,int delta)
{
    for ( int i = y ; i <= m ; i = i + lowbit(i))
    {
	d[i] = d[i] + delta;
    }
}

LL sum2( int y)
{
    LL res = 0 ;
    for ( int i = y  ;  i >= 1 ; i = i - lowbit(i))
    {
	res = res + d[i];
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
	ms(c,0);
	ms(d,0);
	memset(vx,false,sizeof(vx));
	memset(vy,false,sizeof(vy));
	scanf("%d %d %d %d",&n,&m,&K,&Q);
	for ( int i  = 0 ; i <K ; i++)
	{
	    int x,y;
	    scanf("%d %d",&x,&y);
	    if (!vx[x])
	    {
	     	update (x,1);
		vx [x] = true;
	    }
	    if (!vy[y])
	    {
		update2 (y,1);
		vy[y] = true;
	    }
	    
	}
	for ( int i = 0 ; i < Q ; i++)
	{
	    int x1,y1,x2,y2;
	    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	    int xx = sum(x2)-sum(x1-1);
	    int yy = sum2(y2)-sum2(y1-1);
	  //  cout<<"sum(x2):"<<sum(x2)<<endl;
	  //  cout<<"sum(x1-1):"<<sum(x1-1)<<endl;
	  //  cout<<"sum(y2):"<<sum(y2)<<endl;
	  //  cout<<"sum(y1-1)"<<sum(y1-1)<<endl;
	  //  cout<<"xx:"<<xx<<endl;
	  //  cout<<"yy:"<<yy<<endl;
	    if (xx>=x2-x1+1||yy>=y2-y1+1)
	    {
		puts("Yes");
	    }
	    else
	    {
		puts("No");
	    }
	     
	}
    }
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
