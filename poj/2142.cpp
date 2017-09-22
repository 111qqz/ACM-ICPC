/* ***********************************************
Author :111qqz
Created Time :Thu 13 Oct 2016 04:23:13 PM CST
File Name :code/poj/2142.cpp
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
LL a,b,d;
LL exgcd( LL a,LL b,LL &x,LL &y)
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
LL num ( LL x)
{
    if (x<0) return -x;
    return x;
}
LL cal( LL x,LL y)
{
    return a*num(x)+b*num(y);
}
bool ok( LL x,LL y,LL gx,LL gy)
{
    if (num(x)+num(y)>num(x+gx)+num(y-gy)) return true;
    if (num(x)+num(y)==num(x+gx)+num(y-gy)&&cal(x,y)>cal(x+gx,y-gy)) return true;
    return false;
}
bool ok2( LL x,LL y,LL gx,LL gy)
{
    if (num(x) + num(y) > num(x-gx) + num(y+gy)) return true;
    if (num(x) + num(y) ==num (x-gx) + num(y+gy)&&cal(x,y)>cal(x-gx,y+gy)) return true;
    return false;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%lld%lld%lld",&a,&b,&d))
	{
	    if (a==0&&b==0&&d==0) break;
	    LL x,y;
	    LL gcd = exgcd(a,b,x,y);
	    x = x * d/gcd;
	    y = y * d/gcd;
	    LL gx = b/gcd;
	    LL gy = a/gcd;
//	    for ( int i = -50000 ; i <= 50000 ; i++)
//	    {
//		LL sum1 = num(x+i*gx) + num(y-i*gy);
//		LL sum2 = num(x+i*g)
//	    }
	    //LL mn = num(x) + num(y);
	    while (ok(x,y,gx,gy))
	    {
		x = x + gx;
		y = y - gy;
//		if (num(x) + num(y)<mn)
//		{
//		    mn = num(x) + num(y);
//		}
//		else break;
	    }
	    while ( ok2(x,y,gx,gy))
	    {
		x = x-gx;
		y = y+gy;
//		if (num(x) + num(y)<mn)
//		{
//		    mn = num(x) + num(y);
//		}
//		else break;
	    }
	    /*
	    LL mn2 = cal(x,y);
	    while ((num(x) + num(y) == num(x+gx) + num(y-gy)) && (cal(x,y)>cal(x+gx,y-gy)))
	    {
		x = x + gx;
		y = y - gy;
//		if (cal(x+gx,y-gy)<mn2)
//		{
//		    mn2 = cal(x+gx,y-gy);
//		}
//		else break;
	    }
	    while ((num(x) + num(y) == num(x+gx) + num(y-gy)) && (cal(x,y)>cal(x-gx,y+gy)))
	    {
		x = x - gx;
		y = y - gy;
//		if (cal(x-gx,y+gy)<mn2)
//		{
//		    mn2 = cal(x-gx,y+gy);
//		}else break;
	    }  */
	    
	    printf("%lld %lld\n",num(x),num(y));
	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
