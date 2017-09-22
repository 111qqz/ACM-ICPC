/* ***********************************************
Author :111qqz
Created Time :Thu 13 Oct 2016 03:57:06 PM CST
File Name :code/poj/2115.cpp
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
LL a,b,c,k;
LL exgcd(LL a,LL b,LL &x,LL &y)
{
    if (b==0)
    {
	x = 1;
	y = 0;
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
	while (~scanf("%lld%lld%lld%lld",&a,&b,&c,&k))
	{
	    if (a==0&&b==0&&c==0&&k==0) break;

	    k =  1LL<<k;
	    LL X,Y,GCD;
	    GCD = exgcd(c,k,X,Y);
	    if ((b-a)%GCD)
	    {
		puts("FOREVER");
		continue;
	    }
	    else
	    {
		X = X * ((b-a)/GCD);
		LL gx = k/GCD;
		X = (X % gx + gx) % gx;
		printf("%lld\n",X);
	    }

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
