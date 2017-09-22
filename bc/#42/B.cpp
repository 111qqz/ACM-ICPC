/*************************************************************************
	> File Name: code/bc/#42/B.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月01日 星期六 02时47分54秒
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
const int N=2E5+7;
int n,m;
map<int,int>mp;
set<int>se[N];
int main()
{
    while (scanf("%d %d",&n,&m)!=EOF)
    {
	for ( int i = 1 ; i <= n ; i++ )
	    se[i].clear();
	mp.clear();
	int  t = 0;
	int x;
	for ( int i = 1 ; i <= n ; i++ )
	{
	    scanf("%d",&x);
	    if (!mp[x]) mp[x]=++t;
	    se[mp[x]].insert(i);
	}
	for ( int i = 1 ; i <= m ; i++)
	{
	    scanf("%d",&x);
	    if (se[mp[x]].size()==0)
	    {
		puts("-1");
	    }
	    else
	    {
		printf("%d\n",*se[mp[x]].begin());
		se[mp[x]].erase(se[mp[x]].begin());
	    }
	}

    }
	return 0;
}
