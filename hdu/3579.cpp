/* ***********************************************
Author :111qqz
Created Time :Sat 15 Oct 2016 05:17:11 PM CST
File Name :code/hdu/3579.cpp
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
int n;
LL m[10],r[10];
LL exgcd( LL a,LL b,LL &x, LL &y)
{
    if (b==0)
    {
	x = 1;
	y = 0;
	return a;
    }
    LL ret = exgcd(b,a%b,y,x);
    y-=x*(a/b);
    return ret;
}
LL ex_crt(LL *m,LL *r,int n)
{
     LL M = m[1] , R = r[1],x,y,gcd;
     for ( int i = 2 ; i <= n ; i ++)
     {
	 gcd = exgcd(M,m[i],x,y);
	 if ((r[i]-R)%gcd) return -1;
	 LL gx = m[i]/gcd;
	 x = x * (r[i]-R)/gcd;
	 x = x% gx;
	 R = R + x*M;
	 M = M/gcd*m[i];
	 R%=M;
     }
     return R>0?R:R+M;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	int cas = 0 ;
	cin>>T;
	while (T--)
	{
	    scanf("%d",&n);
	    for ( int i = 1 ; i <= n ; i++) scanf("%lld",&m[i]);
	    for ( int i = 1 ; i <= n ; i++) scanf("%lld",&r[i]);
	    printf("Case %d: %lld\n",++cas,ex_crt(m,r,n));
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
