/* ***********************************************
Author :111qqz
Created Time :2015年12月02日 星期三 19时35分16秒
File Name :pizza.c
************************************************ */
#include <stdio.h>
#include<time.h>

#define MAXTIME 1000000
int n;

int cal( int n)
{
    if (n==0) return 1;
    else return n+cal(n-1);

}
int main()
{
    freopen("pizza2.out","w",stdout);
    for ( int n = 10 ; n <= 100 ; n +=10)
    {
	clock_t begin = clock();
	int res;
	for ( int i = 1 ; i <= MAXTIME ; i++)
	    res = cal(n);
	clock_t end = clock();

	double tim = (double)(end-begin)/CLOCKS_PER_SEC;
//	printf("%d\n",n);
	printf("%.12f\n",tim);
    }

 //   printf("%d",res);
    return 0;
}
