/* ***********************************************
Author :111qqz
Created Time :Wed 26 Oct 2016 06:22:39 PM CST
File Name :code/hdu/4704.cpp
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
const int N=1E5+7;
const LL mod = 1E9+7;
char st[N];
int len;
LL n;
LL ksm(LL a,LL b)
{
    LL res = 1LL;
    while (b>0)
    {
	if (b&1) res = (res * a) % mod;
	b = b >> 1LL;
	a = ( a*a ) % mod;
    }
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%s",st))
	{
	    len = strlen(st);
	    n = 0 ;
	    for ( int i = 0 ; i < len ; i++)
	    {
		LL val = st[i]-'0';
		n = ((n * 10LL)%(mod-1) + val)% (mod-1);
	    }
	    n = (n-1+mod-1)%(mod-1);
	    LL ans = ksm( 2,n );
	    printf("%lld\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
