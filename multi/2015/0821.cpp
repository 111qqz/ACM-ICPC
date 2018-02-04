/*************************************************************************
	> File Name: code/2015summer/0821.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月20日 星期四 23时45分20秒
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
const int N=1E6+7;
int sum[50005];
LL p[N];

void solve ()
{
    int d,n;
    int x;
    memset(p,0,sizeof(p));
    sum[0] =  0;
    p [0] = 1;
    for ( int i = 1 ; i <= n ; i++){
	scanf("%d",&x);
	sum[i] = (sum[i-1] + x) % d;
	p[sum[i]]++;
    }
    LL ans = 0 ;
    for ( int i = 0 ; i < d ; i++){
	if (p[i]>0){
	    ans = ans + p[i]*(p[i]-1)/2;
	}
    }
    cout<<ans<<endl;
}
int main()
{
    int T;
    cin>>T;
    while (T--){
	solve();
    }
	return 0;
}
