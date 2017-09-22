/* ***********************************************
Author :111qqz
Created Time :2016年02月19日 星期五 15时43分58秒
File Name :1833.cpp
************************************************ */

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <map>

using namespace std;
const int N=3E3+5;
int n ,m,k;
int a[N],b[N];

int main()
{
    cin>>m;
    while (m--)
    {
        cin>>n>>k;
      //  k = k % n;

        for ( int i = 0;i < n ; i++ )
        {
            scanf("%d",&a[i]);
        }
        while (k--)
        {
            next_permutation(a,a+n);
        }
        for ( int i = 0 ; i < n ; i++ )
        {
            printf("%d ",a[i]);
        }
        printf("\n");


    }


	return 0;
}
