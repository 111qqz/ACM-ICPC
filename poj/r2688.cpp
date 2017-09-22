/*************************************************************************
	> File Name: code/poj/r2688.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月15日 星期六 01时53分08秒
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
const int inf = 0x7fffffff;
const int N=25;
char maze[N][N];
int w,h,num;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
bool vis[N][N];
struct node
{
    int x,y;
    int time;
    bool ok()
    {
	if (x>=0&&x<h&&y>=0&&y<w&&!vis[x][y]&&maze[x][y]!='x')
	    return true;
	return false;
    }
}s,tmp;
int bfs(int sx,int sy)
{
    memset(vis,false,sizeof(vis));
    queue<node>q;
    tmp.x = sx;
    tmp.y = sy;
    tmp.time = 0 ;
    q.push(tmp);
    vis[tmp.x][tmp.y] = true;
    while (!q.empty())
    {
	node pre = q.front();q.pop();

	if (maze[pre.x][pre.y]=='*')
	{
	    maze[pre.x][pre.y] = '.';
	    s.x = pre.x;
	    s.y = pre.y;
	    return pre.time;
	}
	for ( int i = 0 ; i < 4 ; i++ )
	{
	    node next;
	    next.x = pre.x + dx[i];
	    next.y = pre.y + dy[i];
	    next.time = pre.time+1;
	    if (next.ok())
	    {
		q.push(next);
		vis[next.x][next.y]=true;
	    }
	}
    }
    return -1;
}
int main()
{
    while (scanf("%d %d",&w,&h)!=EOF)
    {
	if (w==0&&h==0) break;
	for ( int i = 0 ; i < h ; i++)
	{
	    scanf("%s",maze[i]);
	}
	num = 0 ;
	for (  int i = 0 ; i < h ; i++ )
	{
	    for ( int j = 0 ; j < w ; j++)
	    {
		if (maze[i][j]=='*')
		{
		    num++;
		}
		if (maze[i][j]=='o')
		{
		    s.x = i;
		    s.y = j;
		}
	    }
	}
	bool flag = false;
	int ans  = 0;
	for ( int i = 1 ; i <= num ; i++ )
	{
	    int tmp = bfs(s.x,s.y);
    //	    cout<<"tmp:"<<tmp<<endl;
	    if (tmp==-1)
	    {
		flag = true;
		break;
	    }
	    ans = ans + tmp;
	}
	if (flag)
	{
	    puts("-1");
	}
	else
	{
	    printf("%d\n",ans);
	}
    }
  
	return 0;
}
