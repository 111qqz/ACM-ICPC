/*************************************************************************
	> File Name: code/class/20151125/4.c
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月25日 星期三 18时50分14秒
 ************************************************************************/

#include<stdio.h>

int day;
int amt;
int main()
{
    scanf("%d",&day);
    amt = 1;
    for ( int i = 1 ; i < day ; i++) 
    {
	amt++;
	amt = amt * 2;
    }
    printf("%d\n",amt);

    return 0;
    
}
