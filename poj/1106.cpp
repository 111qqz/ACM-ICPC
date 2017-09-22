/*************************************************************************
	> File Name: code/poj/1106.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月09日 星期一 09时28分51秒
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
const  int N=2E4+7;

int n;
double r;
int dblcmp( double d)
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
	scanf("%lf %lf",&x,&y);
    }
    

    point operator - (const point &p)const{
	return point(x-p.x,y-p.y);
    }
    double operator ^(const point &p)const{
	return x*p.y-y*p.x;
    }
    double dis(point p)
    {
	return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
    }
}tmp[N],c,p[N];
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
    while (~scanf("%lf %lf %lf",&c.x,&c.y,&r))
    {
	int cnt = 0 ;
	if (dblcmp(r)<=0) break;
	scanf("%d",&n);
	for ( int i = 0 ;i  < n ; i ++)
	{
	    tmp[i].input();
	    double d =c.dis(tmp[i]);
	    if (dblcmp(d-r)<=0)
	    {
		//p[cnt]=tmp[i];
		p[cnt].x=tmp[i].x;
		p[cnt].y=tmp[i].y;
		cnt++;
	    }
	}
	int ans = 0;
	for ( int i = 0 ; i < cnt ; i++)
	{
	    int sum = 1 ;
	    for ( int j = 0 ; j < cnt ; j++)
	    {
		double cross = (c-p[i])^(c-p[j]);
		if (cross>=0&&i!=j)
		{
		    sum++;
		}
	    }
	    ans = max(sum,ans);
	}
	printf("%d\n",ans);
    }
  
   
 #ifndef ONLINE_JUDGE  
  #endif
  fclose(stdin);
	return 0;
}
