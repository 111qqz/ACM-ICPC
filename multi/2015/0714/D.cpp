/*************************************************************************
	> File Name: code/2015summer/0714/D.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月16日 星期四 01时31分13秒
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
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const LL MOD=1E9+7;
LL x;
LL ans;
LL eular(LL n)
{
    LL res = 1;
    for ( int i = 2 ; i*i <= n ; i++ )
    {
	  if (n%i==0)
	  {
		res =res*(i-1);
		n=n/i;
		while (n%i==0)
		{
		    n = n/i;
		    res = res * i;
		}
	  }
    }
    if (n>1) res=res*(n-1);
    return res;
}
int main()
{
    while (scanf("%lld",&x)!=EOF&&x)
    {
	  ans =(x*(x-1-eular(x))/2)% MOD;
	  while (ans<0) ans=ans+MOD;
	    ans = ans % MOD;
	  printf("%lld\n",ans);
    }
    return 0;
}

