/*************************************************************************
	> File Name: code/class/20151125/eightqueens.c
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月25日 星期三 19时09分54秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define C 10
#define N 50

int zx[N],fx[N],l[N];
int ans[N];
int cnt = 0 ;

void print()
{
    for ( int i = 1 ; i <= 8 ; i++)
	printf("%d  ",ans[i]);
    printf("\n");
}
void dfs( int i)
{

    for ( int j = 1 ;  j <= 8 ; j++)
    {
	if (l[j]&&fx[i+j]&&zx[i-j+C])
	{
	    ans[i] =  j;
	    l[j] = 0;
	    fx[i+j] = 0;
	    zx[i-j+C] = 0;
	    if (i<8)  dfs(i+1);
	    else
	    {
		print();
		cnt++;
	    }
	    l[j] = 1;
	    fx[i+j] = 1;ssis
	    zx[i-j+C] = 1;
	}
    }
}
int main()
{

    for ( int i = 0 ; i < N ; i++)
    {
	zx[i] = 1;
	fx[i] = 1;
	l[i]  = 1;

    }

    dfs(1);
    printf("  total num:%d\n",cnt);
    return 0;
    
}
