/* ***********************************************
Author :111qqz
Created Time :2015年12月05日 星期六 14时06分54秒
File Name :code/cf/problem/377A.cpp
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



using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=5E2+7;
char maze[N][N];
bool vis[N][N];
int n,m,k;
int sx,sy;
int sum;
int num;
bool flag = false;
bool ok ( int x,int y)
{
    if (x>=0&&y>=0&&x<=n-1&&y<=m-1&&maze[x][y]=='.'&&!vis[x][y]) return true;
    return false;
}

void dfs( int x,int y)
{
    vis[x][y] = true;
    maze[x][y]='R';
  //  cout<<"x:"<<x<<" y:"<<y<<" num:"<<num<<" sum:"<<sum<<endl;
    if (num>=sum-k)
    {
	return;
    }
    for ( int i = 0 ; i < 4 ; i++)
    {
	int nx = x + dx4[i];
	int ny = y + dy4[i];
	if (num>=sum-k) break;
	if (ok(nx,ny))
	{
	    num++;
	    dfs(nx,ny);
	}
    }
}

void print()
{
    for ( int i = 0 ; i < n;  i++) printf("%s\n",maze[i]);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	
	ms(vis,false);
	scanf("%d%d%d",&n,&m,&k);
	sum = 0 ;
	for ( int i = 0 ; i < n ; i++)
	{
	    scanf("%s",maze[i]);
	    for ( int j = 0 ; j < m; j++)
	    {
		if (maze[i][j]=='.')
		{
		    sum++;
		    sx = i;
		    sy = j;
		}
	    }
	}
//	cout<<"sum"<<sum<<endl;
	num = 1;
	dfs(sx,sy);
	for ( int i = 0 ; i < n ; i++)
	{
	    for ( int j = 0 ; j < m;  j++)
	    {
		if (maze[i][j]=='.')
		{
		    maze[i][j]='X';
		}
		if (maze[i][j]=='R')
		{
		    maze[i][j]='.';
		}
	    }
	}
	print();

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
