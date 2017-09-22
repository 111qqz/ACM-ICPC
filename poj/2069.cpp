/* ***********************************************
Author :111qqz
Created Time :2016年08月30日 星期二 14时31分15秒
File Name :code/poj/2069.cpp
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
#define INF 1E20
#define MAX 1E6
using namespace std;
const double eps = 1E-7;
const int dx6[6]={1,0,0,-1,0,0};
const int dy6[6]={0,1,0,0,-1,0};
const int dz6[6]={0,0,1,0,0,-1};
const int inf = 0x3f3f3f3f;
int n;
int dblcmp(double d)
{
    return d<-eps?-1:d>eps;
}
struct point
{
    double x,y,z;
    void input()
    {
	scanf("%lf%lf%lf",&x,&y,&z);
    }
    point(){}
    point (double _x,double _y,double _z):x(_x),y(_y),z(_z){}
    void look()
    {
//	cout<<"x:"<<x<<" y:"<<y<<" z:"<<z<<" ";
	printf("x:%.5f y:%.5f z:%.5f ",x,y,z);
    }
    double dis(point b)
    {
	double res = 0 ;
	res = (x-b.x)*(x-b.x)+(y-b.y)*(y-b.y)+(z-b.z)*(z-b.z);
//	if (res<0.000001){
//	    look();
//	    cout<<"res:"<<res<<endl;
//	}
	return sqrt(res);
    }

    bool ok ()
    {
	if (x<0||y<0||z<0||x>100||y>100||z>100) return false;
	return true;
    }

}p[35];

double ax,ay,az;
double SA(const point *p,int n,point &ret)
{
    double t,cur,ans = INF;
    const double delta = 0.98;
    int mp = 0; //记录距离当前圆心最远的点，每次不是随机移动而是朝着最远的点的方向移动。
    for (ret = point(ax,ay,az) ,t = 100 ; t>eps ; t*=delta){
	for ( int i = 0 ; i < n ; i++)
	    if (ret.dis(p[mp])<ret.dis(p[i]))  mp = i ;
	cur = ret.dis(p[mp]);
	if (dblcmp(cur-ans)<0) ans = cur;
	ret.x+=(p[mp].x-ret.x)/cur*t;
	ret.y+=(p[mp].y-ret.y)/cur*t;
	ret.z+=(p[mp].z-ret.z)/cur*t;

    }
    return ans;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
      while (~scanf("%d",&n))
      {
	  if (n==0) continue;
	  ax = ay = az = 0 ;
	  for ( int i = 0 ; i < n ; i++)
	    {
		p[i].input();
		ax+=p[i].x;
		ay+=p[i].y;
		az+=p[i].z;
	    }
	  ax = ax/n;
	  ay = ay/n;
	  az = az/n;
	  point ret;
	  double ans = SA(p,n,ret);
	  printf("%.5f\n",ans);
      }

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
