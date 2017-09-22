/*************************************************************************
	> File Name: code/whust/#0.2/J.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月09日 星期日 12时54分56秒
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
const int N=1E2+5;
char maze[N][N];
int tar[5][2];
int beg[4*N][2];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int total;
int h,w;
int sum;
bool v[N][N];
struct NODE
{
    int d,prex,prey;
}q[N][N][2];
bool ok ( int x,int y,int num)
{
    if (x>=0&&x<h&&y>=0&&y<w&&q[x][y][num].d==-1&&maze[x][y]!='*')
	return true;
    return false;
}
void bfs ( int sx,int sy,int num)
{
    q[sx][sy][num].d = 0;
    queue<int>x;
    queue<int>y;
    x.push(sx);
    y.push(sy);
    while (!x.empty())
    {
	int px = x.front();x.pop();
	int py = y.front();y.pop();
	//cout<<"px:"<<px<<" py:"<<py<<endl;
	for ( int i = 0 ; i < 4 ; i ++ )
	{
	    int nx = px + dx[i];
	    int ny = py + dy[i];
//	   cout<<"nx:"<<nx<<" ny:"<<ny<<endl;
	    if (ok(nx,ny,num))
	    {
	//	cout<<"why???"<<endl;
  		if (maze[nx][ny]=='#')
		{
// 	 	    q[nx][ny][num].d = q[px][py][num].d+1;
		    q[nx][ny][num].prex = px;
		    q[nx][ny][num].prey = py;
		 //   maze[nx][ny]='.';
		}
		else
		{
 // 		    q[nx][ny][num].d = q[px][py][num].d;
		    q[nx][ny][num].prex = px;
 		    q[nx][ny][num].prey = py;
		}
		x.push(nx);
		y.push(ny);
	    }
	}
    }
}
void solve ( int x,int y)
{
//    cout<<"x:"<<x<<" y:"<<y<<endl;
    if (q[x][y][0].prey!=-1&&q[x][y][0].prex!=-1)
    {
	solve(q[x][y][0].prex,q[x][y][0].prey);
	if (!v[x][y]&&maze[x][y]=='#')
	{
	    sum++;
//	    cout<<"sum:"<<sum<<endl;
	    v[x][y] = true;
	}
    }
}
void solve2( int x,int y)
{
//      cout<<"x:"<<x<<" y:"<<y<<endl;
    if (q[x][y][1].prex!=-1&&q[x][y][1].prey!=-1)
    {
	solve2(q[x][y][1].prex,q[x][y][1].prey);
	if (!v[x][y]&&maze[x][y]=='#')
	{
	    sum++;
	    v[x][y] =true;
	}
    }
}
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
	scanf("%d %d",&h,&w);
	int cnt  = 0;
	for ( int i = 0 ; i < h ; i ++ )
	{
	    cin>>maze[i];
	}
	for ( int i =  0 ; i < h ; i ++ )
	{
	    for ( int j = 0 ; j  <  w ; j ++ )
	    {
		if (maze[i][j]=='$')
		{
		     cnt++;
		     tar[cnt][0] = i;
	 	     tar[cnt][1] = j;
		    // cout<<"tarx:"<<i<<" tary:"<<j<<endl;
	 	} 
	    }
	}
	cnt  = 0;
	for ( int i = 0 ; i < h ; i ++ )
	{
	    if (maze[i][0]=='.'||maze[i][0]=='#')
	    {
 		cnt++;
		beg[cnt][0]=i;
		beg[cnt][1]=0;
	    }
	    if (maze[i][w-1]=='.'||maze[i][w-1]=='#')
	    {
 		cnt++;
		beg[cnt][0]=i;
		beg[cnt][1]=w-1;
	    }
	}
	for ( int j = 0 ; j < w ; j ++)
	{
	    if (maze[0][j]=='.'||maze[0][j]=='#')
	    {
 	 	cnt++;
		beg[cnt][0]=0;
		beg[cnt][1]=j;
	    }
	    if (maze[h-1][j]=='.'||maze[h-1][j]=='#')
	    {
 	 	cnt++;
		beg[cnt][0]=h-1;
		beg[cnt][1]=j;
	    }
	}
	memset(q,-1,sizeof(q));
	bfs(tar[1][0],tar[1][1],0);
	bfs(tar[2][0],tar[2][1],1);
	int ans = inf;
	for ( int i =  1; i  <= cnt ; i ++)
	{
	    int tmpx = beg[i][0];
	    int tmpy = beg[i][1];
	 //   if (q[tmpx][tmpy][0].d==-1||q[tmpx][tmpy][1].d==-1) continue;
	    sum = 0;
	    memset(v,false,sizeof(v));
	    solve(tmpx,tmpy);	
	    solve2(tmpx,tmpy);
//	    cout<<"sum:"<<sum<<endl;
	    ans = min (ans,sum);
	}
	cout<<ans<<endl;
    }
	return 0;
}
