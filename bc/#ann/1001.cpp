/*************************************************************************
	> File Name: code/bc/#ann/1001.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月25日 星期六 18时54分24秒
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
int n,m,p,q;
int main()
{
    int T;
    cin>>T;
    int ans = 0;
    while (T--)
    {
	//  scanf("%d %d %d %d",&n,&m,&p,&q);
	  scanf("%d %d %d %d",&n,&m,&p,&q);
	  ans = n*p;
	  ans = min(ans,n/m*q+n%m*p);
	  ans = min(ans,((n-1)/m+1)*q);
	  printf("%d\n",ans);
    }
  
	return 0;
}
