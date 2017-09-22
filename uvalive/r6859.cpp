#include<cstdio>  
#include<cmath>  
#include<cstdlib>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
const double eps = 1e-10;  
const int maxn = 100000 + 10;  
const int dx[] = {1,-1,0,0};  
const int dy[] = {0,0,1,-1};  
struct Point{  
    double x,y;  
    Point(double x = 0,double y = 0):x(x),y(y){}  
}p[maxn<<2],tubao[maxn];  
typedef Point Vector;  
Vector operator + (Vector A,Vector B) { return Vector(A.x+B.x,A.y+B.y); }  
Vector operator - (Vector A,Vector B) { return Vector(A.x-B.x,A.y-B.y); }  
Vector operator * (Vector A,double p) { return Vector(A.x*p,A.y*p); }  
Vector operator / (Vector A,double p) { return Vector(A.x/p,A.y/p); }  
bool operator < (const Point& a,const Point &b){  
    return a.x < b.x || (fabs(a.x-b.x) < eps && a.y < b.y);  
}  
int dcmp(double x){  
    if (fabs(x) < eps) return 0;  
    return x < 0 ? -1 : 1;  
}  
bool operator == (const Point&a, const Point &b){  
    return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;  
}  
double Cross(Vector A,Vector B) { return A.x*B.y - A.y * B.x; }  
double dist(Point &A,Point &B){  
    return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y) );  
}  
int ConvexHull(Point *p,int n,Point * ch){  
//    sort(p,p+n);  
    int m = 0;  
    for (int i =0 ; i < n; ++i){  
        while(m > 1 && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]) <= 0)--m;  
        ch[m++] = p[i];  
    }  
    int k = m;  
    for (int i = n-2; i >= 0; --i){  
        while(m > k && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]) <= 0) --m;  
        ch[m++] = p[i];  
    }  
    if (n > 1)--m;  
    return m;  
}  
int main(){  
    int n;  
    while(scanf("%d",&n) == 1){  
        int cnt = 0;  
        for (int i = 0; i < n; ++i){  
            double x,y;  
            scanf("%lf %lf",&x,&y);  
            for (int j = 0; j < 4; ++j){  
                double xx = x + dx[j];  
                double yy = y + dy[j];  
                p[cnt].x = xx;  
                p[cnt++].y = yy;  
            }  
        }  
        sort(p,p+cnt);  
        int nn = unique(p,p+cnt)-p;  
  
        int m = ConvexHull(p,nn,tubao);  
        double ans = 0;  
        for (int i = 0; i < m; ++i){  
            int disx = abs(tubao[(i+1)%m].x-tubao[i].x);  
            int disy = abs(tubao[(i+1)%m].y-tubao[i].y);  
            int Max = max(disx,disy);  
            int Min = min(disx,disy);  
            ans += Min*sqrt(2) + Max-Min;  
        }  
  
        printf("%.15lf\n",ans);  
    }  
  
    return 0;  
}  


