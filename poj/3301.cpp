/* ***********************************************
Author :111qqz
Created Time :2017年10月15日 星期日 00时33分09秒
File Name :3301.cpp
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
#define PB push_back
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
const int N=50;
const double PI = acos(-1.0);
int n;
struct point
{
    int x,y;
    void input()
    {
	scanf("%d %d",&x,&y);
    }
}p[N];


double cal( double ang)
{
    double minx=1000,miny=1000,maxx=-1000,maxy=-1000;
    for ( int i = 1 ; i <= n ; i++)
    {
	double tmpx = p[i].x * cos(ang) + p[i].y * sin(ang);
	double tmpy = p[i].y * cos(ang) - p[i].x * sin(ang);
	minx = min(minx,tmpx);
	maxx = max(maxx,tmpx);
	miny = min(miny,tmpy);
	maxy = max(maxy,tmpy);
    }
    return max(maxx-minx,maxy-miny);
}
//三分模板
double sanfen(double l,double r)
{
    double mid,midmid;
    while (r-l>eps)
    {
	mid = (2*l+r)/3;
	midmid = (l+2*r)/3;
	if (cal(mid)>=cal(midmid))  l = mid; //此处为求极小值
	else r = midmid;
    }
    return cal(l);

}
    
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
//	printf("PI:%.12f\n",PI);
	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%d",&n);
	    for ( int i = 1 ; i <= n ;i++) p[i].input();
	    double ans = sanfen(0,PI);
	    ans*=ans;
	    printf("%.2f\n",ans);
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
