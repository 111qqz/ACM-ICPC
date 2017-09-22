/* ***********************************************
Author :111qqz
Created Time :2016年08月31日 星期三 15时47分25秒
File Name :code/bzoj/3680.cpp
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
#define INF 1E40
#define MAX 100000
using namespace std;
const double eps = 1E-3;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N =1E4+7;
int n;
double Rand(){ return (rand()%10000)/10000.0;}
struct point 
{
    double x,y,w;
    void input()
    {
	scanf("%lf%lf%lf",&x,&y,&w);
    }
    double dis(point b)
    {
	double res = (x-b.x)*(x-b.x)+(y-b.y)*(y-b.y);
	return b.w*sqrt(res);
    }
    void look()
    {
	cout<<"x:"<<x<<" y:"<<y<<endl;
    }
}p[N],ret;
double ans;
double dis(const point &a,const point &b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double Cal(point x)
{
    double res = 0;
    for ( int i = 0 ; i < n ; i++) res +=x.dis(p[i]);
    if (res<ans)
    {
	ret = x;
	ans = res;
    }
    return res;
}
double SA(const point *p)
{
    ans = INF;
    double step;
    const double delta = 0.98;
    point nxt;
    ret.x = 0 ;
    ret.y = 0 ;
    for ( int i = 0 ; i < n ; i++) ret.x+=p[i].x,ret.y+=p[i].y;
    ret.x = ret.x/double(n);
    ret.y = ret.y/double(n);
    ret.x = 0 ;
    ret.y = 0 ;
    point cur = ret;
  //  cur.look();
    for (step = MAX ; step>eps ; step*=delta){
		nxt.x = cur.x + (Rand()*2-1.0)*step;
		nxt.y = cur.y + (Rand()*2-1.0)*step;
	//	nxt.look();
	//	ret.look();
		double delta = Cal(cur)-Cal(nxt);
		if (delta>0||exp(delta/step)>Rand()) cur = nxt;
	}
    for ( int i = 1 ; i <=1000 ; i++)
    {
	point nxt;
	nxt.x = ret.x+(Rand()*2-1.0)*step; //在模拟退火得到的答案附近用爬山法微调，增加精确度。
	nxt.y = ret.y+(Rand()*2-1.0)*step;
	Cal(nxt);
    }   
    return ans;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	srand(821452);
	scanf("%d",&n);
	for ( int i = 0 ; i < n ; i++) p[i].input();
	SA(p);
	printf("%.3f %.3f\n",ret.x,ret.y);
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
