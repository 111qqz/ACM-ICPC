/*************************************************************************
	> File Name: code/class/20151125/5.c
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月25日 星期三 18时43分23秒
 ************************************************************************/

#include<stdio.h>
int n;
int a[10005];
int main()
{

    scanf("%d",&n);
    for ( int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);

    for ( int i = 1 ; i <= n-1 ; i++)
	for ( int j = i+1 ; j <= n ; j++ )
	{
	    if (a[i]<a[j])
	    {
		int tmp;
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	    }
	}
    for ( int i =1  ; i<= n ; i++) printf("%d ",a[i]);
    return 0;
}
