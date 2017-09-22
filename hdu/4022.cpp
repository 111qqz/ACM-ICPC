/*************************************************************************
	> File Name: code/hdoj/4022.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月01日 星期六 04时37分20秒
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
const int N=2E5+7;
const int inf = 0x7fffffff;

map<int,int>xmap,ymap;
multiset<int>x[N];
multiset<int>y[N];
int main()
{
    int n,m;
    while (scanf("%d %d",&n,&m)!=EOF)
    {
	if (n==0&&m==0) break;
	for ( int i = 1 ; i <= n ; i++)
	{
	    x[i].clear();
	    y[i].clear();
	}
	xmap.clear();
	ymap.clear();
	int tx,ty;
	int cntx=0,cnty=0;
	for ( int i = 1 ; i <= n ; i++ )
	{
	    scanf("%d %d",&tx,&ty);
	    if (!xmap[tx]) xmap[tx]=++cntx;
	    if (!ymap[ty]) ymap[ty]=++cnty;
	    x[xmap[tx]].insert(ymap[ty]);
	    y[ymap[ty]].insert(xmap[tx]);
	}
	int c,d;
	set<int>::iterator it;
	for ( int i = 1; i <= m ; i++ )
	{
	    scanf("%d %d",&c,&d);
	    if (c==0)
	    {
		cout<<x[xmap[d]].size()<<endl;
		for ( it = x[xmap[d]].begin();it!=x[xmap[d]].end();it++)
		{
		    y[*it].erase(xmap[d]);
		}
		x[xmap[d]].clear();
	    }
	    else
	    {
		cout<<y[ymap[d]].size()<<endl;
		for ( it =y[ymap[d]].begin();it!=y[ymap[d]].end();it++)
		{
		    x[*it].erase(ymap[d]);

		}
		y[ymap[d]].clear();
	    }
	}
	printf("\n");
    }
  
	return 0;
}
