/*************************************************************************
	> File Name: code/class/bucket.c
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月27日 星期五 14时29分11秒
 ************************************************************************/

#include<stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define M  100000007
#define N  10000005
#define MAX(a,b) (a>b)?a:b
int n;
int a[N];
int cnt[M];
double t1,t2,t;
void print()
{
    for ( int i = 0 ;i < n ; i++) printf("%d ",a[i]);
    puts("");
}

void sort_bucket()
{
    memset(cnt,0,sizeof(cnt));
    int mx = -1;
    for ( int i = 0 ; i < n ; i++)
    {
	cnt[a[i]]++;
	mx = MAX(a[i],mx);
    }
    int k = 0 ;
    for ( int i = 0 ; i  <= mx ; i++)
	for ( int j = 1 ; j <= cnt[i]; j++)
	    a[k++] = i;
    
}

void sort_choose()
{
    for ( int i = 0 ; i < n-1 ; i++)
	for ( int j = 0 ; j < n ; j++)
	{
	    if (a[i]>a[j])
	    {
		int tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	    }
	}
}

void sort_quick(int l,int r)
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
    if (l<r) sort_quick(l,j);
    if (i<r) sort_quick(i,r);
}
int main()
{

    srand(time(0));
    n=10000;
    for ( int i = 0 ; i < n ;i++)
	a[i] = rand()%100+1;
//   freopen("out.txt","w",stdout);
 //   freopen("in.txt","r",stdin);
  //  scanf("%d",&n);
   // for ( int i = 0 ；  i < n ; i++) scanf("%d",&a[i]);
//      for ( int i = 0 ; i  < n ; i++) scanf("%d",&a[i]);
 //   print();
     t1 = clock()/1000;
      sort_quick(0,n-1); //2
     t2= clock()/1000;
     t = t2-t1;
    printf("t2 :%.12f t1 : %.12f\n",t2,t1);
  //  print();
    printf("快排的运行时间为：%.12f\n",t);

     t1 = clock()/1000;
    sort_bucket();
     t2 = clock()/1000;
    printf("桶排的运行时间为：%.12f\n",t2-t1);

    
     t1 = clock()/1000;
    sort_choose();
     t2 = clock()/1000;
    printf("选择排序的运行时间为：%.12f\n",t2-t1);


   // print();
}

