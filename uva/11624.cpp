/*************************************************************************
	> File Name: uva/11624.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月18日 星期日 22时51分14秒
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
const int N=2333;

int T;
int n,m;
char maze[N][N];
bool v[N][N];
int d[N][N];

struct node
{
    int x,y;
    int d;

    bool ok()
    {
	if (x>=0&&y>=0&&x<n&&y<m&&maze[x][y]!='#'&&!v[x][y]) return true;
	return false;
    }
    bool go()
    {
	if (x==0||y==0||x==n-1||y==m-1) return true;
	return false;
    }
    
    
}s;

bool ok( int x,int y)
{
    if (x>=0&&y>=0&&x<n&&y<m&&maze[x][y]!='#'&&d[x][y]==-1) return true;
    
    return false;
}

void solve()
{
    queue<int>x;
    queue<int>y;
    ms(d,-1);
    for ( int i = 0 ; i < n ; i++ )
	for ( int j = 0 ; j < m ; j++)
	{
	    if (maze[i][j]=='F')
	    {
		x.push(i);
		y.push(j);
		d[i][j] = 0;
	    }
	}

    while (!x.empty())
    {
	int px = x.front();x.pop();
	int py = y.front();y.pop();
	
	for ( int i = 0 ; i < 4 ; i++)
	{
	    int nx = px + dx4[i];
	    int ny = py + dy4[i];
	    if (ok(nx,ny))
	    {
		x.push(nx);
		y.push(ny);
		d[nx][ny] = d[px][py]+1;
	    }
	}
    }
}

bool bfs()
{
    queue<node>q;
    ms(v,false);
    for ( int i = 0 ; i < n ; i++)
	for ( int j = 0 ; j < m ;j++)
	    if (maze[i][j]=='J')
	    {
		s.x = i;
		s.y = j;
		s.d = 0;
		q.push(s);
		v[i][j] = true;
	    }

    while (!q.empty())
    {
	node pre = q.front();q.pop();
	
	if (pre.go()&&pre.d<=d[pre.x][pre.y])
	{
	    printf("%d\n",pre.d+1);
	    return true;
	}
	for ( int  i = 0 ; i < 4 ; i++)
	{
	    node next;
	    next.x = pre.x + dx4[i];
	    next.y = pre.y + dy4[i];
	    next.d = pre.d + 1;
	    if (next.ok())
	    {
		q.push(next);
		v[next.x][next.y]= true;
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

   cin>>T;
   while (T--)
   {
       scanf("%d %d",&n,&m);
       for ( int i = 0 ; i < n ; i++) scanf("%s",maze[i]);
	
       solve();
       if (!bfs())
	{
	    puts("IMPOSSIBLE");
	}
   }

  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
