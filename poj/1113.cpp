/*************************************************************************
	> File Name: code/poj/1113.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月09日 星期一 16时33分28秒
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
int n,l;
int top;
int dblcmp(int d)
{
    return d<-eps?-1:d>eps;
}
struct point 
{
    double x,y;
    point (){}
    point (double _x,double _y):
	x(_x),y(_y){};

    void input()
    {
	scanf("%lf %lf",&x,&y);
    }
    point operator - (const point &p) const{
	return point (x-p.x,y-p.y);
    }
    double operator ^ (const point  &p) const{
	return x*p.y-y*p.x;
    }
    bool operator < (const point a)const{
	return dblcmp(a.x-x)==0?dblcmp(y-a.y)<0:x<a.x;
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


struct polygon
{
    point p[N];
    int n;
    void input()
    {
	
	p[0].input();
	for ( int i = 1 ; i < n ; i++)
	{
	    p[i].input();
	    if (p[i].y>p[0].y||(p[i].y==p[0].y&&p[i].x>p[0].x))
		swap(p[0],p[i]);
	}
    }

    struct cmp
    {
	point p;
	cmp(const point &p0){p=p0;}
	bool operator()(const point &aa,point &bb)
	{
	    point a=aa,b=bb;
	    int d = dblcmp((a-p)^(b-p));
	    if (d==0)
	    {
		return dblcmp(a.distance(p)-b.distance(p))<0;
	    }
	    else 
		return d>0;
	}

    };

    void getconvex(polygon &convex,int &top)
    {
	int i,j,k;
	sort(p,p+n); //极角排序
	convex.n=n;

	for ( int i = 0 ; i < min (n,2);i++)
	{
	    convex.p[i] = p[i];
	}
	if (n<=2) return ;
	top = convex.n;
	top = 1;
	for ( int i = 2 ; i < n ; i++)
	{
	    while (top&&convex.p[top].sub(p[i]).det(convex.p[top-1].sub(p[i]))<=0) top--;

	    convex.p[++top]=p[i];
	}
    
	   int tmp = top;
	   convex.p[++top] = p[n-2];
	   for (int i = n-3 ; i >= 0 ; i--)
	   {
	       while (top!=tmp&&convex.p[top].sub(p[i]).det(convex.p[top-1].sub(p[i]))<=0)
		   top--;
	       convex.p[++top]=p[i];
	   }
	//   ztop = top;
	   
    };

}pol;

int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   while (scanf("%d %d",&n,&l)!=EOF)
    {
	pol.n=n;
	pol.input();
	polygon conv;
	pol.getconvex(conv,top);
	
	   double res=0;
//	   cout<<"top:"<<top<<endl;
	   for ( int i = 0 ; i < top ; i++)
	       res +=conv.p[i].distance(conv.p[i+1]);
	   res +=conv.p[0].distance(conv.p[top]);

	   res = res + 2*pi*l;
	   printf("%d\n",(int)(res+0.5));

	

    }
  
   
 #ifndef ONLINE_JUDGE  
  #endif
  fclose(stdin);
	return 0;
}
