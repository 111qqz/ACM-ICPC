/*************************************************************************
	> File Name: code/hdu/3264.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月06日 星期五 14时57分47秒
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
const int N=25;
const double pi =acos(-1.0);
int n;
int dblcmp(double d)
{
    return d<-eps?-1:d>eps;
}
struct point
{
    double x,y;
    point(){}
    point(double _x,double _y):
	x(_x),y(-y){};
    void input()
    {
	scanf("%lf%lf",&x,&y);
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
    double distance(point p)
    {
	return hypot(x-p.x,y-p.y);
    }
};

struct circle
{
    point p;
    double r;
    circle(){}
    circle(point _p,double _r):
	p(_p),r(_r){};
    void input()
    {
	p.input();
	scanf("%lf",&r);
    }
    double area()
    {
	return pi*r*r;
    }

    int relationcircle(circle v)
    {
	double d=p.distance(v.p);
	if (dblcmp(d-r-v.r)>0) return 5;
	if (dblcmp(d-r-v.r)==0) return 4;
	double l = fabs(r-v.r);
	if (dblcmp(d-r-v.r)<0&&dblcmp(d-l)>0) return 3;
	if (dblcmp(d-l)==0) return 2;
	if (dblcmp(d-l)<0) return 1;
    }

    double areacircle(circle v)
    {
	int rel = relationcircle(v);
	if (rel>=4) return 0.0;
	if (rel<=2) return min(area(),v.area());
	double d=p.distance(v.p);
	double hf=(r+v.r+d)/2.0;
	double ss=2*sqrt(hf*(hf-r)*(hf-v.r)*(hf-d));
	double a1=acos((r*r+d*d-v.r*v.r)/(2.0*r*d));
	a1 = a1 *r*r;
	double a2=acos((v.r*v.r+d*d-r*r)/(2.0*v.r*d));
	a2 = a2*v.r*v.r;
	return a1+a2-ss;
    }
}cir[N];

bool judge(double rr)
{
    for ( int i = 1 ; i <= n ; i++)
    {
	circle tmp = cir[i];
	tmp.r = rr;
	for (int   j = 1; j <= n ; j++)
	{
	    double crossarea = tmp.areacircle(cir[j]);
	   // cout<<"cross_area:"<<crossarea<<endl;
	    if (crossarea<cir[j].area()/2.0)
		break;
	    if (j==n) return true;
	}
	
    }
    return false;

}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
   int T;
   scanf("%d",&T);
   while ( T-- )
    {
	scanf("%d",&n);
	for ( int i = 1  ; i <=  n ; i++) cir[i].input();
	double l=0,r=1E5;
	while (dblcmp(r-l)>0)
	{
	   // cout<<"l:"<<l<<" r:"<<r<<endl;
	    double mid = (l+r)/2.0;
	    if (judge(mid))
		r = mid;
	    else l=mid;

	}
	printf("%.4f\n",r);

    }
  
   
 #ifndef ONLINE_JUDGE  
  #endif
  fclose(stdin);
	return 0;
}
