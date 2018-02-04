/* ***********************************************
Author :111qqz
Created Time :2016年02月22日 星期一 23时36分22秒
File Name :code/cf/problem/482A.cpp
************************************************ */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
     int n,k;
     int tmp,p;
     const int N=1E5+7;
     int a[N];

int main()
{

     scanf("%d %d",&n,&k);
     for ( int i = 1; i <= n ; i++ )
        a[i] = i;
        tmp = k;
        p = 1;
     for ( int i = 2 ; i <= k+1  ; i++)
     {
         a[i] = a[i-1] + tmp*p;
         tmp--;
         p=p*-1;
     }
     for ( int i = 1 ; i < n ; i++ )
        printf("%d ",a[i]);
    printf("%d",a[n]);

    return 0;
}
