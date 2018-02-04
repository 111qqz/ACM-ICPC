/*************************************************************************
	> File Name: code/bc/#43/B.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月31日 星期五 16时38分13秒
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
LL a[N];
int n,p;

int main()
{
    while (scanf("%d %d",&n,&p)!=EOF)
    {
	LL ans = -1;
	for ( int i = 0 ; i < n;  i++ )
	{
	    scanf("%lld",&a[i]);
	    a[i]=a[i]%p;
	}
	sort(a,a+n);
	ans = (a[n-1]+a[n-2])%p;
	int j = n-1;
	for ( int i = 0 ; i  < n-2 ; i++ )
	{
	    while (i<j&&a[i]+a[j]>=p) j--;
	    ans = max(ans,(a[i]+a[j])%p);
	}
	cout<<ans<<endl;

    }
  
	return 0;
}
