/* ***********************************************
Author :111qqz
Created Time :2016年02月22日 星期一 23时39分51秒
File Name :code/cf/problem/525B.cpp
************************************************ */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>

using namespace std;

int m,k,len;
const int N=2E5+7;
int a[N];
char st[N];

int main()
{
    cin>>st;
    scanf("%d",&m);
    for ( int i = 1 ; i <= m ; i++ )
        scanf("%d",&a[i]);
    sort(a+1,a+m+1);
    k = 1;
    len = strlen(st);
    while (k<=m)
    {
        for ( int j = a[k] ; j <= a[k+1]-1 ; j++)
            swap(st[j-1],st[len-j]);
        k = k + 2;
    }
    if ( m %2==1 )
        for ( int i = a[m]; i <= len/2 ; i++ )
            swap(st[i-1],st[len-i]);
    cout<<st<<endl;
    return 0;
}
