/* ***********************************************
Author :111qqz
Created Time :2016年05月30日 星期一 17时04分06秒
File Name :code/poj/2420.cpp
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
#define MAX  1000000
#define INF 999999999 
using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=105;
int n;
int dblcmp(double d)
{
    return d<-eps?-1:d>eps;
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
	double res ;
	res = (x-b.x)*(x-b.x)+(y-b.y)*(y-b.y);
	return sqrt(res);
    }
    void look()
    {
	cout<<"x:"<<x<<" y:"<<y<<endl;
    }

}p[N];


double getsum(point t)
{
    double sum = 0.0;
    for ( int i = 1 ; i <= n ; i++) sum += t.dis(p[i]);
    return sum;
}
double SA(const point *p,int n,point &ret)
{
    int i;
    double t,cur,ans = inf;
    const double delta =0.95;
    bool tag;
    point nxt;
    for (ret = p[1] ,t=MAX;t>eps;t*=delta){
	for (tag = true;tag;){
	    for (tag = i = 0;i<4;i++){
		nxt.x = ret.x + dx4[i]*t;
		nxt.y = ret.y + dy4[i]*t;
		cur = getsum(nxt);
		if (cur<ans){
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

	scanf("%d",&n);
	for ( int i = 1; i <= n ; i++) p[i].input();
	
	double ans;
	point res;
	ans = SA(p,n,res);
	printf("%0.f\n",ans);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
