/* ***********************************************
Author :111qqz
Created Time :2016年04月10日 星期日 17时00分22秒
File Name :code/bzoj/1644.cpp
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
const int inf = 0x3f3f3f3f;
const int N=105;
char maze[N][N];
int n;
bool vis[N][N];
int dir[N][N][5];
struct node
{
    int x,y;


    bool ok ()
    {
	if (x>=0&&x<n&&y>=0&&y<n&&maze[x][y]!='x') return true;
	return false;
    }

    void look()
    {
	cout<<"x:"<<x<<" y:"<<y<<endl;
    }

}s,e;

void bfs()
{
    queue<node>q;
    q.push(s);

    while (!q.empty())
    {
	node pre = q.front(); q.pop();
//	pre.look();
	for ( int i = 0 ; i < 4 ; i++)
	{
	    node nxt;
	    nxt.x = pre.x + dx4[i];
	    nxt.y = pre.y + dy4[i];
    	    if (!nxt.ok()) continue; 
	    for ( int j = 0 ; j < 4 ; j++)
	    {
		bool flag = false;
		if (i==j&&dir[nxt.x][nxt.y][i]>dir[pre.x][pre.y][j])
		{
		    dir[nxt.x][nxt.y][i] = dir[pre.x][pre.y][j];
		    flag = true;
		}
		if (i!=j&&dir[nxt.x][nxt.y][i]>dir[pre.x][pre.y][j]+1)
		{
		    dir[nxt.x][nxt.y][i] = dir[pre.x][pre.y][j] + 1;
		    flag = true;
		}
		if (flag)
		{
		    q.push(nxt);
		}

	    }
	}
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d",&n);
	for ( int i = 0 ; i < n ; i++) scanf("%s",maze[i]);

	for ( int i = 0 ; i < n ; i ++)
	    for ( int j = 0 ; j < n ; j++)
		{
		    if (maze[i][j]=='A')
		    {
			s.x = i ;
			s.y = j;
		    }
		    if (maze[i][j]=='B')
		    {
			e.x = i ;
			e.y = j ;
		    }
		}

	ms(dir,0x3f);
	for ( int i = 0 ; i < 4 ; i++) dir[s.x][s.y][i] = 0;
	bfs();
//	for ( int i = 0 ; i < 4 ; i++) cout<<dir[e.x][e.y][i]<<endl;
	int ans = inf;
	for ( int i = 0 ; i < 4 ; i++) ans = min(ans,dir[e.x][e.y][i]);
	printf("%d\n",ans);

    return 0;
}
	
