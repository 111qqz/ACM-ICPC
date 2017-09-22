/*************************************************************************
	> File Name: code/class/6.c
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月11日 星期三 17时40分46秒
 ************************************************************************/

#include<stdio.h>

int n;
int a[105];
int main()
{
    scanf("%d",&n);
    for ( int i = 0 ; i < n ; i++) scanf("%d",&a[i]);

    for ( int i = 0 ; i < n ; i++)
	for ( int j = i+1 ; j < n ; j++)
	    if (a[i]>a[j])
	    {
		int tmp;
		tmp  = a[i];
		a[i] = a[j];
		a[j] = tmp;
	    }
    for ( int i = 0 ; i <  n ; i++ ) printf("%d ",a[i]);
    
}
