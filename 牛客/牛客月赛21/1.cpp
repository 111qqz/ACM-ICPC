#include <bits/stdc++.h>
using namespace std;

#define eps 1e-8
#define pi  3.1415926535897932385

struct Point
{
    double x,y;
    Point(double a=0,double b=0){x=a;y=b;}
};


//向量的加减及数乘
Point operator + (Point a,Point b)
{
    return Point(a.x+b.x,a.y+b.y);
}

Point operator - (Point a,Point b)
{
    return Point(a.x-b.x,a.y-b.y);
}

Point operator * (Point a,double k)
{
    return Point(a.x*k,a.y*k);
}

Point operator / (Point a,double k)
{
    return Point(a.x/k,a.y/k);
}

//求质量均匀分布的三角形的重心
Point TriangleMassCenter(Point a,Point b,Point c)
{
    return (a+b+c)/3.0;
}




Point Circum(Point a,Point b,Point c){ //三角形外心 
	double x1=a.x,y1=a.y;
	double x2=b.x,y2=b.y;
	double x3=c.x,y3=c.y;
	
	double a1=2*(x2-x1);
	double b1=2*(y2-y1);
	double c1=x2*x2+y2*y2-x1*x1-y1*y1;
	
	double a2=2*(x3-x2);
	double b2=2*(y3-y2);
	double c2=x3*x3+y3*y3-x2*x2-y2*y2;
	
	double x=(c1*b2-c2*b1)/(a1*b2-a2*b1);
	double y=(a1*c2-a2*c1)/(a1*b2-a2*b1);
	
	return Point(x,y);
}

void debug(Point X)
{
    printf("%.3f %.3f \n",X.x,X.y);
}
int x1,Y1,x2,y2,x3,y3;
int main()
{
    cin>>x1>>Y1>>x2>>y2>>x3>>y3;
    Point A(x1,Y1),B(x2,y2),C(x3,y3);
    // debug(A);
    // debug(B);
    // debug(C);
    Point ans = Circum(A,B,C);
    printf("%.3f %.3f\n",ans.x,ans.y);

    return 0;

    
} // namespace std;

