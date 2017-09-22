/*************************************************************************
	> File Name: code/poj/1912.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月10日 星期二 12时41分18秒
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
const int N=1E5+7;
const double pi = acos(-1.0);
int n,m;

int dblcmp(double d)
{
    return d<-eps?-1:d>eps;
}
struct point 
{
    double x,y;
    point(){}
    point(double _x,double _y):
    x(_x),y(_y){};

    void input()
    {
	scanf("%lf",&x);
	scanf("%lf",&y);
    }

    bool operator <(point a)const{
	return dblcmp(a.x-x)==0?dblcmp(y-a.y)<0:x<a.x;
    }
    point operator - (const point &p)const{
	return point (x-p.x,y-p.y);
    }

    double operator ^ ( const point &p) const{
	return x*p.y-y*p.x;
    }
    double operator * ( const point &p)const{
	return x*p.y-y*p.x;
    }
    double distance(point p)
    {
	return hypot(x-p.x,y-p.y);
    }
    point sub(point p)
    {
	return point(x-p.x,y-p.y);
    }
    double det(point p)
    {
	return x*p.y-y*p.x;
    }

}p[N];

struct line
{
    point a,b;
    line(){}
    line (point _a,point _b)
    {
	a = _a;
	b = _b;
    }

}li;

struct polygon
{
    int n;
    point p[N];
    void input()
    {
	for ( int i = 0 ; i <  n ; i++)
	    p[i].input();
    }

    struct cmp
    {
	point p;
	cmp(const point &p0){p=p0;}
	bool operator()(const point &aa,const point &bb)
	{
	    point a=aa,b=bb;
	    int d = dblcmp(a.sub(p).det(b.sub(p)));
	    if (d==0)
	    {
		return dblcmp(a.distance(p)-b.distance(p))<0;
	    }
	    return d>0;
	}
    };

    void getconvex(polygon &convex)
    {
	sort(p,p+n);
	convex.n = n ;
	for ( int i = 0 ; i < min(n,2) ; i++)
	{
	    convex.p[i] = p[i];
	}
	if (n<=2) return ;
	int &top =convex.n;
	top = 1;
	for ( int i = 2 ; i  < n ; i++)
	{
	    while (top&&convex.p[top].sub(p[i]).det(convex.p[top-1].sub(p[i]))<=0) top--;

	    convex.p[++top] = p[i];
	}
	int temp = top;
	convex.p[++top] = p[n-2];
	for ( int i = n -3 ; i >= 0 ; i--)
	{
	    while (top!=temp&&convex.p[top].sub(p[i]).det(convex.p[top-1].sub(p[i]))<=0) top--;
	    convex.p[++top] = p[i];
	}
    }

    double theta[N];
    void initLinecrossConvex()
    {
	for ( int i = 0 ; i < n ; i++)
	{
	    point v = p[(i+1)%n] - p[i];
	    theta[i] = atan2(v.y,v.x);
	}
	for ( int i = 1 ; i < n ; i++)
	{
	    if (dblcmp(theta[i-1]-theta[i])>0)
		theta[i] +=2*pi;
	}
    }

    int selectLine(int la ,int lb ,line li)
    {
	if (la>lb) lb +=n;
	int l = la,r=lb,mid;
	while (l<r)
	{
	    mid = l+r+1>>1;
	    if (dblcmp((li.b-li.a)^(p[la]-li.a))*dblcmp((li.b-li.a)^(p[mid%n]-li.a))>=0)
		l = mid ;
	    else r= mid -1;
	}
	return l%n;
    }

    int LinecrossConvex (line l)
    {
	double tnow;
	point v = l.b-l.a;
	tnow =atan2(v.y,v.x);
	if (dblcmp(tnow-theta[0])<0) tnow +=2.0*pi;
	int pl = lower_bound(theta,theta+n,tnow)-theta;
	tnow = atan2(-v.y,-v.x);
	if (dblcmp(tnow-theta[0])<0) tnow +=2.0*pi;
	int pr = lower_bound(theta,theta+n,tnow)-theta;

	pl %= n ;
	pr %= n;

	if (dblcmp(v^(p[pl]-l.a))==0)
	{
//	    pa = pb =p[pl];
	    return 1;
	}
	if (dblcmp(v^(p[pr]-l.a))==0)
	{
//	    pa = pb = p[pr];
	    return 1;
	}
	int d1 = dblcmp(v^(p[pl]-l.a));
	int d2 = dblcmp(v^(p[pr]-l.b));

//	if (dblcmp(v^(p[pl]-l.a))*dblcmp(v^(p[pr]-l.a))>0) return 0;
	cout<<"d1:"<<d1<<" d2:"<<d2<<endl;
	if (d1*d2>0) return 0;
	cout<<"wwwwwwwwwwwhhhh"<<endl;
	int xa = selectLine (pl , pr , l);
	int xb = selectLine (pr , pl , l);
	if (xa>xb) swap(xa,xb);
	if (dblcmp(v^(p[(xa+1)%n]-p[xa]))==0)
	{
//	    pa = p[xa];
//	    pb = p[(xa+1)%n];
	    return 2;
	}
	if (dblcmp(v^(p[(xb+1)%n]-p[xb]))==0)
	{
//	    pa = p[xb];
//	    pb = p[(xb+1)%n];
	    return 2;
	}
	return 3;

	
    }

}pol,conv;
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
   scanf("%d",&n);
   pol.n = n;
   pol.input();
   pol.getconvex(conv);

 //   bool flag = false;
    while (scanf("%lf %lf %lf %lf",&li.a.x,&li.a.y,&li.b.x,&li.b.y)!=EOF)
    {
	int ret =conv.LinecrossConvex (li);
	cout<<"ret:"<<ret<<endl;
	    if (ret==0)
	    {
		puts("BAD");
	    }
	    else
	    {
		puts("GOOD");
	    }
    }
  
   
 #ifndef ONLINE_JUDGE  
  #endif
  fclose(stdin);
	return 0;
} 
