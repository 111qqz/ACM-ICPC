/* ***********************************************
Author :111qqz
Created Time :2016年04月06日 星期三 23时04分48秒
File Name :code/bzoj/r1632.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define fst first
#define sec second
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;
#define pi pair < int ,int >
#define MP make_pair

using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int dx8[8]={2,2,-2,-2,1,1,-1,-1};
const int dy8[8]={1,-1,1,-1,2,-2,2,-2};
const int inf = 0x3f3f3f3f;
const int N=50;
int maze[N][N];
bool vis[N][N];
LL lh[N][N],d[N][N],num[N][N];

int n ,m;
int sx,sy,ex,ey;



void bfs()
{
    queue<int>x,y;
    x.push(sx);
    y.push(sy);
    vis[sx][sy] = true;

    while (!x.empty()&&!y.empty())
    {
	int px = x.front();x.pop();
	int py = y.front();y.pop();

	for ( int i = 0  ;i  < 8 ; i++)
	{
	    int nx = px + dx8[i];
	    int ny = py + dy8[i];

	    if (nx<0||ny<0||nx>=n||ny>=m||maze[nx][ny]==2) continue;
	    int tlh = lh[px][py] + (maze[nx][ny]==0);

	    if (tlh<lh[nx][ny])
	    {
		lh[nx][ny] = tlh;
		d[nx][ny] = d[px][py]+1;
		num[nx][ny] = num[px][py];
		if (vis[nx][ny]) continue;
		vis[nx][ny] = true;
		x.push(nx);
		y.push(ny);
	    }else if (tlh==lh[nx][ny])
	    {
		if (d[px][py]+1<d[nx][ny])
		{
		    d[nx][ny] = d[px][py] + 1;
		    num[nx][ny] =num[px][py];
		    if (vis[nx][ny]) continue;
		    vis[nx][ny] = true;
		    x.push(nx);
		    y.push(ny);

		}else if (d[px][py]+1==d[nx][ny])
		{
		    num[nx][ny]+=num[px][py];
		    if (vis[nx][ny]) continue;
		    vis[nx][ny] = true;
		    x.push(nx);
		    y.push(ny);
		}
	    }
	}

	vis[px][py] = false;
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	cin>>n>>m;
	for ( int i = 0  ; i <n ;  i++)
	    for ( int j =  0 ; j < m;  j++)
	    {
		cin>>maze[i][j];
		lh[i][j]=d[i][j] = inf;
		if (maze[i][j]==3)
		{
		    sx = i;
		    sy = j;
		    lh[sx][sy] = 0;
		    d[sx][sy]=0;
		    num[sx][sy] = 1;
		}
		if (maze[i][j]==4)
		{
		    ex = i ;
		    ey = j ;
		}
	    }

	ms(vis,false);
	bfs();

	if (lh[ex][ey]==inf)
	    cout<<-1<<endl;
	else cout<<lh[ex][ey]<<endl<<d[ex][ey]<<endl<<num[ex][ey]<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
