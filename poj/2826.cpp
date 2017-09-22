/*************************************************************************
	> File Name: code/poj/2826.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月06日 星期五 16时07分21秒
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
const double eps = 1E-10;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
const int inf = 0x3f3f3f3f;
const double pi = acos(-1.0);
int dblcmp(double d)
{
    return d < -eps ? -1 : d > eps;
}
inline double sqr(double x){return x*x;}
struct point
{
    double x,y;
    point(){}
    point(double _x,double _y):
    x(_x),y(_y){};
    void input()
    {
        scanf("%lf%lf",&x,&y);
    }
    void output()
    {
        printf("%.2f %.2f\n",x,y);
    }
    bool operator==(point a)const
    {
        return dblcmp(a.x-x)==0&&dblcmp(a.y-y)==0;
    }
    bool operator<(point a)const
    {
        return dblcmp(a.x-x)==0?dblcmp(y-a.y)<0:x<a.x;
    }
    double len()
    {
        return hypot(x,y);
    }
    double len2()
    {
        return x*x+y*y;
    }
    double distance(point p)
    {
        return hypot(x-p.x,y-p.y);
    }
    double distance2(point p)
    {
        return sqr(x-p.x)+sqr(y-p.y);
    }
    point add(point p)
    {
        return point(x+p.x,y+p.y);
    }
    point operator + (const point & p) const{
        return point(x+p.x,y+p.y);
    }
    point sub(point p)
    {
        return point(x-p.x,y-p.y);
    }
    point operator - (const point & p) const{
        return point(x-p.x,y-p.y);
    }
    point mul(double b)
    {
        return point(x*b,y*b);
    }
    point div(double b)
    {
        return point(x/b,y/b);
    }
    double dot(point p)
    {
        return x*p.x+y*p.y;
    }
    double operator * (const point & p) const{
        return x*p.x+y*p.y;
    }
    double det(point p)
    {
        return x*p.y-y*p.x;
    }
    double operator ^ (const point & p) const{
        return x*p.y-y*p.x;
    }
    double rad(point a,point b)
    {
    	point p=*this;
    	return fabs(atan2(fabs(a.sub(p).det(b.sub(p))),a.sub(p).dot(b.sub(p))));
	}
    point trunc(double r)
	{
		double l=len();
		if (!dblcmp(l))return *this;
		r/=l;
		return point(x*r,y*r);
	}
    point rotleft()
    {
        return point(-y,x);
    }
    point rotright()
    {
        return point(y,-x);
    }
    point rotate(point p,double angle)//绕点p逆时针旋转angle角度
    {
        point v=this->sub(p);
        double c=cos(angle),s=sin(angle);
        return point(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
    }

    int sameside(point p1,point p2)
    {
//	p1.output();
//	p2.output();
	if (dblcmp(x-p2.x)<=0&&dblcmp(p2.x-p1.x)<=0) return 1;
	if (dblcmp(x-p2.x)>=0&&dblcmp(p2.x-p1.x)>=0) return 1;
	return 0;
    }
    double gettrianglearea(point b,point c)
    {
	return ((b.x-x)*(c.y-y)-(b.y-y)*(c.x-x))/2;
    }
};
struct line
{
    point a,b;
    line(){}
    line(point _a,point _b)
    {
        a=_a;
        b=_b;
    }
    bool operator==(line v)
    {
    	return (a==v.a)&&(b==v.b);
    }
    //倾斜角angle
    line(point p,double angle)
    {
    	a=p;
    	if (dblcmp(angle-pi/2)==0)
    	{
    		b=a.add(point(0,1));
    	}
    	else
    	{
    		b=a.add(point(1,tan(angle)));
    	}
    }
    //ax+by+c=0
    line(double _a,double _b,double _c)
    {
    	if (dblcmp(_a)==0)
    	{
    		a=point(0,-_c/_b);
    		b=point(1,-_c/_b);
    	}
    	else if (dblcmp(_b)==0)
    	{
    		a=point(-_c/_a,0);
    		b=point(-_c/_a,1);
    	}
    	else
    	{
    		a=point(0,-_c/_b);
    		b=point(1,(-_c-_a)/_b);
    	}
    }
    void input()
    {
        a.input();
        b.input();
    }
    void adjust()  //调整为由低指向高
    {
    	//if (b<a)swap(a,b);
	//if (a.y>b.y) swap(a,b);
	if (dblcmp(a.y-b.y)>0) swap(a,b);
    }
    double length()
    {
        return a.distance(b);
    }
    double getk()
    {
//	printf("*********\na.x: %f a.y %f b.x : %f b.y : %f\n ****************\n",a.x,a.y,b.x,b.y);
	return (b.y-a.y)/(b.x-a.x);
    }
    double angle()//直线倾斜角 0<=angle<180
	{
		double k=atan2(b.y-a.y,b.x-a.x);
		if (dblcmp(k)<0)k+=pi;
		if (dblcmp(k-pi)==0)k-=pi;
//		cout<<"ang1:"<<k<<endl;
//		cout<<"k:"<<tan(k)<<endl;
		return k;
	}
    //点和线段关系
    //1 在逆时针
    //2 在顺时针
    //3 平行
    int relation(point p)
    {
        int c=dblcmp(p.sub(a).det(b.sub(a)));
        if (c<0)return 1;
        if (c>0)return 2;
        return 3;
    }
    bool pointonseg(point p)
    {
        return dblcmp(p.sub(a).det(b.sub(a)))==0&&dblcmp(p.sub(a).dot(p.sub(b)))<=0;
    }
    bool parallel(line v)
    {
        return dblcmp(b.sub(a).det(v.b.sub(v.a)))==0;
    }
    //2 规范相交
    //1 非规范相交 ()
    //0 不相交
    int segcrossseg(line v)
    {
        int d1=dblcmp(b.sub(a).det(v.a.sub(a)));
        int d2=dblcmp(b.sub(a).det(v.b.sub(a)));
        int d3=dblcmp(v.b.sub(v.a).det(a.sub(v.a)));
        int d4=dblcmp(v.b.sub(v.a).det(b.sub(v.a)));
        if ((d1^d2)==-2&&(d3^d4)==-2)return 2;
        return (d1==0&&dblcmp(v.a.sub(a).dot(v.a.sub(b)))<=0||
                d2==0&&dblcmp(v.b.sub(a).dot(v.b.sub(b)))<=0||
                d3==0&&dblcmp(a.sub(v.a).dot(a.sub(v.b)))<=0||
                d4==0&&dblcmp(b.sub(v.a).dot(b.sub(v.b)))<=0);
    }
    int linecrossseg(line v)//*this seg v line
    {
        int d1=dblcmp(b.sub(a).det(v.a.sub(a)));
        int d2=dblcmp(b.sub(a).det(v.b.sub(a)));
        if ((d1^d2)==-2)return 2;
        return (d1==0||d2==0);
    }
    point crosspoint(line v)
    {
        double a1=v.b.sub(v.a).det(a.sub(v.a));
        double a2=v.b.sub(v.a).det(b.sub(v.a));
        return point((a.x*a2-b.x*a1)/(a2-a1),(a.y*a2-b.y*a1)/(a2-a1));
    }
}li[10];
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   int T;
   scanf("%d",&T);
   while (T--)
   {                                          
	li[1].input();li[1].adjust();
	li[2].input();li[2].adjust();
	if (li[1].segcrossseg(li[2])==0)  //不相交
	{
	    puts("0.00");
	    continue;
	}
//	if (li[1].a.y==li[1].b.y||li[2].a.y==li[2].b.y)   //有一边平行x轴
//	{
//	    puts("0.00");
//	    continue;
//	}
//	if (li[1]==li[2])
//	{
//	    puts("0.00"); //重合
//	    continue;
//	}
	
	point crossp=li[1].crosspoint(li[2]);
	point lowp;
	int anotherline;
	if (li[1].b.y<li[2].b.y)
	{
	    lowp=li[1].b;
	    anotherline=2;
	}
	else
	{
	    lowp=li[2].b;
	    anotherline=1 ;
	}
//	if (dblcmp(ang)==0)  //貌似并不可能出现...
//	{
//	    puts("0.00");
//	    continue;
//	}
	point p3;
	
	if (dblcmp(li[anotherline].a.x-li[anotherline].b.x)==0)
	{
	    p3.x=li[anotherline].a.x;
	    p3.y=lowp.y;
	}
	else
	{
	   // ang = li[anotherline].angle();
	    double dy =lowp.y-li[anotherline].a.y;
	  //  cout<<"ang2:"<<ang<<endl;
	  //  cout<<"anotherline:"<<anotherline<<endl;
	    double k = li[anotherline].getk();
	  //  cout<<"dy:"<<dy<<" k:"<<k<<endl;
	    p3.x=li[anotherline].a.x+dy*1.0/k;
	    p3.y=lowp.y;
	}
	double h = lowp.y-crossp.y;
	if (dblcmp(h)==0)
	{
	    puts("0.00");
	    continue;
	}
	if (p3.sameside(li[anotherline].b,li[anotherline%2+1].b)==1)
	{
	    puts("0.00");
    
	  //  cout<<"p3:";p3.output();
	    continue;
	}
	double c = fabs(lowp.x-p3.x);
	
//	cout<<"low.x:"<<lowp.x<<" p3.x:"<<p3.x<<endl;  //p3.x有问题！
//	cout<<"h:"<<h<<" c:"<<c<<endl;
	double ans = h*c/2;
//	double ans = lowp.gettrianglearea(crossp,p3);
	printf("%.2f\n",fabs(ans));


   }
  
   
 #ifndef ONLINE_JUDGE  
  #endif
  fclose(stdin);
	return 0;
}
