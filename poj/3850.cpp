/*************************************************************************
	> File Name: code/poj/3850.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月08日 星期日 20时10分56秒
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
const int N=2E3+7;
int n;
int pos;
int dblcmp(double d)
{
    return d<-eps?-1:d>eps;
}

struct point
{
    double x,y;
    int id;
    point(){}
    point (double _x,double _y):
    x(_x),y(_y){};
    void input()
    {
	scanf("%lf %lf",&x,&y);
    
    }
    point  operator - (const point &p) const
    {
	return point (x-p.x,y-p.y);
    }
    double operator ^(const point &p) const{
	return x*p.y-y*p.x;
    }

    double dis( point p)
    {
	return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
    }


}p[N];

bool cmp( point a,point b)
{
    double cross = (a-p[0])^(b-p[0]);
    return dblcmp(cross)>0||(dblcmp(cross)==0&&p[0].dis(a)<p[0].dis(b));
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
   int T;
   scanf("%d",&T);
   while (T--)
   {
       scanf("%d",&n);
       for ( int i = 0 ; i < n ; i++) p[i].input(),p[i].id = i;

       for ( int i = 1 ; i < n ; i++) 
	{
	    if (dblcmp(p[i].x-p[0].x)<0||(dblcmp(p[i].x-p[0].x)==0&&dblcmp(p[i].y-p[0].y)<0))
		    swap(p[i],p[0]);
	}
	
       sort(p+1,p+n,cmp);
       int m = -1;
       for ( int i = n -2 ; i >0 ; i --)
	{
	    double cross = (p[i]-p[0])^(p[n-1]-p[0]);
	    if (dblcmp(cross))
	    {
		m = i ;
		break;
	    }
	}
        for ( int i = 0 ; i <= m ; i++)
	    if (i) printf(" %d",p[i].id);
		else printf("%d",p[i].id);
	if (m!=-1)
	{
	    for ( int i = n-1 ; i > m ;i--)
		printf(" %d",p[i].id);
	}
	puts("");


   }
  
   
 #ifndef ONLINE_JUDGE  
  #endif
  fclose(stdin);
	return 0;
}
