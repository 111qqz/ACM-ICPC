/*************************************************************************
	> File Name: code/hdu/3552.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月09日 星期一 10时20分55秒
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
#include<cctype>
#define fst first              
#define sec second      
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
const int inf = 0x3f3f3f3f;
const double pi = acos(-1.0);
const int N=1E3+7;
int n;
double ang[N];
int dblcmp( double d)
{
    return d<-eps?-1:d>eps;
}
struct point
{
    double x,y;
    point(){}
    point (double _x,double _y):
	x(_x),y(_y){};

    void input()
    {
	scanf("%lf %lf",&x,&y);
    }

    double myatan2(point p)
    {
	double res = atan2(p.y-y,p.x-x);
	return res>0?res:res+2*pi;
    }
}p[N];

int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
   
    while (scanf("%d",&n)!=EOF)
    {
	if (n<=0) break;
	for ( int i = 0 ; i < n ; i++) p[i].input();
	
    	double mx = 0;
	for ( int i = 0 ; i < n ; i++ )
	{
	    int cnt = 0 ;
	    for ( int j = 0 ; j < n ;j++)
	    {
		if (i==j) continue;
		ang[cnt++] = p[i].myatan2(p[j]);
	    }
	    sort(ang,ang+cnt);
	    double mn = 999999;
	    for ( int j = 0 ; j < cnt-1 ; j++)
	    {
		double tmp = ang[j+1]-ang[j];
		if (dblcmp(tmp-pi)>0)   //直线的夹角不可能是钝角
		{
		    tmp = 2*pi-tmp;
		}
		mn = min(tmp,mn);
	    }
	    mx = max(mn,mx);
	}
	printf("%.4f\n",mx*(180.0/pi));

    }
  
   
 #ifndef ONLINE_JUDGE  
  #endif
  fclose(stdin);
	return 0;
}
