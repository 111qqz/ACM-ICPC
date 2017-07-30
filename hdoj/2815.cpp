/* ***********************************************
Author :111qqz
Created Time :Mon 24 Jul 2017 09:43:41 PM CST
File Name :2815.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define PB push_back
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
LL k,p,n;
map<LL,LL>mp;
LL ksm(LL a,LL b,LL p)
{
    LL res = 1LL;
    while (b)
    {
        if (b&1) res = res * a % p;
        b = b>>1LL;
        a = a * a % p;
    }
    return res;
}
LL gcd( LL a,LL b){return b?gcd(b,a%b):a;}
LL BSGS(LL a,LL b,LL p)
{
    a%=p;
    b%=p;
    //if (a==0&&b==0) return 0;
    //if (a==0) return -1;
    if (b==1) return 0;
    int cnt = 0 ;
    LL t = 1;
    for (int g = gcd(a,p); g!=1 ; g = gcd(a,p))
    {
        if (b%g) return -1;
        p/=g;
        b/=g;
        t=t*a/g%p;
        cnt++;
        if (b==t) return cnt;
    }
    mp.clear();
    int m = ceil(sqrt(double(p)));
    LL base = b ;
    for ( int i = 0 ; i < m ; i++)
    {
        mp[base] =  i;
        base = base * a % p;
    }
    base = ksm(a,m,p);
    LL ret = t ;
    for ( int i = 1 ; i <= m+1 ; i++)
    {
        ret = ret * base % p;
        if (mp.count(ret)) return i*m-mp[ret]+cnt;
    }
    return -1;
}
int main()
{
    #ifndef  ONLINE_JUDGE 
    freopen("./in.txt","r",stdin);
  #endif
    //k^(D+1))-1=n (%p)  求D
    while (~scanf("%lld%lld%lld",&k,&p,&n))
    {
         if (p==1) {
         puts("Orz,I can’t find D!");
         continue;
        }
	 n++;
         LL ans = BSGS(k,n,p);
             if (ans==-1) puts("Orz,I can’t find D!");
             else printf("%lld\n",--ans);
    }

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
