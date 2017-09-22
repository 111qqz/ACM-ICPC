/* ***********************************************
Author :111qqz
Created Time :2015年12月02日 星期三 20时52分36秒
File Name :pivot.c
************************************************ */
#include <time.h>
#include <stdio.h>

#define MAXTIME 10000000


int n;
int a[100005];
void qsort( int l,int r)
{
    int i = l;
    int j = r;
    int x = a[(i+j)/2];

    do
    {
	while (a[i]<x) i++;
	while (a[j]>x) j--;
	if (i<=j)
	{
	    int tmp = a[i];
	    a[i] = a[j];
	    a[j] = tmp;
	    i++;
	    j--;
	}
    }while (i<=j);

    if (i<r) qsort(i,r);
    if (l<j) qsort(l,j);
}

int pivot()
{
    qsort(1,n);
    int mid = n/2 + 1;
    if (a[1]==a[mid])
	return a[1];
    else return -1;
}
int main()
{
    scanf("%d",&n);
    for ( int i = 1; i  <=  n ; i ++)
    {
	scanf("%d",&a[i]);
    }
    
    int ans ;
    clock_t begin = clock();
    for ( int i = 1 ; i <= MAXTIME ;  i++ )
	ans = pivot();
    clock_t end = clock();
    double tim = (double)(end-begin)/CLOCKS_PER_SEC;

    printf("time:%.12f",tim);
    
  return 0;
}
