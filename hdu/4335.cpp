/* ***********************************************
Author :111qqz
Created Time :Thu 27 Oct 2016 03:43:05 AM CST
File Name :code/hdu/4335.cpp
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
typedef unsigned long long ULL;
using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N =2E5+7;
LL b,p;
LL a[N];
unsigned long long M;
LL euler( LL x)
{
    LL ret = 1;
    for ( LL i = 2 ; i * i <= x ; i++)
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
LL ksm( LL a,LL b,LL k)
{
    LL res = 1;
    while (b>0)
    {
	if (b&1) res = (res * a) % k;
	b = b >> 1LL;
	a = (a*a) % k;
    }
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	int cas = 0;
	while (T--)
	{
	    scanf("%lld%lld%llu",&b,&p,&M);
	    printf("Case #%d: ",++cas);
	    LL mod = euler(p);
	    if (p==1)
	    {
		if (b==0)
		{
		    if (M==18446744073709551615ULL)
			puts("18446744073709551616");
		    else printf("%llu\n",M+1); //把%llu 写成了%lld...wa了半天。。。。。<sad
		}else printf("0\n");
		continue;
	    }
	    LL cnt = 0 ;
	    LL fac = 1;
	    LL i = 0 ;
	    /*
	    for ( i = 0 ; ULL(i)<=M&&fac < mod ; i++)
	    {
		if (ksm(i,fac,p)==b) cnt++;
		fac *= (i+1);
	    }
	    */
	    fac%=mod;
	    for ( ; ULL(i)<=M && fac ; i++)
	    {
		if (ksm(i,fac+mod,p)==b) cnt++;
		fac = fac*(i+1)%mod;
	    }
	    if (ULL(i)<=M)
	    {
		LL num = 0 ;
		for ( int j = 0 ; j < p ; j++)
		{
		    a[j] = ksm(i+j,mod,p);
		    if (a[j]==b) ++num;
		}
		LL bk_num = (M-i+1)/p;
		cnt +=bk_num*num;
		LL Rem = (M-i+1)-bk_num*p;
		for ( int j = 0 ; j < Rem ; j++)
		    cnt += (a[j]==b);
	    }
	    printf("%lld\n",cnt);
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
