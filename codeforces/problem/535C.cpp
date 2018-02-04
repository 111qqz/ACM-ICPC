/* ***********************************************
Author :111qqz
Created Time :2016年03月03日 星期四 13时49分13秒
File Name :code/cf/problem/535C.cpp
************************************************ */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
 
using namespace std;
typedef long long LL;
const int N=1e5+5;
LL A,B,n,l,t,m,p,q,k,ans,a,b,c,dd,q2;
long double d,pp;
int main()
{
    cin>>A>>B>>n;
    for ( int i = 1; i <= n ; i++ )
    {
        cin>>l>>t>>m;
        if ( t<A+B*(l-1) )
        {
            cout<<-1<<endl;
            continue;
        }
     //   l = A + (l-1)*B; //wtf。。。这行代码是什么鬼...
        p = (int) ((t-A)/B);
        p++;
        a=B;
        b=(2*A-B);
        c=-B*l*l+3*B*l-2*m*t-2*A*l+2*A-2*B;
        d=(-b+sqrt(b*b-4*a*c))/(2*a);
        //cout<<"a:"<<a<<endl;
        //cout<<"b:"<<b<<endl;
        //cout<<"c:"<<c<<endl;
       // cout<<"d:"<<d<<endl;
        q = int (d);
        q2 = int((2*t-2*A+2*B-l*B)/B);
       // cout<<"q1:"<<q<<endl;
      //  cout<<"q2:"<<q2<<endl;
        q = min(q,q2);
       // cout<<"p:"<<p<<endl;
     //   cout<<"q"<<q<<endl;
        ans = min (p,q);
        cout<<ans<<endl;
    }
    return 0;
}
