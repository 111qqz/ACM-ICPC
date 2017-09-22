/* ***********************************************
Author :111qqz
Created Time :2016年02月22日 星期一 23时08分05秒
File Name :code/hdu/1087.cpp
************************************************ */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int n,tmp,ans;
    const int N=1E3+5;
    int a[N],dp[N];
    while ( scanf("%d",&n)!=EOF&&n)
    {
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        for ( int i = 1 ; i <= n ; i++ )
            scanf("%d",&a[i]);
        dp[1]=a[1];
        ans=dp[1];
        for ( int i = 2 ; i <= n ; i++ )
        {
            tmp = 0;
            for ( int j = 1 ; j <= i-1 ; j++ )
                if ( a[j]<a[i]&&dp[j]>tmp)
            {
                tmp=dp[j];
            }
            dp[i]=tmp+a[i];
            if ( dp[i]>ans ) ans = dp[i] ;
        }
        printf("%d\n",ans);
    }
    return 0;
}
