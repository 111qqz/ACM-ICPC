/* ***********************************************
Author :111qqz
Created Time :2016年08月30日 星期二 20时46分05秒
File Name :code/poj/5017.cpp
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
#define MAX 1
using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
double a,b,c,d,e,f;
int dblcmp(double d)
{
    return d<-eps?-1:d>eps;
}
struct point
{
    double x,y,z;
    point(){}
    point (double _x,double _y,double _z):x(_x),y(_y),z(_z){}
    double dis(point b){
	double res = 0 ;
	res = (x-b.x)*(x-b.x)+(y-b.y)*(y-b.y)+(z-b.z)*(z-b.z);
	return sqrt(res);
    }
    void look()
    {
	printf("x:%.7f y:%.7f z:%.7f ",x,y,z);
    }
};
double getZ(double x,double y)
{
    double A,B,C,delta;
    A = c;
    B = d*y+e*x;
    C = a*x*x+b*y*y+f*x*y-1;
    delta = B*B-4*A*C;
    //    cout<<"A:"<<A<<" B:"<<B<<" C:"<<C<<" delta:"<<delta<<endl;
    if (dblcmp(delta)<0) return 1E31; //无解
    delta = sqrt(delta);
    double z1 = (-B+delta)/2.0/A;
    double z2 = (-B-delta)/2.0/A;
    if (dblcmp(z1*z1-z2*z2)<0) return z1;   //x,y的坐标已经确定，我们选距离(0,0,0）近的解。
    else return z2;
}
double SA(point &ret)
{
    double step,cur,ans=INF;
    const double delta=0.99;
    bool tag;
    point nxt;
    point target = point(0,0,0);
    for ( ret = point(0,0,0),step = 1 ; step>eps ; step*=delta){
	for (tag = true; tag ;){
	    tag = false;
	    for ( int i = 0 ; i < 4 ; i++){
		nxt.x = ret.x + dx4[i]*step;  //只搜x,y，通过解方程得到z啊巧妙地保证了点一直在椭球面上。
		nxt.y = ret.y + dy4[i]*step;
	        nxt.z = getZ(nxt.x,nxt.y);
		if (nxt.z>=1E30) continue; //无解。
		cur = nxt.dis(target);
		if (dblcmp(cur-ans)<0)
		{
		    ans = cur;
		    ret = nxt;
		    tag = true;
		    break;
		}
	    }
	}
    }
    return ans;
}
int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
#endif
    while (~scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f))
    {
	double ans;
	point ret;
	ans = SA(ret);
	printf("%.7f\n",ans);
    }
#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
