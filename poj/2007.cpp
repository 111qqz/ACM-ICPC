/*************************************************************************
	> File Name: code/poj/2007.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月08日 星期日 19时35分54秒
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
const int N=55;
int cnt;
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
    bool input()
    {
	return scanf("%lf %lf",&x,&y)!=EOF;
    }
    point operator - (const point &p)const
    {
	return point(x-p.x,y-p.y);
    }

    double operator^(const point &p)const
    {
	return x*p.y-y*p.x;
    }
}p[N];

bool cmp(point a,point b)
{
    point c;
    c.x=0.0;
    c.y=0.0;
    double tmp =(a-c)^(b-c);
 //   cout<<"tmp:"<<tmp<<endl;
    return tmp>0;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
    cnt = 0 ;
   while (p[cnt].input())  cnt++;
   
   sort(p+1,p+cnt,cmp);
   for ( int i = 0 ; i < cnt ; i++) printf("(%.0f,%.0f)\n",p[i].x,p[i].y);

  
   
 #ifndef ONLINE_JUDGE  
  #endif
  fclose(stdin);
	return 0;
}
