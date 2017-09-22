/* ***********************************************
Author :111qqz
Created Time :2016年08月31日 星期三 15时20分25秒
File Name :code/hdu/3694.cpp
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
#define INF 1E30
#define MaxStep 200
using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
int dblcmp(double d)
{
    return d<-eps?-1:d<eps;
}
struct point
{
    double x,y;
    void input()
    {
	scanf("%lf%lf",&x,&y);
    }
    double dis(point b)
    {
	double res;
	res = (x-b.x)*(x-b.x)+(y-b.y)*(y-b.y);
	return sqrt(res);
    }
    bool ok ()
    {
	if (x<0||y<0||x>1000||y>1000) return false;
	return true;
    }
}p[5];
double SA(const point *p,int n,point &ret)
{
    double step,cur,ans=inf;
    const double delta = 0.99;
    bool tag;
    point nxt;
    for (ret = p[0] , step = MaxStep;step>eps;step*=delta){
	for (tag = true;tag;){
	    tag = false;
	    for (int i = 0 ; i < 4 ; i++){
		nxt.x = ret.x + dx4[i]*step;
		nxt.y = ret.y + dy4[i]*step;
		if (!nxt.ok()) continue;
		cur = 0 ;
		for ( int j = 0 ; j < n ; j++ ) cur+=nxt.dis(p[j]);
	//	cout<<"nxt.x:"<<nxt.x<<" nxt.y:"<<nxt.y<<" cur:"<<cur<<endl;
		if (dblcmp(cur-ans)<0){
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
	while (~scanf("%lf%lf",&p[0].x,&p[0].y))
	{
	    if (p[0].x==-1||p[0].y==-1) break;
	    for ( int i = 1 ; i <= 3 ; i++) p[i].input();
	    point ret;
	    double ans = SA(p,4,ret);
	    printf("%.4f\n",ans);
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
