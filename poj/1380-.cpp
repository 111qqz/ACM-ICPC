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
int dblcmp(double d) {return d<-eps?-1:d>eps;}
bool ok(double a,double b,double x,double y)
{
 

    if (dblcmp(a-x)>0&&dblcmp(b-y)>0) return true;
    if (dblcmp(a-x)<0) return false;
    double djx =sqrt(x*x*1.0+y*y*1.0);
    double ax = asin(a*1.0/djx);
    double ay = asin(x*1.0/djx);
    double az = ax-ay;
    double tmp = cos(az)*y+sin(az)*x;
    if (dblcmp(tmp-b*1.0)<=0) return true;
    return false;

}
int main()
{
	
	double a,b,x,y;
	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%lf%lf%lf%lf",&a,&b,&x,&y);
	    if (a>b) swap(a,b);
	    if (x>y) swap(x,y);
	    if (ok(a,b,x,y))
		puts("Escape is possible.");
	    else puts("Box cannot be dropped.");
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
