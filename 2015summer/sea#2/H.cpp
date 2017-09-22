/*************************************************************************
	> File Name: code/2015summer/sea#2/H.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月28日 星期二 16时11分27秒
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
const int N=1E2+5;
int cnt,sum;
int n,m;
char maze[N][N];
int d[N][N];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool flag;
int tx,ty,wx,wy;
int res;
bool ok ( int x,int y)
{
 //   cout<<"x:"<<x<<" y:"<<y<<endl;
    if (x<0||y<0||x>=m||y>=n)
	  return false;
    if (maze[x][y]=='#')
	  return false;
    if (d[x][y]!=-1) return false;
    if (maze[x][y]=='C')
    {
	  cnt++;
	  return true;
    }
    if (maze[x][y]=='.')
    {
	  return true;
    }
    if (cnt==sum&&maze[x][y]=='W')
    {
	  return true;
    }
    return false;
}
void bfs()
{
    memset(d,-1,sizeof(d));
    queue<int>x;
    queue<int>y;
    x.push(tx);
    y.push(ty);
    d[tx][ty]=0;
    int p = 1;
    while (!x.empty())
    {
	  int px = x.front();x.pop();
	  int py = y.front();y.pop();
	  if (px==wx&&py==wy&&sum==cnt)
	  {
		flag = true;
		cout<<d[px][py]<<endl;
	  }
	  for ( int i = 0 ; i < 4 ; i++ )
	  {
		int nx = px + dx[i];
		int ny = py + dy[i];
		
		if (ok(nx,ny))
		{
		    if (nx==wx&&ny==wy&&sum!=cnt) continue;
		    d[nx][ny] = d[px][py] + 1;
		    if (sum==cnt&&p==1)
		    {
			  res = d[nx][ny];
			  memset(d,-1,sizeof(d));
			  d[nx][ny]==0;
			  p++;
		    }
		    x.push(nx);
		    y.push(ny);
		}
	  }

    }
}
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
	  res = 0;
	  flag = false;
        cnt = 0;
	  sum = 0;
	  scanf("%d %d",&m,&n);
	  for ( int i = 0 ; i < m ; i ++ )
	  {
		scanf("%s",maze[i]);
	  }
	  for ( int i = 0 ; i < m ; i++ )
	  {
		for ( int j = 0 ; j < n ; j++)
		{
		    if (maze[i][j]=='C')
		    {
			  sum++;
		    }
		    if (maze[i][j]=='T')
		    {
			  tx = i;
			  ty = j;
		    }
		    if (maze[i][j]=='W')
		    {
			  wx = i;
			  wy = j;
		    }
		}
	  }
	  bfs();
	  for ( int i  = 0 ; i < m ;i++ )
	  {
		for ( int j = 0 ; j < n ; j++ )
		{
		    cout<<d[i][j]<<" ";
		}
		cout<<endl;
	  }
	  if (!flag)
	  {
		cout<<"Mission Failed!"<<endl;
	  }
    }
  
	return 0;
}
