/*************************************************************************
	> File Name: code/2015summer/#6/II.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月01日 星期六 03时09分18秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x7fffffff;


LL dis(LL x1,LL x2,LL y1,LL y2,LL z1,LL z2)
{
    
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2);
    
}
int main()
{
    int T;                 //整体算法是寻找距离球最近的点，比较这个点到球心的距离和半径
			    // 。。。判断了边+点+面还没A的我好傻逼啊。。。。。。。。sad
			    // 卧槽，读错题了，长方体是实心的啊喂！怪不得我想的那么麻烦！
    cin>>T;
    while (T--)
    {
	LL tx,ty,tz;
	LL x1 = inf;
	LL x2 = -inf;
	LL y1 = inf;
	LL y2 = -inf;
	LL z1 = inf;
	LL z2 = -inf;
	for ( int i = 1 ; i <= 8 ; i++ )
	{

	    scanf("%lld %lld %lld",&tx,&ty,&tz);
	    x1 = min(tx,x1);
	    x2 = max(tx,x2);
	    y1 = min(ty,y1);
	    y2 = max(ty,y2);
	    z1 = min(tz,z1);
	    z2 = max(tz,z2);
	}
	LL bx,by,bz,r;
	    LL x,y,z;
	scanf("%lld %lld %lld %lld",&bx,&by,&bz,&r);
	x = bx;
	y = by;
	z = bz;
	if (x>x2) x=x2;
	if (x<x1) x=x1;
	if (y>y2) y=y2;
	if (y<y1) y=y1;
	if (z>z2) z=z2;
	if (z<z1) z=z1;
	if (r*r>=dis(x,bx,y,by,z,bz))
	{
	    puts("Yes");
	}
	else
	{
	    puts("No");
	}


    }
  
	return 0;
}
