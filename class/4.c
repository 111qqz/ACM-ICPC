/*************************************************************************
	> File Name: code/class/4.c
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月11日 星期三 17时28分44秒
 ************************************************************************/

#include<stdio.h>
#include <math.h>
#define eps 1E-8
double a,b,c;
double x1,x2,x;

int dblcmp(double d)
{
    return d<-eps?-1:d>eps;
}
struct comp
{
    double a,b;
}cx1,cx2;
int main()
{
    scanf("%lf %lf %lf",&a,&b,&c);
    if (dblcmp(a)==0)
    {
	x = -c/b;
	printf("方程有一个解:%f\n",x);
    }
    else
    {
	double d =b*b-4*a*c;
	int res = dblcmp(d);
	if (res<0)
	{
	   // printf("方程无解\n");
	        cx1.a = cx2.a = (-b)*1.0/(2*a*1.0);
		cx1.b = -sqrt(-d)*1.0/(2*a*1.0);
		cx2.b = sqrt(-d)*1.0/(2*a*1.0);
		int d1 = dblcmp(cx1.b);
		int d2 = dblcmp(cx2.b);
		printf("方程有两个不相等的虚数根：\n");
		

		if (d1>0)
		{
		    printf("x1: %.4f+%.4fi\n",cx1.a,cx1.b);
		}
		else
		{
		    printf("x1: %.4f%.4fi\n",cx1.a,cx1.b);
		}
		if (d2>0)
		{
		    printf("x2: %.4f+%.4fi\n",cx2.a,cx2.b);
		}
		else
		{
		    printf("x2: %.4f%.4fi/n",cx2.a,cx2.b);
		}
    
	}
	if (res==0)
	{
	    x1 = x2 = (-b+sqrt(d))*1.0/(2*a*1.0);
	    printf("方程有两个相等的实数根: %f %f\n",x1,x2);
	}
	if (res>0)
	{
	    x1 = (-b-sqrt(d))*1.0/(2*a*1.0);
	    x2 = (-b+sqrt(d))*1.0/(2*a*1.0);
	    printf("方程有两个不等的实数根： %f %f\n",x1,x2);
	}
    }
}
