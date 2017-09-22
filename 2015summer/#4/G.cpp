/*************************************************************************
	> File Name: code/2015summer/#4/G.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月29日 星期三 21时53分52秒
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
const int N=2E4+5;
int k,n;
LL a[N];
LL ans ;
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
	scanf("%d %d",&n,&k);
	for ( int i = 0;  i< n ; i++ )
	{
	    scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	ans = 9999999999;
	for ( int i = 0 ; i+k-1<n ; i++)
	{
	    ans = min(ans,a[i+k-1]-a[i]);
	}
	cout<<ans<<endl;
    }
  
	return 0;
}
