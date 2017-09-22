/*************************************************************************
	> File Name: code/class/20151125/1.c
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月25日 星期三 18时26分38秒
 ************************************************************************/

#include<stdio.h>
#include <math.h>

int cnt;

int judge(int x)
{
    int sum = 0;
    for ( int i = 1 ; i < x  ;i ++)
    {
	if (x%i==0)
	    sum += i;
    }

    if (sum==x) return 1;
	else return 0;
}
int main()
{
    cnt  = 0;
    
    for ( int i = 1 ; i < 1000 ; i++)
    {
	if (judge(i))
	{
	    cnt++;
	    printf("%d ",i);
	 //   if (cnt%4==0) printf("\n");
	}
    }
     
}
