/*************************************************************************
	> File Name: code/bc/#42/BB.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月01日 星期六 09时30分45秒
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
map<int,set<int> >mp;
int m,n;
int main()
{
    while (scanf("%d %d",&n,&m)!=EOF)
    {
	mp.clear();
	for ( int i = 1;  i <= n ; i++ )
	{
	    int tmpx;
	    scanf("%d",&tmpx);
	    mp[tmpx].insert(i);
	}
	for ( int i = 1 ; i <= m ; i++ )
	{
	    int q;
	    scanf("%d",&q);
	    if (mp[q].size()==0)
	    {
		puts("-1");
	    }
	    else
	    {
		printf("%d\n",*mp[q].begin());
		mp[q].erase(mp[q].begin());
	    }
	}
    }
  
	return 0;
}
