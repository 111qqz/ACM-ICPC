/* ***********************************************
Author :111qqz
Created Time :2016年02月22日 星期一 23时49分32秒
File Name :code/cf/problem/534B.cpp
************************************************ */

#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
const int N=1E2+5;
const int inf=8E9;
int a[N],m[N];
int v1,v2,t,d,tmp,p,ans,n;


int main()
{
    cin>>v1>>v2>>t>>d;
    p = inf;
    memset(a,0,sizeof(a));
    a[1]= v1;
    tmp = v2;
    m[t]= v2;
    for ( int i = t-1 ; i >= 1; i--)
    {
        tmp = tmp+d;
        m[i] = tmp;
    }
    for ( int i =2 ;i <= t; i++ )
    {
        if (a[i-1]+d<=m[i])
        {
            a[i] = a[i-1] + d;
        }
        else
        {
            a[i] = m[i];
            p = i;
            break;
        }
    }
    ans = 0;
    for ( int i = p ; i <= t; i++ )
        a[i] = m[i];
    for ( int i = 1; i <= t ; i++ )
    {
        if (i<p)
            ans = ans + a[i];
        else ans = ans + m[i];
    }
   // for ( int i = 1; i <= t ; i++)
   //     cout<<"a[i]:"<<a[i]<<endl;
    cout<<ans<<endl;

    return 0;
}
