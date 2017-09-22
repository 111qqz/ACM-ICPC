/*************************************************************************
	> File Name: code/zoj/3624.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月20日 星期二 06时45分26秒
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
#include<cctype>
                 
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int MOD = 1E9+7;
int m,n,p,q;
LL qpow(LL a,LL b,LL p)
{
    LL res = 1;
    while (b)
    {
	if (b&1) res = (res*a)%p;
	a = (a*a)%p;
	b >>=1;
    }
    return res;
}

LL comb(LL a,LL b,LL p)
{
    if (a<b) return 0;
    if (a==b) return 1;
    if (b>a-b) b = a-b;
    
    LL ans = 1,ca = 1,cb = 1;
    for ( LL i = 0 ; i < b ; i++)
    {
	ca = (ca*(a-i))%p;
	cb = (cb*(b-i))%p;
    }
    ans  = (ca*qpow(cb,p-2,p))%p;
    return ans;
}

LL lucas(int n,int m,int p)
{
    LL ans = 1;
    
    while (n&&m&&ans)
    {
	ans = (ans*comb(n%p,m%p,p))%p;
	n /= p;
	m /= p;
    }
    return ans%p;
}

int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   while (scanf("%d %d %d %d",&m,&n,&p,&q)!=EOF)
  {
      LL ans;
      ans =(lucas(m+n,n,MOD)*lucas(m+q-p,q,MOD))%MOD+MOD;
      ans = ans -(lucas(m+q,m,MOD)*lucas(m+n-p,n,MOD))%MOD;
      ans = ans % MOD ;
    
      printf("%lld\n",ans);

  }
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
