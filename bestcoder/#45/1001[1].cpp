/*************************************************************************
	> File Name: code/bc/#45/1001.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月29日 星期三 13时25分01秒
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
const int N=1E3+5;
int a[N];
LL n,nn;
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
	scanf("%lld",&n);
	nn = n ;
	int k = 0;
	while (nn)
	{
	    k++;
	    a[k]=nn&1;
	    nn = nn >>1;
	}
	int ans = 0;
//	for ( int i = 1 ; i <= k ; i++ )
//	    cout<<a[i]<<endl;
	for ( int i = 1 ; i <= k ; i++ )
	{
	    if (a[i]==1&&a[i-1]==0)
		ans++;
	}
	printf("%d\n",ans);
    }
	return 0;
}
