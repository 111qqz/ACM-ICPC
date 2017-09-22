/* ***********************************************
Author :111qqz
Created Time :2015年12月16日 星期三 16时28分10秒
File Name :joesph_dp.c
************************************************ */
#include <stdio.h>
#include <string.h>
int dp[1000];
int main()
{
    int n,k;
    memset(dp,0,sizeof(dp));
    scanf("%d %d",&n,&k);

    dp[1] = 0 ;
    for ( int i = 2 ; i <= n ;i++) dp[i] = (dp[i-1]+k)%n;

    printf("%d\n",dp[n]);

    return 0;
}
