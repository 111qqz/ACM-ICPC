/*************************************************************************
	> File Name: code/class/3.c
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月11日 星期三 17时24分25秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int prime( int n)
{
    if (n==1) return 0 ;
    if (n<=3) return 1;
    for ( int i = 2 ; i*i <= n ; i++)
	if (n%i==0) return 0;
    return 1;
}
int main()
{
    int cnt = 0 ;
    for ( int i = 1 ; i <= 1000 ; i++)
	if (prime(i))
	{
	    cnt++;
	    printf("%d ",i);
	    if (cnt%4==0)
	    {
		printf("\n");
	    }
	    
	}

}

