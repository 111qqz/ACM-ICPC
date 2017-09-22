/*************************************************************************
	> File Name: code/sea#4/K.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月13日 星期四 19时23分54秒
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
const int N=21;
char maze[N][N];
int n,m,t,sx,sy;
int d[2100][N][N];

void bfs()
{
    memset(d,-1,sizeof(d));
    queue<int>x,y;
    d[0][sx][sy] = 0;
    
}
int main()
{
    while (scanf("%d %d %d",&n,&m,&t)!=EOF)
    {
	for ( int i = 0 ; i < n ; i++ )
	{
	    scanf("%s",maze[i]);
	}
	for ( int i = 0 ;  i  < n ; i++ )
	{
	    for ( int j = 0 ; j < m ; j++ )
	    {
		if (maze[i][j]=='@')
		{
		    sx =  i;
		    sy = j;
		}
	    }
	}
	bfs();
    }
  
	return 0;
}
