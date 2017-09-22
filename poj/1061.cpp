/* ***********************************************
Author :111qqz
Created Time :Wed 12 Oct 2016 08:43:02 PM CST
File Name :code/poj/1061.cpp
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
LL x,y,m,n,L;
LL exgcd( LL a,LL b, LL &x,LL &y)
{
    if (b==0)
    {
	x = 1LL;
	y = 0LL;
	return a;
    }
    LL ret = exgcd(b,a%b,x,y);
    LL tmp = x;
    x = y;
    y = tmp - a/b*y;
    return ret;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>x>>y>>m>>n>>L;
	LL tmp1 = y-x;
	LL tmp2 = m-n;
/*	LL X,Y,GCD;
	GCD = exgcd(tmp2,L,X,Y);
	if (tmp1%GCD) puts("Impossible");
	else
	{
	     X = X * (tmp1/GCD);
	     LL gx = L/GCD;
	     if (gx<0) gx = - gx;
	     X = (X%gx +gx)%gx;
	     printf("%lld\n",X);
	}  */
	if (tmp1<0)
	{
	    tmp1 = -tmp1;
	    tmp2 = -tmp2;
	}
	LL X,Y;
	LL GCD;
	if (tmp2<0)
	{
	    GCD = exgcd(-tmp2,L,X,Y);
	    X = -X;
	}
	else
	{
	    GCD = exgcd(tmp2,L,X,Y);
	}
	if (tmp1%GCD)
	{
	    puts("Impossible");
	}
	else
	{
	    LL gx = L/GCD;
	    X = X * tmp1/GCD;
	    X = (X % gx + gx) % gx;
	    printf("%lld\n",X);
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
