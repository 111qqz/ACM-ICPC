/* ***********************************************
Author :111qqz
Created Time :2015年12月02日 星期三 19时01分32秒
File Name :sum.c
************************************************ */
#include <stdio.h>
#include <time.h>
#define N 100005
#define MAXTIME 10000000
int n;
int a[N];
int ans;
int solve1( int n)
{
    if (n==0) return 0;
    else return n+solve1(n-1);
}
int solve2( int n)
{
    int res =  0;
    for ( int i = 1 ; i <= n ; i++)
    {
	res += i;
    }
    return res;
}
int main()
{
 //   for ( int i = 0 ; i < n ; i++)  scanf("%d",&a[i]);
    
    freopen("ou.txt","w",stdout);
    for ( int n = 3 ; n <= 10 ; n++){
    clock_t begin = clock();
    for ( int i = 1 ; i <= MAXTIME ;  i++)
    {
	    ans = solve1(n);
    }
    clock_t end = clock();
    double time =(double )(end-begin)/CLOCKS_PER_SEC;
    printf("n:%dtime1:%.12f   ",n,time);

    begin = clock();
    for ( int i = 1 ; i <= MAXTIME ; i++)
    {
	ans = solve2(n);
    }
    end = clock();
     time = (double ) (end-begin)/CLOCKS_PER_SEC;
     printf("time2:%.12f\n",time); 
    }

    
return 0;

}
