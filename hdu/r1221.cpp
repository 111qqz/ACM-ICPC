/* ***********************************************
Author :111qqz
Created Time :2015年12月20日 星期日 17时50分26秒
File Name :code/hdu/1221.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define fst first
#define sec second
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;
#define pi pair < int ,int >
#define MP make_pair
#define y1 lovejxy
using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;

double x,y,r,x1,y1,x2,y2;
int dblcmp( double d)
{
    return d<-eps?-1:d>eps;
}

struct point
{
    double x,y;

}circle,a,b,c,d;

double dis(point a,point b)
{
    double res = (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
    return sqrt(res);
}
bool ok ()
{
   if(dis(a,circle)<r && dis(b,circle) <r && dis(c,circle)<r && dis(d,circle) <r)
        return false;
        if(circle.x>=a.x && circle.x<=b.x)
        {
            if(fabs(circle.y-a.y) <= r || fabs(circle.y-b.y) <= r)
            return true;
        }
        if((circle.y >= a.y && circle.y <=b.y) || (circle.y>=b.y && circle.y<=a.y))
        {
            if(fabs(circle.x-a.x) <=r || fabs(circle.x-b.x) <=r)
            return true;
        }
        if(dis(a,circle)<=r || dis(b,circle) <=r || dis(c,circle)<=r || dis(d,circle) <=r)
        return true;

	return false;
        
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%lf %lf %lf %lf %lf %lf %lf",&circle.x,&circle.y,&r,&a.x,&a.y,&b.x,&b.y);
	    point tmp;
	    if (a.x>b.x)
	    {
		tmp = a;
		a = b;
		b = tmp;
	    }
	 //   cout<<"a.x"<<a.x<<" b.x"<<b.x<<endl;
	
		c.x = a.x;
		c.y = b.y;
		d.x = b.x;
		d.y = a.y;

		if (ok())
		{
		    puts("YES");
		}
		else
		{
		    puts("NO");
		}
	    
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
