/*************************************************************************
	> File Name: code/hdu/2102.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月02日 星期五 09时43分07秒
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
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
#define lr dying111qqz
using namespace std;
#define For(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
char maze[2][11][11];
int d[2][11][11];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
bool vis[2][11][11];
int n,m,t;
struct node
{
    int x,y,z;
    int d;
    bool ok()
    {
	if (x<0||y<0||x>=n||y>=m) return false;
	if (vis[z][x][y])    return false;
	if (maze[z][x][y]=='*') return false;
	if (maze[z][x][y]=='#'&&(maze[z^1][x][y]=='#'||maze[z^1][x][y]=='*'||vis[z^1][x][y])) return false;
	return true;
    }
    
};
node s;
bool bfs()
{
    s.x = 0 ;
    s.y = 0;
    s.z = 0;
    s.d = 0 ;
    queue<node>q;
    q.push(s);
    vis[0][0][0] = true;
    while (!q.empty())
    {
	node pre;
	pre = q.front();
	q.pop();
	char tmp = maze[pre.z][pre.x][pre.y];
//	cout<<pre.z<<" "<<pre.x<<" "<<pre.y<<endl;
	if (tmp=='P')
	{
	   // cout<<"pre.d"<<pre.d<<endl;
	    if (pre.d<=t) return true;
	    return false;
	}
	

	for ( int i = 0 ;  i <  4 ; i++)
	{
	    node nxt;
	    nxt.x = pre.x + dx[i];
	    nxt.y = pre.y + dy[i];
	    nxt.z = pre.z;
	    nxt.d = pre.d + 1;
	    if (!nxt.ok()) continue;
	    if (maze[nxt.z][nxt.x][nxt.y]=='.'||maze[nxt.z][nxt.x][nxt.y]=='P')
	    {
		q.push(nxt);
		vis[nxt.z][nxt.x][nxt.y]= true;
	    }
	    else
	    {
		nxt.z = pre.z ^ 1;
		q.push(nxt);
		vis[nxt.z][nxt.x][nxt.y] = true;
	    }

	}
    }
   // cout<<"ahhhh"<<endl;
    return false;


}
int main()               //遇到传送门就一定要传送！并不是可以选择的！
{			//所以如果一个传送门传送到的位置是障碍物，那这个转送门直接就是不可以到达的！等效于障碍物！
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
    int T;
    scanf("%d",&T);
    while (T--)
    {
	ms(vis,false);
	scanf("%d %d %d",&n,&m,&t);
	for ( int i = 0 ; i < n ; i++) scanf("%s",maze[0][i]);
	for ( int i = 0 ; i < n ; i++) scanf("%s",maze[1][i]);
	if (bfs())
	{
	    puts("YES");
	}
	else
	{
	    puts("NO");
	}
    }
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
