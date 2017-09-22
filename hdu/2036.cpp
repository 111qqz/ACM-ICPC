/*************************************************************************
	> File Name: code/hdoj/2036.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月06日 星期五 12时05分30秒
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
const int N=105;
int n;
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
    double det(point p)
    {
	return x*p.y-y*p.x;
    }
};
struct  polygon
{
    point  p[N];
    void input()
    {
	for ( int i = 0 ; i < n ; i++)
	{
	    p[i].input();
	}
    }
    double getarea()
    {
	double sum= 0 ;
	int i;
	for ( int i = 0 ; i < n ; i++ )
	{
	    sum+=p[i].det(p[(i+1)%n]);
	}
	return fabs(sum)/2;
    }
}pol;
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
   while (scanf("%d",&n)!=EOF&&n)
    {
	pol.input();
	printf("%.1f\n",pol.getarea());
    }

  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
