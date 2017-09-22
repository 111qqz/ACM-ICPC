/*************************************************************************
	> File Name: code/whust/#7/G.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月01日 星期六 14时30分01秒
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
const int N=2E2+5;
LL a[5][N];
set<LL>se[6];
set<LL>::iterator it1,it2,it3,it4;
int main()
{
    int T;
    cin>>T;
    int n;
    bool flag;
    while (T--)
    {
	flag = false;
	scanf("%d",&n);
	LL x;
	for ( int i = 1 ; i <= 2 ; i++)
	{
	    for ( int j =  1;  j <= n ; j++)
	    {
		scanf("%lld",&a[i][j]);
	    }
	}
	for ( int i = 3 ; i <= 5 ; i++ )
	{
	    for ( int j = 1 ; j <= n ;  j++ )
	    {
		
		scanf("%lld",&x);
		se[i].insert(x);
	    }
	}
	for ( it1 = se[4].begin();it1!=se[4].end();it1++)
	{
	    if (flag) break;
	    for ( it2 =se[5].begin();it2!=se[5].end();it2++)
	    {
		if (flag) break;
		int j = n;
		for (  int i = 1 ; i <= n-1; i++)
		{
		    if (flag) break;
		    while (i<j&&-*it1-*it2-a[1][i]-a[2][j]<*se[3].begin()) j--;
		    if (se[3].count(-*it1-*it2-a[1][i]-a[2][j])!=0)
		    {
			flag = true;
			break;
		    }
		}
	    }
	}
    	if (flag) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
    }
  
	return 0;
}
