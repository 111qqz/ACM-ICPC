/*************************************************************************
	> File Name: code/poj/2688.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月14日 星期五 21时38分30秒
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
bool vis[N][N];
int dust_num;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int w;
int h;
int cnt;
int ans;
int dust_x[N];
int dust_y[N];
struct node
{
    int x,y;
    int time;

    bool ok ()
    {
	if (x>=0&&x<h&&y>=0&&y<w&&maze[x][y]!='X'&&!vis[x][y])
	    return true;
	return false;
    }
}s;

bool  flag;
int bfs( int sx, int sy)
{
    queue<node>q;
    s.x = sx;
    s.y = sy;
    q.push(s);
    memset(vis,false,sizeof(vis));
    
    while (!q.empty())
    {
	node pre = q.front();q.pop();
	if (maze[pre.x][pre.y]=='O')
	{
	    maze[sx][sy] = 'O';
	    maze[pre.x][pre.y] ='.';
	    return pre.time;
	}
	for ( int i = 0 ; i < 4 ; i++ )
	{
	    node next;
	    next.x = pre.x + dx[i];
	    next.y = pre.y + dy[i];
	    next.time = pre.time + 1;
	    if (!next.ok()) continue;
	    q.push(next);

	    
	}

    }
    return -1;
}
int main()
{
    while (~scanf("%d %d",&w,&h))
    {
	if (h==0&&w==0) break;
	for ( int i = 0 ; i < h ; i++)
	{
	    scanf("%s",maze[i]);
	}
	dust_num = 0;
	cnt  = 0;
	ans  = 0;
	for ( int i = 0 ; i< h ; i++)
	{
	    for ( int j = 0 ; j < w; j++)
	    {
		if (maze[i][j]=='*')
		{
		    dust_num++;
		    dust_x[dust_num] = i;
		    dust_y[dust_num] = j;
		}
	    }
	}
	flag = false;
	for ( int i = 1 ; i <= dust_num ; i++)
	{
	    int tmp = bfs(dust_x[i],dust_y[i]);
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
	cout<<"aaa"<<endl;
    }
  
	return 0;
}
