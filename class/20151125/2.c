/*************************************************************************
	> File Name: code/class/20151125/2.c
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月25日 星期三 18时31分40秒
 ************************************************************************/

#include<stdio.h>
#include <math.h>


int judge(int x)
{
    int xx=x;
    int res = 0;
    int g;
    while (xx)
    {
//	printf("xx:%d\n",xx);
	g = xx % 10;
	res = res + g*g*g;
	xx = xx/10;
//	printf("%d\n",res);
    }

 //   printf("res: %d",res);
    if (res==x) return 1;
    else return 0;

}

int main()
{

    for ( int i = 100 ; i < 1000 ; i ++)
    {
	if (judge(i))
	{
	    printf("%d\n",i);
	}
    }
 return 0;

}
