/* ***********************************************
Author :111qqz
Created Time :2016年02月22日 星期一 23时46分25秒
File Name :code/cf/problem/534A.cpp
************************************************ */

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int N=5E3+7;
int a[N],n,k,tmp;

int main()
{
    cin>>n;
    memset(a,0,sizeof(a));
    if (n<=2)
    {

        k = 1;
        a[1] = 1;
        cout<<k<<endl;
        cout<<a[1];
        return 0;
    }
    if (n==3)
    {
        k = 2;
        a[1] = 1;
        a[2] = 3;
        cout<<k<<endl;
        cout<<a[1]<<" "<<a[2];
        return 0;
    }
    if (n==4)
    {
        k = 4;
        a[1] = 2;
        a[2] = 4;
        a[3] = 1;
        a[4] = 3;
        cout<<k<<endl;
        cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4];
        return 0;
    }
     tmp = (n+1)/2;
    for ( int i = 1 ; i <= n ; i++)
    {

        if (i<=tmp)
        {
            a[i] = 2*i-1;
        }
        else
        {
            a[i]=a[i-tmp]+1;
        }
    }
    cout<<n<<endl;
    for ( int i = 1 ; i <= n ; i++ )
        cout<<a[i]<<" ";



    return 0;
}
