/* ***********************************************
Author :111qqz
Created Time :2016年02月22日 星期一 22时52分26秒
File Name :code/hdu/1171.cpp
************************************************ */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;
const int N=3E6+5;
int a[N],dp[N];
int n,x,y;
int tmp;
int sum;

void solve(int value ,int cost)
{
    for ( int i = sum/2 ; i >= cost ; i--)
    {
        dp [i] = max(dp[i],dp[i-cost]+value);
    }

}

int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        if( n<0 ) break;
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        tmp = 1;
        sum = 0;
        for ( int i = 1 ; i <= n ; i++ )
        {
            scanf("%d %d",&x,&y);
            sum = sum +x*y;
            for ( int j =1 ; j <= y ; j++)
            {
                a[tmp] = x;
                tmp++;
            }
        }
        for ( int i = 1 ; i <= tmp ; i++)
            solve (a[i],a[i]);
        printf("%d %d\n",sum-dp[sum/2],dp[sum/2]);
    }

    return 0;
}
