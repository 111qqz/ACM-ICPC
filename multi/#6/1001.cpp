/*************************************************************************
	> File Name: code/multi/#6/1001.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月06日 星期四 12时09分51秒
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
const LL MOD=1E9+7;
LL n;
LL quickpow(LL m,LL n,LL k)
{
    LL b = 1;
    while (n>0)
    {
	if (n&1)
	    b = (b*m)%k;
	n = n >> 1;
	m = (m*m)%k;
    }
    return b;
}

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
	scanf("%lld",&n);
	cout<<quickpow(2,n-1,MOD)-1<<endl;
    
    }
  
	return 0;
}
