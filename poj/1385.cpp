
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

using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=1E6+7;
int dblcmp(double d)
{
    return d < -eps ? -1 : d > eps;
}
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
	if (dblcmp(x)==0) x = 0;
	if (dblcmp(y)==0) y = 0;
        printf("%.2f %.2f\n",x,y);
    }
    point sub(point p)
    {
        return point(x-p.x,y-p.y);
    }
    point div(double b)
    {
        return point(x/b,y/b);
    }
    double dot(point p)
    {
        return x*p.x+y*p.y;
    }
    double det(point p)
    {
        return x*p.y-y*p.x;
    }
}p[N],ans;

struct polygon
{
    int n ;
    void input()
    {
	for ( int i = 0 ; i < n ; i++) p[i].input();
    }
    point getbarycentre()
    {
        point ret(0,0);
        double area=0;
        int i;
        for (i=1;i<n-1;i++)
        {
            double tmp=p[i].sub(p[0]).det(p[i+1].sub(p[0]));
            if (dblcmp(tmp)==0)continue;
            area+=tmp;
            ret.x+=(p[0].x+p[i].x+p[i+1].x)/3*tmp;
            ret.y+=(p[0].y+p[i].y+p[i+1].y)/3*tmp;
        }
        if (dblcmp(area))ret=ret.div(area);
        return ret;
    }
}pol;

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	int n ;
	cin>>T;
	while (T--)
	{
	  //  ms(p,0);
	    scanf("%d",&n);
	    pol.n = n ;
	    pol.input();
	    ans = pol.getbarycentre();
	    ans.output();
	    
	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
