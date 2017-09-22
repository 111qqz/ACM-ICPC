/*************************************************************************
	> File Name: code/class/20151125/maze.c
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月25日 星期三 19时54分22秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

#define N 30
int n,m;
int maze[N][N];
int head,tail;
int dx[2]={0,1};
int dy[2]={1,0};
 struct node
{
    int x,y;
    int pre;
}q[N];

void print( int x)
{
  //  printf("whhhhhh>");
    if (q[x].pre!=-1)
    {
	print(q[x].pre);
	printf("(%d , %d)\n",q[x].x,q[x].y);
    }
}
void bfs()
{
    head = 0;
    tail = 1;
    q[head].x = 0;
    q[head].y = 0;
    q[head].pre = -1;
    while (head<tail)
    {
//	printf("%d %d\n",q[head].x,q[head].y);
	if (q[head].x==n-1&&q[head].y==m-1)
	{
	    print(head);
	    return;
	}
	for ( int i = 0 ; i < 2 ; i++)
	{
	    int nx = dx[i] + q[head].x;
	    int ny = dy[i] + q[head].y;
	    if (nx>=0&&nx<n&&ny>=0&&ny<m&&maze[nx][ny]==0)
	    {
		q[tail].x=nx;
		q[tail].y=ny;
		q[tail].pre=head;
		tail++;
	    }
	}
	head++;
    }
}
int main()
{
 //   freopen("in.txt","r",stdin);
    scanf("%d %d",&n,&m);
    memset(maze,0,sizeof(maze));
    for ( int i = 0 ; i < n ; i++)
	for ( int j = 0 ; j < m ; j++)
		scanf("%d",&maze[i][j]);
 //   printf("what the hell?");

    bfs();
    return 0;
}


