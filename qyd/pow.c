/*************************************************************************
	> File Name: code/qyd/pow.c
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月14日 星期六 00时20分54秒
 ************************************************************************/

#include<stdio.h>

int n,k;

int kk_pow( int n,int k)
{
    if (k==0) return 1;
    else return n*kk_pow(n,k-1);
}
int main()
{
  //  scanf("%d %d",&n,&k);

    for ( int i = 0 ; i <= 9 ; i++)
	printf("%d ",kk_pow(3,i));

}
