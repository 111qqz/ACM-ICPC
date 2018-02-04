/* ***********************************************
Author :111qqz
Created Time :2016年08月04日 星期四 14时20分10秒
File Name :code/multi2016/#6/1001.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define fst first
#define sec second
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;
#define pi pair < int ,int >
#define MP make_pair

using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=1E6+11111;
LL n,m,r;
LL fac[N],inv[N];
LL get_inv(LL x,LL d)
{
    LL ret = 1LL;
    for ( LL p = d-2 ; p ; p>>=1 ; x=(x*x)%d)
	if (p&1)
	    ret = (ret*x)%d;
    return ret;
}
void init( LL d)
{
    fac[0] = 1;
    for ( LL i = 1 ; i < N ; i++)
	fac[i] = (fac[i-1]*i)%d;
    for (LL i = 0 ; i < N ; i++)
	inv[i] = get_inv(fac[i],d);
}
LL Cc(LL a,LL b,LL q)
{
    if (a<b) return 0 ;
    LL ret =fac(a)*inv[b]%q*inv[a-b]%q;
    return ret;
}
LL C(LL a,LL b,LL q)
{
    if (b==0) return 1;
    return C(a/q,b/q,q)*Cc(a%q,b%q,q)%q;
}
LL getCAB(LL p,LL q,LL m,LL n,LL d)
{
    LL a,b;
    if (p==q&&m!=n) return 0;
    if (p==q&&m==n)
    {
	if (m%p==0&&m/p%2==0)
	    a=b=m/p/2;
	else
	    return 0;
    }
    LL bu =n*p-m*q,au=m*p-n*q,dwn=p*p-q*q;
    if (bu%dwn!=0||au%dwn!=0) return 0;
    a = au/dwn;
    b = bu/dwn;
    if (a<0||b<0) return 0;
    return C(a+b,a,d);
}

pair <LL,LL> a[N]={};
LL M,N;
LL check(LL i,LL d,LL p ,LL q,LL n)
{
    LL lu=1,ru=1;
    LL rtn =1,cnt=1;
    for (LL j=1,r=i ;j <= n ;++j,r>>=1)
    {
	if ((r&1)==1)
	{
	    if (a[j].fst<=lu||a[j].sec<=ru) return 0;
	    rtn =(rtn*getCAB(p,q,a[j],x-lu,a[j],y-ru,d))%d;
	    cnt*=-1;
	    lu = a[j].fst;
	    ru = a[j].sec;
	}
    }
    rtn = (rtn*getCAB(p,q,N-lu,M-ru,d))%d;
    return rtn*cnt;
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%lld%lld%lld",&n,&m,&r))
	{
	    for ( int i = 1 ; i <= r ; i++) scanf("%lld%lld",&a[i].fst,&a[i].sec);
	    sort(a+1,a+n+1);
	    LL ans = 0 ;
	    for ( LL i = 0 ; i < (1<<n))
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
