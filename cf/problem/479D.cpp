/* ***********************************************
Author :111qqz
Created Time :2016年02月22日 星期一 23时42分46秒
File Name :code/cf/problem/479D.cpp
************************************************ */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int n,l,x,y;
const int N=1E5+7;
int a[N];
int ans,p,q;
bool flag1,flag2,flag3,flag4;

int main()
{
    scanf("%d %d %d %d",&n,&l,&x,&y);
    flag1 = false;
    flag2 = false;
    flag3 = false;
    flag4 = false;

    for ( int i = 1 ; i <= n ; i++ )
        scanf("%d",&a[i]);
        ans = 2;
        p = -1;
        q = 0;
    for ( int i = 1 ; i <= n ; i++ )
    {
        if(binary_search(a,a+n+1,a[i]+x))
        {
            flag1 = true;

        }
        if (binary_search(a,a+n+1,a[i]+y))
        {
            flag2 = true;
        }
        if (binary_search(a,a+n+1,a[i]+x+y))
        {
            flag3 = true;
            p = a[i];
        }
        if (binary_search(a,a+n+1,a[i]+y-x)&&((a[i]+y<=l)||(a[i]-x>=0)))
        {
            flag4 = true;
            p = a[i];
        }
    }

        if ( flag1) {ans--;q = 1 ;}
        if ( flag2 ){ ans--;q = 2 ;}
        if ( ans==2&&(flag3||flag4))
        {
            ans--;
        }
        cout<<ans<<endl;
    if ( ans==2 )
    {
        cout<<a[1]+x<<" "<<a[1]+y<<endl;
    }
    if ( ans==1 )
    {
        if ( p==-1 )
        {
            if ( q==1 )
                cout<<a[1]+y<<endl;
            else cout<<a[1]+x<<endl;
        }
        else
        {
            if ( p+y<=l )
            cout<<p+y<<endl;
            else cout<<p-x<<endl;
        }
    }
    return 0;
}
