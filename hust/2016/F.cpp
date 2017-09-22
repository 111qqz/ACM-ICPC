/* ***********************************************
Author :111qqz
Created Time :2016年05月28日 星期六 14时40分56秒
File Name :code/hust/2016/F.cpp
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
const double eps = 1E-10;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;


double dcmp(double d)
{
    return d<-eps?-1:d>eps;
}
struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }
    void read() {
        scanf("%lf%lf", &x, &y);
    }
};

typedef Point Vector;

Vector operator - (Vector A, Vector B) {
    return Vector(A.x - B.x, A.y - B.y);
}



double Cross(Vector A, Vector B) {return A.x * B.y - A.y * B.x;} //叉积

//可以不规范相交
bool SegmentProperIntersection2(Point a1, Point a2, Point b1, Point b2) {
    double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1),
            c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
    return max(a1.x, a2.x) >= min(b1.x, b2.x) &&
    max(b1.x, b2.x) >= min(a1.x, a2.x) &&
    max(a1.y, a2.y) >= min(b1.y, b2.y) &&
    max(b1.y, b2.y) >= min(a1.y, a2.y) &&
    dcmp(c1) * dcmp(c2) <= 0 && dcmp(c3) * dcmp(c4) <= 0;
}

const int N = 25;

int n;

struct Ban  
{
    Point p[4];
    void input() 
    {
        double a, y[4];
        scanf("%lf", &a);
        for (int i = 0; i < 2; i++) 
	{
            scanf("%lf", &y[i]);
            p[i] = Point(a, y[i]);
        }
    }
} b[N];

struct Edge 
{
    int u, v;
    double w;
    Edge(){}
    Edge(int u, int v, double w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

vector<Edge> g[N * 4];

double dist(Point a, Point b) 
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

void add_edge(int u, int v, double d) 
{
    g[u].push_back(Edge(u, v, d));
    g[v].push_back(Edge(v, u, d));
}

bool judge(int l, int r, Point aa, Point bb) 
{
    for (int i = l; i <= r; i++) 
    {
        if (!SegmentProperIntersection2(aa, bb, b[i].p[0], b[i].p[1]))
            return false;
    }
    return true;
}

double d[N * 4];
int vis[N * 4];

double spfa(int s, int t) 
{
    ms(vis,0);
    queue<int> Q;
    for (int i = 0; i <= t; i++) d[i] = 1E20;
    d[s] = 0;
    vis[s] = 1;
    Q.push(s);
    while (!Q.empty()) 
    {
        int u = Q.front();
        Q.pop();
        vis[u] = 0;
	
	int siz = g[u].size();
        for (int i = 0; i < siz; i++) 
	{
            int v = g[u][i].v;
            double w = g[u][i].w;
            if (d[u] + w < d[v]) 
	    {
                d[v] = d[u] + w;
		if (vis[v]) continue;
		vis[v] = 1;
		Q.push(v);
                
            }
        }
    }
    return d[t];
}

int main() {

   freopen("code/in.txt","r",stdin);
    while (scanf("%d", &n)!=EOF)
    { 
        for (int i = 0; i <= n * 2 + 1; i++) g[i].clear();
        for (int i = 0; i < n; i++)
            b[i].input();
        if (judge(0, n - 1, Point(0, 5), Point(10, 5)))
            add_edge(0, n * 2 + 1, 10);
        for (int i = 0; i < n; i++) 
	{
            for (int j = 0; j < 2; j++) 
	    {
                if (judge(0, i - 1, Point(0, 5), b[i].p[j]))
                    add_edge(0, i * 2 + j + 1, dist(Point(0, 5), b[i].p[j]));
                if (judge(i + 1, n - 1, b[i].p[j], Point(10, 5)))
                    add_edge(n * 2 + 1, i * 2 + j + 1, dist(Point(10, 5), b[i].p[j]));
                for (int k = i + 1; k < n; k++) {
                    for (int x = 0; x < 2; x++) {
                        if (judge(i + 1, k - 1, b[i].p[j], b[k].p[x]))
                            add_edge(i * 2 + j + 1, k * 2 + x + 1, dist(b[i].p[j], b[k].p[x]));
                    }
                }
            }
        }
        printf("%.2f\n", spfa(0, n * 2 + 1));
    }
    return 0;
}
