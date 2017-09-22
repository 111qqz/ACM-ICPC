/*************************************************************************
    > File Name: code/hdu/1086.cpp
    > Author: 111qqz
    > Email: rkz2013@126.com 
    > Created Time: 2015年11月06日 星期五 13时41分46秒
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
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const double eps = 1E-8;
typedef long long LL;
#define sec second
const int inf = 0x3f3f3f3f;
const int N=105;
int n;
int dblcmp(double d)
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
	scanf("%lf%lf",&x,&y);
    }
    point sub(point p)
    {
	return point(x-p.x,y-p.y);
    }
    double det(point p)
    {
	return x*p.y-y*p.x;
    }
    double dot(point p)
    {
	return x*p.x+y*p.y;
    }
};

struct line
{
    point a,b;
    void input()
    {
	a.input();
	b.input();
    }
    int segcrossseg(line v)
    {
	int d1=dblcmp(b.sub(a).det(v.a.sub(a)));
	int d2=dblcmp(b.sub(a).det(v.b.sub(a)));
	int d3=dblcmp(v.b.sub(v.a).det(a.sub(v.a)));
	int d4=dblcmp(v.b.sub(v.a).det(b.sub(v.a)));
	if ((d1^d2)==-2&&(d3^d4)==-2) return 2;
	return (d1==0&&dblcmp(v.a.sub(a).dot(v.a.sub(b)))<=0||
		d2==0&&dblcmp(v.b.sub(a).dot(v.b.sub(b)))<=0||
		d3==0&&dblcmp(a.sub(v.a).dot(a.sub(v.b)))<=0||
		d4==0&&dblcmp(b.sub(v.a).dot(b.sub(v.b)))<=0);
    }
}li[N];
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
   
   while (~scanf("%d",&n)!=EOF&&n)
    {
	for ( int i = 1 ; i <= n ; i++) li[i].input();
	int cnt = 0;
	for ( int i = 1 ; i < n ; i++)
	    for ( int j = i+1 ; j <= n ; j++)
	    {

		if (li[i].segcrossseg(li[j]))
		    cnt++;
	    }
	printf("%d\n",cnt);
    }

  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
