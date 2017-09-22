/* ***********************************************
Author :111qqz
Created Time :2015年12月02日 星期三 19时20分35秒
File Name :hanoi.c
************************************************ */
#include <stdio.h>
#include <time.h>
#define MAXTIME 100000
int n;
clock_t begin, end;
double tim;
void hanoi( int n,char a,char b,char c)
{
    if (n<1) return ;
    if (n==1)
    {
//	printf("%c-->%c\n",a,c);
    }
    hanoi(n-1,a,c,b);
 //   printf("%c-->%c\n",a,c);
    hanoi(n-1,b,a,c);
}
int main()
{
    freopen("hanoi2.out","w",stdout);
    for ( int n = 3 ; n <= 10 ; n++){
//	printf("%d\n",n);
	begin = clock();
	for ( int i = 1 ; i <= MAXTIME ; i++)
	{
	    hanoi(n,'a','b','c');
	}
	end = clock();
	tim =(double)(end-begin)/CLOCKS_PER_SEC;
	printf("n:%d time:%.12f\n",n,tim);
    }

	return 0;

}
