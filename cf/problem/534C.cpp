/* ***********************************************
Author :111qqz
Created Time :2016年03月03日 星期四 13时54分19秒
File Name :code/cf/problem/534C.cpp
************************************************ */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
typedef long long LL;
const int N=2E5+7;
LL n,d[N],ans[N];
LL A,MAX,MIN,TMAX,TMIN;

using namespace std;

int main()
{
    scanf("%I64d %I64d",&n,&A);
    memset(ans,0,sizeof(ans));
    for ( int i = 1; i <= n ;i ++ )
        scanf("%I64d",&d[i]);
    MAX = 0;
    MIN = n;
    for ( int i = 1; i <= n ; i++ )
        MAX = MAX + d[i];
    for ( int i = 1 ; i <= n ; i++ )
    {
        TMAX = MAX - d[i];
        TMIN = MIN - 1;
        if (d[i]>=(A-TMIN))
        {
            ans[i] =ans[i]+d[i]-(A-TMIN);
        }
        if (A>=TMAX+1)
        {
            ans[i] =ans[i]+A-TMAX-1;
        }

    }
    for ( int i = 1; i < n ; i++)
        cout<<ans[i]<<" ";
        cout<<ans[n];


    return 0;
}
