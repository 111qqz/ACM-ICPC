/* ***********************************************
Author :111qqz
Created Time :2015年12月29日 星期二 18时14分45秒
File Name :code/cf/problem/30C.cpp
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

using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=1E3+7;
int n;
double dp[N];
int dblcmp(double d)
{
    return d<-eps?-1:d>eps;
}
struct point 
{
    int x,y,t;
    double p;

    void input()
    {
	scanf("%d %d %d",&x,&y,&t);
	scanf("%lf",&p);
    }

    double dis(point p)
    {
	return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
    }

    bool operator <(point p)const
    {
	return t<p.t;
    }
}p[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	for ( int i = 1 ; i <= n ; i++) p[i].input();

	sort(p+1,p+n+1);

	double ans=0;
	for ( int i = 1 ; i <= n ; i++)
	{
	    dp[i] = p[i].p;
	    for ( int j = 1 ; j < i ; j++)
	    {
		if (dblcmp(p[i].dis(p[j])-p[i].t+p[j].t)<=0)
		    dp[i] = max(dp[i],dp[j]+p[i].p);
	    }
	    ans = max(dp[i],ans);
	}
	printf("%.10f\n",ans);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
