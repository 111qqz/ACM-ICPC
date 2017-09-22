/*************************************************************************
	> File Name: code/loj/r1066.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月11日 星期二 20时35分17秒
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
const int N=13;
char maze[N][N];
int d[N][N];
int n;
int sx,sy;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};


bool ok (int x,int y)
{
    if (x>=0&&x<n&&y>=0&&y<n&&d[x][y]==-1)
	return true;
    return false;
}
int bfs( int xx,int yy,char goal)
{
    memset(d,-1,sizeof(d));
    d[xx][yy]=0;
    queue<int>x;
    queue<int>y;
    x.push(xx);
    y.push(yy);

    while (!x.empty())
    {
	int px = x.front();x.pop();
	int py = y.front();y.pop();
	if (maze[px][py]==goal)
	{
	    sx = px;
	    sy = py;
	    maze[sx][sy]='.';
	    return d[px][py];
	}
	for ( int i = 0 ; i < 4 ; i++ )
	{
	    int nx = px + dx[i];
	    int ny = py + dy[i];
	    if (ok(nx,ny)&&(maze[nx][ny]=='.'||maze[nx][ny]==goal))
	    {
		d[nx][ny] = d[px][py] + 1;
		x.push(nx);
		y.push(ny);
	    }
	}
    }
    return -1;
}
int main()
{
    int T;
    cin>>T;
    int cas = 0;
    while (T--)
    {
	cas++;
	scanf("%d",&n);
	for ( int i = 0 ; i < n ; i++ )
	{
	    scanf("%s",maze[i]);
	}
	int cnt  = 0;
	for ( int i = 0 ; i < n ; i++ )
	{
	    for ( int j = 0 ; j < n ; j++ )
	    {
		if (maze[i][j]=='A')
		{
		    sx = i ;
		    sy = j;
		}
		if (maze[i][j]!='.'&&maze[i][j]!='#')
		{
		    cnt++;
		}
	    }
	}
	int ans  =0;
	bool flag = false;
	for ( int i = 0 ; i < cnt ; i ++ )
	{
	    int tmp = bfs(sx,sy,i+'A');
	    if (tmp==-1)
	    {
		flag = true;
		break;
	    }
	    ans = ans + tmp;
	}
	printf("Case %d: ",cas); 
	if (flag)
	{

	    printf("Impossible\n");
	}
	else
	{

	    printf("%d\n",ans);
	}
    }
  
	return 0;
}
