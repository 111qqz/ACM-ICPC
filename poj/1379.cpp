/* ***********************************************
Author :111qqz
Created Time :2016年08月28日 星期一 19时10分47秒
File Name :code/poj/1379.cpp
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
#define INF 1e8
#define MAX 1e6
#define MAXN 1005
double X,Y;
int n;
struct Point {
    double x, y;
    double d;
    Point() {}
    Point(double _x, double _y) : x(_x), y(_y) {}
    Point operator +(const Point &p) const {
	return Point(x + p.x, y + p.y);
    }
    Point operator -(const Point &p) const {
	return Point(x - p.x, y - p.y);
    }
    Point operator *(double k) const {
	return Point(x * k, y * k);
    }
    bool ok ()
    {
	if (x<0||y<0||x>X||y>Y) return false;
	return true;
    }
} p[MAXN];
const Point d[4] = {Point(-1, 0), Point(0, -1), Point(1, 0), Point(0, 1)};
double dis(const Point &a, const Point &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void solve(const Point *p, int n, Point &ret) {
    int i, j;
    double x, cur, ans = 0;
    const double delta = 0.95;
    bool tag;
    Point nxt;
    for (ret = p[0], x = (X+Y)/10; x > eps; x *= delta) {
	for (tag = true; tag;) {
	    for (tag = (i = 0); i < 4; ++i) {
		nxt.x = ret.x + dx4[i] * x * X;
		nxt.y = ret.y + dy4[i] * x * Y;
		if (!nxt.ok()) continue;
		for (cur=inf, j = 0; j < n; ++j) cur = min(cur,dis(nxt,p[j]));
		if (cur > ans) {
		    ans = cur; ret = nxt; tag = true;
		    break;
		}
	    }
	}
    }
    
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
	scanf("%lf%lf%d",&X,&Y,&n);
	for ( int i = 0 ;  i < n ; i++)
	    scanf("%lf %lf",&p[i].x,&p[i].y);
	Point ans;
	solve(p,n,ans);

	printf("The safest point is (%.1f, %.1f).\n",ans.x,ans.y);

    }
#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
