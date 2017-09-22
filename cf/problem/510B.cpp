/* ***********************************************
Author :111qqz
Created Time :2015年12月05日 星期六 21时35分07秒
File Name :code/cf/problem/510B.cpp
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
const int N=55;
int n,m;
char maze[N][N];
bool vis[N][N];
bool flag;


bool inmaze( int x,int y)
{
    if (x>=0&&x<n&&y>=0&&y<m) return true;
    return false;
}
void dfs( int x,int y,int px,int py)  //要记录当前的x,y是由哪里来的。把因为由px,py到x,y再回到px,py引起的误判剔除。
{					//判cycle方式为：到达一个之前已经到达过的点。
    vis[x][y] = true;
   // cout<<"x:"<<x<<" y:"<<y<<" cur:"<<cur<<endl;
    if (flag) return;
    for ( int i = 0 ; i < 4 ; i++)
    {
	int nx = x + dx4[i] ; 
	int ny = y + dy4[i] ;
	if (nx==px&&ny==py) continue;
	if (inmaze(nx,ny)&&maze[nx][ny]==maze[x][y])
	{
	    if (!vis[nx][ny])
	    {
		dfs(nx,ny,x,y);
	    }
	    else
	    {
		flag = true;
		return ;
	    }
	}
    }
    
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d %d",&n,&m);
	for ( int i = 0 ; i < n ; i++) scanf("%s",maze[i]);
	ms(vis,false);
	flag = false;
	for ( int i = 0 ; i < n ;i++)
	{
	    if (flag) break;
	    for ( int j = 0 ; j < m ; j++)
	    {
		if (flag) break;
		if (!vis[i][j])
		{
		    dfs(i,j,-1,-1);
		}
	    }
	}
	if (flag)
	{
	    puts("Yes");
	}
	else
	{
	    puts("No");
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
