


/* ***********************************************
Author :111qqz
Created Time :2017年10月14日 星期六 16时08分51秒
File Name :E.cpp
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
const double eps = 1E-10;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=1E4+7;
const double PI = acos(-1.0);
struct point
{
    double x,y;
    void input()
    {
    scanf("%lf %lf",&x,&y);
    }

    double dis (point b)
    {
    double ret;
    ret = (x-b.x)*(x-b.x) + (y-b.y) * (y-b.y);
    return sqrt(ret);
    }
}p[N];
int n;
double a[N];
int dblcmp( double d) { return d<-eps?-1:d>eps; }
bool checkR( double R,int id)
{
    if (dblcmp(R)<0||dblcmp(R-a[id])>0) return false;
    //if (dblcmp(R)<0) return false;
    return true;
}
double area(double R)
{
    return  R*R ;
}
vector <double>vecR;
double const DINF = 1E100;
double calc(double R,bool debug)
{
    double ret = 0 ;
    double lstR,curR;
    lstR = R;
    if (debug)
    {
    vecR.clear();
    vecR.PB(R);
    }
    ret = area(R);
    for ( int i = 1 ; i <= n-1 ; i++)
    {
    curR = a[i]-lstR;
    if (debug) vecR.PB(curR);
    ret += area(curR);
    lstR = curR;
    }
   // cout<<"R:"<<R<<" ret:"<<ret<<endl;
    return ret;
}

double sanfen(double l, double r){
   double mid,midmid,ans;
    while (r-l>eps) {
    //cout<<"l:"<<l <<" r:"<<r<<endl;
        mid=(2*l+r)/3;
    midmid = (l+2*r)/3;
    //printf("A:%f B:%f\n",calc(mid,false),calc(midmid,false));
        if( dblcmp(calc(mid,false)-calc(midmid,false))>=0)    // >=就过了，<就wa???
            l=mid;
        else
            r=midmid;
    }
    ans=calc(l,true);
    return ans;
}
void odd()
{

    double lstR=0;
    double ans = 0 ;
    for ( int i = n ;  i >= 1 ; i--)
    {
    if (i%2) lstR += a[i];
    else lstR -= a[i];
    }
    lstR/=2;
    vecR.PB(lstR);
    //cout<<"lstR:"<<lstR<<endl;
    ans += area(lstR);
    if (!checkR(lstR,1)) 
    {
    puts("IMPOSSIBLE");
    return ;
    }
    for ( int i = 1 ; i <= n-1 ; i++)
    {
    double curR = a[i]-lstR;
    if (!checkR(curR,i+1))
    {
        puts("IMPOSSIBLE");
        return;
    }
    vecR.PB(curR);
    ans +=area(curR);
    lstR = curR;
    }
    ans*=PI;
    printf("%.2f\n",ans);
    for ( int i = 0 ; i < int(vecR.size()) ; i++)
    {
    printf("%.2f\n",vecR[i]);
    }
}
double L,R;

int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("./in.txt","r",stdin);
#endif
    int T;
    cin>>T;
    while (T--)
    {
    scanf("%d",&n);
    vecR.clear();
    for ( int i = 1 ; i <= n ; i++) p[i].input();
    for ( int i = 1 ; i <= n ; i++)
    {
        if (i==n)
        a[i] = p[1].dis(p[n]);
        else 
            a[i] = p[i+1].dis(p[i]);
        }
//      for ( int i = 1 ; i <= n ; i++) printf("%f%c",a[i],i==n?'\n':' ');
        //a[n+1] = a[1];
        if (n%2==1)
        {
        odd();
        continue;
        
        }
        
        double tmp=0;
        for ( int i = n ; i >= 1 ; i--)
        {
        if (i%2) tmp+=a[i];
        else tmp-=a[i];
        }
        if (dblcmp(tmp)>0) { puts("IMPOSSIBLE");continue;}
        double L=0,R=a[1];//确定三分的范围
        tmp = 0 ;
        for ( int i = 1 ; i <= n ; i++ )
        {
        int j = i+1;
        if (j>n) j = 1;
        tmp = a[i] - tmp;
        if (i%2==1) R = min(R,tmp);
        else L = max(L,-tmp);
        }
        if (L>R) { puts("IMPOSSIBLE");continue;}
        double ans = sanfen(L,R);
        ans*=PI;
        printf("%.2f\n",ans);
        for ( int i = 0 ; i < vecR.size() ; i++) printf("%.2f\n",vecR[i]);
    }


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}




