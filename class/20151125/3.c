/*************************************************************************
	> File Name: code/class/20151125/3.c
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月25日 星期三 19时02分26秒
 ************************************************************************/

#include<stdio.h>

int n,m;
int solve (int n,int m,int i)
{
    if (i==1)
	return (n+m-1)%n;
    else return (solve(n-1,m,i-1)+m)%n;
    
}
int main()
{
    scanf("%d %d",&n,&m); //人是从0开始编号的
    for ( int i = 1  ; i <= n ; i++)
	printf("第 %d 次出圈的是 %d \n",i,solve(n,m,i));
    return 0;
}
