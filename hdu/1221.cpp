/* ***********************************************
Author :111qqz
Created Time :2015年12月20日 星期日 17时50分26秒
File Name :code/hdu/1221.cpp
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
#define y1 lovejxy
using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;

double x,y,r,x1,y1,x2,y2;
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


    double dis (point p)
    {
	return hypot(x-p.x,y-p.y);
    }

    point sub(point p)
    {
	return point(x-p.x,y-p.y);
    }
    double dot(point p)
    {
	return x*p.x+y*p.y;
    }
    double det(point p)
    {
	return x*p.y-y*p.x;
    }


}p[5],cir;

struct line
{
    point a,b;
    line(){}
    line(point _a,point _b)
    {
	a = _a;
	b = _b;
    }
    double length()
    {
	return a.dis(b);
    }
    double dispointtoline(point p)
    {
	return fabs(p.sub(a).det(b.sub(a)))/length();
    }
    double dispointtoseg(point p)
    {
	if (dblcmp(p.sub(b).dot(a.sub(b)))<0||dblcmp(p.sub(a).dot(b.sub(a)))<0)
	{
	    return min(p.dis(a),p.dis(b));
	}
	return dispointtoline(p);
    }
}li[5];
bool ok ()
{
    int cnt  = 0 ;
    for (int i =1 ; i <= 4 ; i++)   //如果与四个点全部在圆内部，那么矩形在圆内部！	
				    //notice！不要忘记圆比矩形大的情况
    {
	if (dblcmp(cir.dis(p[i])-r)<0)
	    cnt++;   //与四个顶点相交   
    }
    if (cnt==4) return false;
    

    for ( int i = 1 ; i <= 4 ; i++)
    {
	if (dblcmp(li[i].dispointtoseg(cir))<=r) return true;
    }
    return false;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%lf %lf %lf %lf %lf %lf %lf",&cir.x,&cir.y,&r,&x1,&y1,&x2,&y2);
	    if (dblcmp(x1-x2)>0)
	    {
		swap(x1,x2);
		swap(y1,y2);
	    }
	
		p[1].x = x1;
		p[1].y = y1;

		p[2].x = x2;
		p[2].y = y1;

		p[3].x = x2;
		p[3].y = y2;

		p[4].x =x1;
		p[4].x =y2;

		li[1].a=p[1];
		li[1].b=p[2];

		li[2].a=p[2];
		li[2].b=p[3];

		li[3].a=p[3];
		li[3].b=p[4];

		li[4].a=p[4];
		li[4].b=p[1];
		if (ok())
		{
		    puts("YES");
		}
		else
		{
		    puts("NO");
		}
	    

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
