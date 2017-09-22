/*************************************************************************
	> File Name: code/class/1.c
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月11日 星期三 17时10分07秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int a[23][23];
void solve()
{
    memset(a,0,sizeof(a));
    a[1][1]=1;
    for ( int i = 2 ; i <= 20 ; i++)
	for ( int j = 1 ; j <= i ; j++)
	    a[i][j] = a[i-1][j]+a[i-1][j-1];

    for ( int i = 1 ; i <= 20 ; i++)
    {
	for ( int j = 1 ; j <= i ; j++)
	    printf("%d ",a[i][j]);
	printf("\n");
    }
}
int main()
{
    solve();
}

