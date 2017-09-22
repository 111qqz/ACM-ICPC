/* ***********************************************
Author :111qqz
Created Time :Wed 26 Oct 2016 08:29:33 PM CST
File Name :code/fzu/1759.cpp
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
const int N = 1E6+7;
char st[N];
LL a,b,c;

LL euler( LL x)
{
    LL ret = 1;
    for ( LL i = 2 ; i *i <= x ; i++)
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
    LL res = 1LL;
    while (b>0)
    {
	if (b&1) res  = (res * a) % k;
	b = b >> 1LL;
	a = ( a * a ) % k;
    }
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%lld %s %lld",&a,st,&c))
	{
	    cout<<"a:"<<a<<" st:"<<st<<" c:"<<c<<endl;
	    LL mod = euler(c);
	    int len = strlen(st);
	    b = 0 ;
	    for ( int i = 0 ;i < len ; i++)
	    {
		LL val = st[i]-'0';
		b = ((b * 10LL)%mod + val)%mod;
	    }
	    LL ans = ksm(a,b%mod+mod,c);
	    printf("%lld\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
