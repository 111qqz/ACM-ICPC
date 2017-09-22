/* ***********************************************
Author :111qqz
Created Time :Sun 30 Oct 2016 07:19:02 PM CST
File Name :code/hdu/2837.cpp
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
LL n,m;
LL digit[20];
int cnt;
LL ksm( LL a,LL b,LL mod)
{
   // cout<<"a:"<<a<<" b:"<<b<<" mod:"<<mod<<" ";
    if (b==0) return 1;
    if (a==0) return 0; //任何数的0次方都为1，0的任何除0外次方等于0.
    LL res = 1;
    while (b>0)
    {
	if (b&1) res = ( res * a) % mod;
	b = b >> 1LL;
	a =  ( a*a) % mod;
    }
   // if (res<mod) res = res+mod;
//   if (res==0) res = mod;
   // cout<<" res:"<<res<<endl;
    return res;
}
LL euler( LL x)
{
    LL ret = 1;
    for ( LL i =2 ; i * i <= x ; i++)
    {
	if (x%i==0)
	{
	    x/=i;
	    ret*=(i-1);
	    while (x%i==0)
	    {
		x/=i;
		ret*=i;
	    }
	}
    }
    if (x>1) ret*=(x-1);
    return ret;
}
LL fun( LL n,LL m)
{
    if (n<10) return n;
    LL x = fun(n/10,euler(m));
 //   cout<<"n%10:"<<n%10<<" m:"<<m<<" x:"<<x<<endl;
    if (x>=euler(m)||x==0) x = x%euler(m) + euler(m);
    return ksm(n%10,x,m); 
}
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%lld%lld",&n,&m);
	    printf("%lld\n",fun(n,m)%m);
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
