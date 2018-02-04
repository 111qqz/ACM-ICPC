/*************************************************************************
	> File Name: code/2015summer/searching/J.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月27日 星期一 19时19分16秒
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
const int N= 1E3+5;
const int inf = 0x7fffffff;
char maze[N][N];
int d[N][N],f[N][N],n,m;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int sx,sy;
int px,py;
bool flag;
int ans;
queue<int>x;
queue<int>y;
bool ok(int x,int y)
{
    if (x>=0&&x<n&&y>=0&&y<m&&maze[x][y]!='#'&&f[x][y]==-1) return true;
    return false;
}
bool ok2(int x,int y) {
    if (maze[x][y]!='#'&&d[x][y]==-1&&d[px][py]+1<f[x][y]&&x>=0&&x<n&&y>=0&&y<m)
	  return true;
    return false;
}

bool be_to_escape(int x,int y)   //可以站在边界就可以逃出去,如果判断是否逃出去会越界(下标问题),那我就判断是否站在边界.
{
    if (x==n-1||x==0||y==m-1||y==0)
	  return true;
    return false;
}

void bfs()
{
    while (!x.empty()&&!y.empty())
    {
	  int	px = x.front();x.pop();
	  int	py = y.front();y.pop();
	  for ( int i = 0 ; i < 4 ; i++)
	  {
		int nx = px + dx[i];
		int ny = py + dy[i];
		if (ok(nx,ny))
		{
		    f[nx][ny]=f[px][py]+1;
		    x.push(nx);
		    y.push(ny);
		} } } }
void bfs2() {
    memset(d,-1,sizeof(d));
    queue<int>xx;
    queue<int>yy;
    xx.push(sx);
    yy.push(sy);
    d[sx][sy]=0;
    while (!xx.empty()&&!yy.empty())
    {
		 px = xx.front();xx.pop();
		 py = yy.front();yy.pop();
	  if (be_to_escape(px,py))
	  {
		flag = true;
		cout<<d[px][py]+1<<endl;
	//	cout<<"is escape??"<<endl;
		return;
	  }
	  for ( int i = 0 ; i < 4 ; i++ )
	  {
		int nx = px + dx[i];
		int ny = py + dy[i];
		if (ok2(nx,ny))
		{
		    d[nx][ny]=d[px][py]+1; 
		    xx.push(nx);
		    yy.push(ny);
		}
	  }
    }
}
int main()
{
    int T;
    cin>>T;
    while (T--)         //下标从0开始,可能越界2333
    {
	   ans = inf ;
	  while (!x.empty()) x.pop();
	  while (!y.empty()) y.pop();
	  flag = false;
	  memset(f,-1,sizeof(f));
	  scanf("%d %d",&n,&m);
	  for ( int i = 0 ; i < n; i ++ )
	  {
		scanf("%s",maze[i]);
	  }
	  for ( int i = 0 ; i  < n; i ++ )
	  {
		for ( int j = 0 ; j < m ; j++ )
		{
		    if (maze[i][j]=='F')
		    {
			  f[i][j]=0;
			  x.push(i);
			  y.push(j);
		    }
		    if (maze[i][j]=='J')
		    {
			  sx = i;
			  sy = j;
		    }
		}
	  }
	  bfs();
	  bfs2();
/*	  for ( int i = 0;  i < n ; i++ )
	  {
		for ( int j = 0 ; j  < m ; j++ )
		{
		    cout<<d[i][j]<<" ";
		}
		cout<<endl;
	  }   */ 
	  if (!flag)
	  {
		cout<<"IMPOSSIBLE"<<endl;
	  }    
    }
  
	return 0;
}
