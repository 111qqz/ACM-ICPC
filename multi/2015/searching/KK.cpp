/*************************************************************************
	> File Name: code/2015summer/searching/KK.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月25日 星期六 13时33分00秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
int a[10][10];
int head = 0;
int tail = 1;
int dirx[2]={1,0};
int diry[2]={0,1};
struct node
{
    int x,y,pre;
}q[10];

void print(int x)
{
    if (q[x].pre!=-1)
    {
	  print(q[x].pre);
	  printf("(%d, %d)\n",q[x].x,q[x].y);
    }
}
void bfs()
{
    q[head].x=0;
    q[head].y=0;
    q[head].pre=-1;
    while (head<tail)
    {
	  if (q[head].x==4&&q[head].y==4) 
	  {
		print(head);
		return;
	  }
	  for (int i = 0 ; i < 2 ; i++ )
	  {
		int newx=dirx[i]+q[head].x;
		int newy=diry[i]+q[head].y;
		if (newx>=0&&newx<5&&newy>=0&&newy<5&&a[newx][newy]==0)
		{
		    q[tail].x=newx;
		    q[tail].y=newy;
		    q[tail].pre=head;
		    tail++;
		}
	  }
	  head++;
    }

}
int main()
{
    for ( int i = 0 ; i < 5 ; i++ )
    {
	  for ( int j = 0 ; j < 5;  j++)
	  {
		cin>>a[i][j];
	  }
    }
    printf("(0, 0)\n");
    bfs();
  
	return 0;
}
