/*************************************************************************
	> File Name: a.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月06日 星期五 09时48分39秒
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
typedef long long LL;
#define sec second
const int inf = 0x3f3f3f3f;
const double eps=1E-8;
int n;

int dblcmp( double d)
{
    return d<-eps?-1:d>eps;
}

struct  point
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
    point sub(point p)
    {
	return point(x-p.x,y-p.y);
    }
    double det(point p)
    {
	return x*p.y-y*p.x;
    }

};

struct line
{
    point a,b;
    line(){}
    void input()
    {
	a.input();
	b.input();
    }
    point outa()
    {
	return a;
    }
    point outb()
    {
	return b;
    }


    
    int relation(point p)
    {
	int c = dblcmp(p.sub(a).det(b.sub(a)));
	if (c<0) return 1;
	if (c>0) return 2;
	return 3;
    }
    bool parallel(line v)
    {
	return dblcmp(b.sub(a).det(v.b.sub(v.a)))==0;
    }
    //0平行
    //1重合
    //2相交
    int linecrossline(line v)
    {
	if ((*this).parallel(v))
	{
	    return v.relation(a)==3;
	}
	return 2;
    }

    point crosspoint(line v)
    {
	double a1 = v.b.sub(v.a).det(a.sub(v.a));
	double a2 = v.b.sub(v.a).det(b.sub(v.a));
	return point((a.x*a2-b.x*a1)/(a2-a1),(a.y*a2-b.y*a1)/(a2-a1));
    }
}li[15][3];
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
    scanf("%d",&n);
    for ( int i = 1 ; i <= n ; i++)
    {
	li[i][1].input();
	li[i][2].input();
    }

    puts("INTERSECTING LINES OUTPUT");
    for ( int i = 1 ; i <=  n ; i++)
    {
//	li[i][1].outa().output();
//	li[i][1].outb().output();
//	li[i][2].outa().output();
//	li[i][2].outb().output();
	int tmp = li[i][1].linecrossline(li[i][2]);
//	cout<<"tmp:"<<tmp<<endl;
	if (tmp==0)
	{
	    puts("NONE");
	}
	if (tmp==1)
	{
	    puts("LINE");
	}
	if (tmp==2)
	{
	    printf("POINT ");
	    li[i][1].crosspoint(li[i][2]).output();
	}
    }
    puts("END OF OUTPUT");



  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
