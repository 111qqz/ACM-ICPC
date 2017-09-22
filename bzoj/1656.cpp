/* ***********************************************
Author :111qqz
Created Time :2016年04月14日 星期四 22时29分15秒
File Name :code/bzoj/1656.cpp
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
const int dx8[8]={1,1,1,0,0,-1,-1,-1};
const int dy8[8]={1,0,-1,1,-1,1,0,-1};
const int inf = 0x3f3f3f3f;
const int N=55;
char maze[N][N];
int n,m;
int ans;
int f[2][N][N];//f[k][i][j]表示的是从起点走到(i,j),射线法与多边形交点的奇偶性的k的最短路。
//起点为f[0][s.x][s.y],答案为f[1][s.x][s.y];
bool die[N][N]; //画一条射线。。
struct node
{
    int x,y;
    int f;//f表示改点射线法与多边形交点的奇偶性。
    
    bool ok()
    {
	if (x>=0&&x<n&&y>=0&&y<m&&maze[x][y]!='X') return true;
	return false;
    }
}s,tree;


void bfs()
{
    queue<node>q;
    s.f = 0;
    q.push(s);

    while (!q.empty())
    {
	node pre = q.front() ; q.pop();
	for ( int i = 0 ; i < 8 ; i++)
	{
	    node nxt;
	    nxt.x = pre.x + dx8[i];
	    nxt.y = pre.y + dy8[i];
	    if (!nxt.ok()) continue;
	    if ((die[pre.x][pre.y]||die[nxt.x][nxt.y])&&nxt.y<=pre.y) continue;
	    if (die[nxt.x][nxt.y]&&!f[1][nxt.x][nxt.y])
	    {
		f[1][nxt.x][nxt.y] = f[pre.f][pre.x][pre.y]+1;
		nxt.f = 1;
		q.push(nxt);
	    }else if (!f[pre.f][nxt.x][nxt.y])
	    {
		f[pre.f][nxt.x][nxt.y] = f[pre.f][pre.x][pre.y] + 1;
		nxt.f = pre.f;
		q.push(nxt);
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
	
	for ( int i = 0 ; i < n ; i++)
	{
	    for ( int j = 0 ; j < m ; j++)
	    {
		if (maze[i][j]=='*')
		{
		    s.x = i ;
		    s.y = j;
		}
		if (maze[i][j]=='X')
		{
		    tree.x = i ;
		    tree.y = j;
		}
	    }
	}

	ms(die,false);
	for ( int i = 0 ; i < n ; i++) if (i+tree.x<n) die[i+tree.x][tree.y] = true;
	
	bfs();
	printf("%d\n",f[1][s.x][s.y]);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
