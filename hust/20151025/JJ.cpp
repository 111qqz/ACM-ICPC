*************************************************************************
	> File Name: code/hust/20151025/JJ.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月25日 星期日 14时52分17秒
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
#include<cctype>
                 
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const int dx4[4]={0,1,0,-1};
const int dy4[4]={1,0,-1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
int w,h;
bool vis[15][15][5];
char maze[15][15];
:int sx,sy;
int dir;
bool ok( int x,int y)
{
    if (x>=0&&y>=0&&x<w&&y<h&&maze[x][y]!='*')
	return true;
    return false;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   cin>>w>>h;
   for ( int i = 0 ; i < w ; i++) scanf("%s",maze[i]);

   for ( int i = 0 ; i < w ; i++)
       for ( int j = 0 ; j < h ; j++)
       {
	   if (maze[i][j]=='R')
	    {
		dir = 0;
		sx = i;
		sy = j;
	    }
	   if (maze[i][j] =='D')
	    {
		dir = 1;
		sx = i ;
		sy = j;
	    }
	   if (maze[i][j]=='L')
	    {
		dir = 2;
		sx = i;
		sy = j;
	    }
	   if (maze[i][j]=='U')
	    {
		dir = 3;
		sx = i;
		sy = j;
	    }
       }

   int step = 0;

   ms(vis,false);
   vis[sx][sy][dir] = true;
   while (step<=w*h*10)
    {
	step++;
	bool tmp = ok(sx+dx4[dir],sy+dy4[dir]);
	if (tmp)
	{
	    sx = sx + dx4[dir];
	    sy = sy + dy4[dir];
//	    cout<<"sx:"<<sx<<" sy:"<<sy<<endl;
	    if (vis[sx][sy][dir]) break;
	    vis[sx][sy][dir] = true;
	}
	else
	{
	    dir = dir+1;
	    dir = dir % 4;
	    if (vis[sx][sy][dir]) break;
	    vis[sx][sy][dir] = true;
	}

    }

    int ans = 0;
   for ( int i = 0 ; i < w ; i++)
       for ( int j = 0 ; j < h ; j++)
	    for ( int d = 0 ; d < 4 ; d++)
		if (vis[i][j][d])
		{
		    ans++;
	//	    cout<<"i:"<<i<<" j:"<<j<<endl;
		    break;
		}
   cout<<ans<<endl;
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
