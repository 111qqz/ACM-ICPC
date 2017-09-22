/* ***********************************************
Author :111qqz
Created Time :2015年12月10日 星期四 14时32分25秒
File Name :joseph.c
************************************************ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAXTIME 100

int n,m;
typedef struct Node
{
    int data;
    struct Node *next;
}Node,*Cursor;

Cursor Creatcursor( int n)
{
    Cursor head,p;
    head = (Node*)malloc(sizeof(Node));
    if (!head)
    {
	puts("Error");
	exit(1);
    }
    head->data = 1;
    head->next = head;
    for ( int i = n ; i > 1 ; i--)
    {
	p = (Node*)malloc(sizeof(Node));
	if (!p)
	{
	    puts("Error");
	    exit(1);
	}
	p->data = i;
	p->next = head->next;
	head->next = p;

    }
    return head;
}

int winner (Cursor h,int m)
{
    Node *p = h ;
    Node *pre =NULL;
    for ( int i = 0 ; i < n - 1 ; i ++)
    {
	for ( int j = 1 ; j < m ; j++)
	{
	    pre = p;
	    p = p->next;
	}
//	printf("第%d次挂掉的人是：%d\n",i+1,p->data);
	pre->next = p->next;
	free(p);
	p = pre->next;
    }
    return p->data;

}

void test()
{
    int n ,k;
    scanf("%d %d",&n,&k);
    Cursor head;
    head = Creatcursor (n);
    printf("%d\n",winner(head,n));
}
int main()
{
    test();
    return 0;
    for ( int i = 100 ; i <= 5000 ; i +=100)
    {
	clock_t beg = clock();
	for ( int t = 1 ; t <= MAXTIME ; t++)
	{

	    Cursor head;
	    head = Creatcursor(i);
	    //printf("幸存的人是：%d\n",winner(head,i));
	}
	clock_t end = clock();
	double tim = (double)((end-beg))/CLOCKS_PER_SEC; 
	printf("%6d   %.12f\n",i,tim);

    }
    return 0;

}

