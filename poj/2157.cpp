/*************************************************************************
	> File Name: code/poj/2157.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月14日 星期五 16时02分03秒
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
#include <cctype>
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x7fffffff;
const int N=25;
int n,m;
int key[10];
bool vis[N][N];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
char maze[N][N];
struct node
{
    int x,y;
    bool ok()
    {
	if (x>=0&&x<m&&y>=0&&y<n&&!vis[x][y]&&maze[x][y]!='X')
	    return true;
	return false;
    }
};
node s;
void BFS()
{
    queue<node>q;
    q.push(s);
    maze[s.x][s.y] = 'X';
    int step = 0;
    while(!q.empty() && step < m*n)
    {
        step++;
	node pre;
        pre = q.front();
        q.pop();
	char ch = maze[pre.x][pre.y];
        if (isupper(ch))
        {
            if (key[ch - 'A'] == 0)
            {
                maze[pre.x][pre.y] = 'X';
            }
            else
            {
                q.push(pre);
                continue;
            }
        }
        for (int i = 0; i < 4; i++)
        {
	    node next;
	    next . x = pre.x + dx[i];
	    next . y = pre.y + dy[i];
            if (next.ok())
            {
		char ch = maze[next.x][next.y];
                if (ch == '.') 
                {
                    maze[next.x][next.y] = 'X';
                    q.push(next);
                }
                if (islower(ch))
                {
                    key[ch - 'a']-- ;
                    maze[next.x][next.y] = 'X';
		    q.push(next);
                }
                if (ch == 'G')
                {
                    printf("YES\n");
                    return;
                }
                if (isupper(ch))
                {
		    q.push(next);
                }            
            }
        }
    }
    printf("NO\n");
}
int main()
{
    while (scanf("%d %d",&m,&n)!=EOF)
    {
	if (m==0&&n==0) break;
	memset(key,0,sizeof(key));
	for ( int i = 0 ; i < m ; i++)
	{
	    scanf("%s",maze[i]);
	}
	for ( int i = 0 ; i < m ; i ++)
	{
	    for ( int j = 0 ; j < n ; j ++)
	    {
		if (maze[i][j]=='S')
		{
		    s.x = i;
	 	    s.y = j;
		}
		if (islower(maze[i][j]))
		{
		    key[maze[i][j]-'a']++;
		} 
	    }
	}
	BFS();
    }
	return 0;
}
