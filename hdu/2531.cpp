/*************************************************************************
	> File Name: code/hdu/2531.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月11日 星期日 23时14分43秒
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
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=1E2+5;
int w,h;
char maze[N][N];
bool v[N][N];
int cnt ;
int fx[30];
int fy[30];
struct node
{
    int x,y;
    int d;
    bool ok()
    {
	if (x<0||y<0||x>=w||y>=h) return false;
	if (maze[x][y]=='O') return false;
	if (v[x][y]) return false;
	
	for ( int i =2 ; i <= cnt ; i++)
	{
	    int xx = x + fx[i];
	    int yy = y + fy[i];
	    if (xx<0||yy<0||xx>=w||yy>=h) return false;
	    if (maze[xx][yy]=='O') return false;
	}
	return true;
    }

    bool get()
    {
	if (maze[x][y]=='Q') return true;
	for ( int i = 2 ; i <= cnt ; i++)
	{
	    int xx = x + fx[i];
	    int yy = y + fy[i];
	    if (maze[xx][yy]=='Q')
	    {
		return true;
	    }
	}
	return false;
    }
}s;

bool bfs()
{
    
    queue<node>q;
    q.push(s);
    
    while (!q.empty())
    {
	node pre = q.front();q.pop();
	
//	printf("x: %d  y: %d d: %d \n",pre.x,pre.y,pre.d);
	
	if (pre.get())
	{
	    printf("%d\n",pre.d);
	    return true;
	}
	
	for ( int i = 0 ; i < 4 ; i++)
	{
	    node next;
	    next.x = pre.x + dx4[i];
	    next.y = pre.y + dy4[i];
	    next.d = pre.d + 1;
	    if (next.ok())
	    {
		v[next.x][next.y] = true;
		q.push(next);
	    }
	}
    }
    return false;
    
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   while (scanf("%d %d",&w,&h)!=EOF&&w&&h)
   {
       ms(v,false);
       cnt = 0 ;
       for ( int i = 0 ; i < w ; i++) scanf("%s",maze[i]);
	
       for ( int i = 0 ; i < w ; i++)
	   for ( int j = 0 ; j < h ; j++)
	   {
	       if (maze[i][j]=='D')
	       {
		   cnt++;
		   if (cnt==1)
		   {
		       fx[cnt] =  i;
		       fy[cnt] =  j;
		       s.x = i;
		       s.y = j;
		       s.d = 0 ;
		       v[i][j] = true;
		   }
		   else
		    {
			fx[cnt] = i - fx[1]; //相对位移．
			fy[cnt] = j - fy[1];
		    }
	       }
	   }

       if (!bfs())
	{
	    puts("Impossible");
	}
   }
   
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
