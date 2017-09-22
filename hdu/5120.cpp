/* ***********************************************
Author :111qqz
Created Time :2016年02月19日 星期五 16时24分22秒
File Name :code/hdu/5120.cpp
************************************************ */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

    int t,tt;
    int rr,RR,x11,x22,y11,y22;
    double ans;
    const double PI=acos(-1);
    const double C=10e-6;
    double area(int x1,int y1,int x2,int y2,int R,int r);
int main()
{
    cin>>t;
    tt=t;
    while (t--)
    {
        cin>>rr>>RR;
        cin>>x11>>y11>>x22>>y22;
        ans=area(x11,y11,x22,y22,RR,RR)-2*area(x11,y11,x22,y22,RR,rr)+
            area(x11,y11,x22,y22,rr,rr);
            cout<<"Case #"<<tt-t<<": "
            <<fixed<<setprecision(6)<<ans<<endl;
    }
    return 0;
}
double area(int x1,int y1,int x2,int y2,int R,int r)
{
     double d;
     double A,a;
     double st;
      d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
     if (d>=r+R)
        return 0;
     if (R-r>=d)
      return r*r*PI;
      A=acos((R*R+d*d-r*r)/(2.0*d*R));
      a=acos((r*r+d*d-R*R)/(2.0*d*r));
      st=R*d*sin(A);
      A=A*2;
      a=a*2;
      return  (A*R*R+a*r*r)/2.0-st;
}
