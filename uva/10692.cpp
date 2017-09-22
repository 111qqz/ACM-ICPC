/* ***********************************************
Author :111qqz
Created Time :Wed 26 Oct 2016 07:07:27 PM CST
File Name :code/uva/10692.cpp
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
char st[20];
LL n,m;
LL a[15];
LL ksm( LL a,LL b,LL k)
{
    LL res = 1;
    while (b>0)
    {
	if (b&1) res = (res * a )% k;
	b = b >> 1;
	a = ( a * a) % k;
    }
    return res;
}
LL euler( LL x)
{
    LL ret = 1 ;
    for ( LL i = 2 ; i*i <= x ; i++)
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
LL phi[20];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int cas = 0 ;
	while (~scanf("%s",st))
	{
	    ms(a,0);
	    ms(phi,0);
	  //  cout<<"st:"<<st<<endl;
	    if (st[0]=='#') break;
	    int len = strlen(st);
	    m = 0 ;
	    for ( int i = 0 ; i < len ; i++)
	    {
		LL val = st[i]-'0';
		m = m * 10 + val;
	    }
	    scanf("%lld",&n);
	    phi[0] = m;
	    for ( int i = 1; i <= n ; i++) scanf("%lld",a+i);
	    LL fi = euler(m);
	    for ( int i = 1 ; i <= n-1 ;i++)
	    {
		phi[i] = fi;
		fi = euler(fi);
	    }
	    for ( int i = n-1 ; i >=1 ; i--)
	    {
		a[i] = ksm(a[i],(a[i+1]%phi[i]+phi[i]),phi[i-1]);
	    }
	    printf("Case #%d: %lld\n",++cas,a[1]%m);  //考虑n为1的情况
	    ms(st,0);
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
