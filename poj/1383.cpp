/* ***********************************************
Author :111qqz
Created Time :2016年08月27日 星期六 13时46分45秒
File Name :code/poj/1383.cpp
j************************************************ */

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
const int N=1E3+7;
char maze[N][N];
bool vis[N][N];
int ans;
int n,m;
struct Point
{
    int x,y;
    int d;
    bool ok ()
    {
	if (x<0||y<0||x>=n||y>=m) return false;
	if (maze[x][y]=='#') return false;
	if (vis[x][y]) return false;
	return true;
    }
    void out()
    {
	cout<<"x:"<<x<<" y:"<<y<<endl;
    }
}S,lst;

void bfs(Point S)
{
    queue<Point>q;
    S.d = 0;
    q.push(S);
    ms(vis,false);
    vis[S.x][S.y] = true;
    
    while (!q.empty())
    {
	Point cur = q.front();
	q.pop();
	for ( int i = 0 ; i < 4 ; i++)
	{
	    Point nxt;
	    nxt.x = cur.x + dx4[i];
	    nxt.y = cur.y + dy4[i];
	    nxt.d = cur.d + 1;
	    if (!nxt.ok()) continue;
	    q.push(nxt);
	    vis[nxt.x][nxt.y] = true;
	    if (ans<nxt.d)
	    {
		ans = nxt. d;
		lst = nxt;
	    }
	}
//	cout<<"ans:"<<ans<<endl;
    }
    
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while(T--)
	{
	    ms(vis,false);
	    scanf("%d%d",&m,&n);
	    for ( int i =  0; i  < n ; i++) scanf("%s",maze[i]);
	     
	    for ( int i = 0 ; i < n ; i++)
		for ( int j = 0 ; j < m ; j++)
		    if (maze[i][j]=='.')
		    {
			S.x = i ;
			S.y = j ;
		    }
	    ans  = 0;
	    bfs(S);
	    ans = 0 ;
	    bfs(lst);
	    printf("Maximum rope length is %d.\n",ans);

	}
	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
