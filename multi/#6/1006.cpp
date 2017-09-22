/*************************************************************************
	> File Name: code/multi/#6/1006.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月06日 星期四 12时27分21秒
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
int a[N],t[N];
int n; b 
int lowbit( int x)
{
    return x&(-x);
}
void update ( int x,int c)
{
    for ( int i = x ; i <=100000 ; i = i + lowbit(i))
    {
	t[i] = t[i] +c;
    }
}
int Sum( int x)
{
    int res = 0 ;
    for ( int i =  x; i >= 1 ; i = i - lowbit(i))
    {
	res =  res  +  t[i] ;
    }
}
LL cal( int i,int j)
{
    int res ;
    int s1 ,s2;
    s1 = Sum(i-1);
    s2 = Sum(j);
    if (s2-s1==0)
    {
	return i+j;
    }
    else
    {
	res = floor(log(s2-s1)/log(2))+1;
	res = res * (i+j);
	return res;
    }

}
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
	scanf("%d",&n);
	for ( int i = 1 ; i <= n ; i ++ )
	{
	    scanf("%d",&a[i]);
	}
	for ( int i = 1 ; i <= n ; i++ )
	{
	    update(i,a[i]);
	}
	LL ans = 0;
	for (  int i = 1 ; i <= n ; i ++)
	{
	    for ( int j =  i ; j <= n ; j++)
	    {
		ans = ans + cal(i,j);
	//	cout<<"ans:"<<ans<<endl;
	    }
	}
	cout<<ans<<endl;
    }
	return 0;
}
