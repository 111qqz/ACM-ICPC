/* ***********************************************
Author :111qqz
Created Time :2016年11月19日 星期六 18时56分06秒
File Name :code/wfly/#1/A.cpp
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
const int N=3E3+15;
int n,k;
char maze[4][N];
struct node
{
    int x,y;
    void out()
    {
	printf("x:%d y : %d\n",x,y);
    }
}s;
int a[3][N];
bool vis[3][N];
bool ok;
void bfs()
{
    ms(vis,false);
    queue<node>q;
    while (!q.empty()) q.pop();
    q.push(s);
    vis[s.x][s.y] = true;
    while (!q.empty())
    {
	node pre = q.front();
//	pre.out();
	q.pop();
	if (pre.y>=3*n-2) 
	{
	    ok = true;
	    return;
	}
	if (a[pre.x][pre.y+1]) continue; //走一步死。
	for ( int i = 0 ; i < 3 ; i++)
	{
	    if (abs(i-pre.x)>=2) continue ; //一次只能移动一步。
	    if (a[i][pre.y+1]) continue; //必须有空完成上下移动。
	    if (a[i][pre.y+2]) continue; 
	    if (a[i][pre.y+3]) continue;
	    if (vis[i][pre.y+3]) continue;
	    vis[i][pre.y+3] = true;
	    node tmp;
	    tmp.x = i;
	    tmp.y = pre.y+3;
	    q.push(tmp);
	}
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%d%d",&n,&k);
	    for ( int i = 0 ; i < 3 ; i++) scanf("%s",maze[i]);
	    for ( int i = 0 ; i < 3 ; i++)
	    {
		if (maze[i][0]=='s')
		{
		    s.x = i ;
		    s.y = 0 ;
		}
	    }
	    ms(a,0); // !!!
	    for ( int i = 0 ; i < 3 ; i++)
	    {
		for ( int j = 0 ; j < n ; j++)
		{
		    if (maze[i][j]=='.'||maze[i][j]=='s') a[i][j] = 0;
		    else a[i][j] = 1 ;
		}
	    }
	 /*   for ( int i = 0 ; i < 3 ; i++)
	    {
		for ( int j = 0 ; j < n ; j++) printf("%d",a[i][j]);
		printf("\n");
	    } */
	    ok = false;
	    bfs();
	    if (ok)
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
