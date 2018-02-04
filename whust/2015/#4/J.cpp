/*************************************************************************
	> File Name: code/whust/#4/J.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月26日 星期日 12时58分54秒
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
const int N=1E5+7;
struct node
{
    LL h,w;
}a[N],b[N];
bool cmp(node a,node b)
{
    if (a.h<b.h) return true;
    if (a.h==b.h&&a.w<b.w) return true;
    return false;
}
int main()
{
    int T;
    scanf("%d",&T);
    int ans;
    int n;
    while (T--)
    {
	  ans  = 0;
	  multiset<int>se;
	  scanf("%d",&n);
	  for ( int i = 0 ; i < n ; i++ )
		scanf("%lld %lld",&a[i].h,&a[i].w);
	  for ( int i = 0 ;  i< n ; i++ )
		scanf("%lld %lld",&b[i].h,&b[i].w);
	  sort(a,a+n,cmp);
	  sort(b,b+n,cmp);
	  int j = 0;
	  for ( int i = 0 ; i < n ; i++ )
	  {
		while (b[j].h<=a[i].h&&j<=n-1)
		{
		    se.insert(b[j].w);
		    j++;
		}
		if (se.size()==0) continue;
		multiset<int>::iterator it;
		it = se.upper_bound(a[i].w);
		if (it!=se.begin()) it--;
		if (*it<=a[i].w)
		{
		    ans++;
		    se.erase(it);
		}
	  }
	  printf("%d\n",ans);
    }
	return 0;
}
