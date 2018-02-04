/*************************************************************************
	> File Name: code/whust/#3/D.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月25日 星期六 12时28分14秒
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
const  int N=1E4+5;
int a[N];
int n;
int main()
{
    int cas;
    while (scanf("%d",&n)!=EOF)
    {
	  cas++;
	  bool flag=false;
	  if (n==0) break;
	  for ( int i = 1;  i <= n ; i++ )
	  {
		scanf("%d",&a[i]);
	  }
	  int ti=0;
	  while (ti<=1000)
	  {
		
		bool ok = true;
		for ( int i = 1 ; i <= n-1 ; i++)
		{
		    if (a[i]!=a[i+1])
		    {
			  ok = false;
			  break;
		    }
		}
		if (ok)
		{
		    flag = true;
		    printf("Case %d: %d iterations\n",cas,ti);
		    break;
		}
		ti++;
		a[n+1]=a[1];
		for ( int i = 1 ; i <= n ; i++)
		{
		    a[i]=abs(a[i+1]-a[i]);
		
	     }
	  }
	  if (!flag) printf("Case %d: not attained\n",cas);
    }
	return 0;
}
