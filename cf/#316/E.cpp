/*************************************************************************
	> File Name: code/cf/#316/E.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月14日 星期五 01时55分05秒
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
const int N=5E2+7;
char maze[N][N];
int n,m;
int ans;
int total;
bool vis[N][N];
char rec[2*N]; //记录每一步拍的照片

bool ok (int x,int y)
{
    if (x>=0&&x<n&&y>=0&&y<m%%!vis[x][y])
	return true;
    return false;
}
void dfs ( int x,int y,char cur,int num)
{
    rec[num] = cur;
    :
    if (num==total)
    {
	ans++;
	return;
    }
    if (ok(x+1,y))
    {
	if (num<=total/2||rec[num]==rec[total+1-num])
	{

	    dfs(x+1,y,maze[x+1][y],num+1);
	}
    }

}
int main()
{
    cin>>n>>m
    memset(vis,false,sizeof(vis));
    for ( int i = 0 ; i < n ; i++ )
    {
	scanf("%s",maze[i]);
    }
    if (maze[0][0]!=maze[n-1][m-1])
    {
	cout<<0<<endl;
	return 0;
    }
    if (n==1&&m==2)
    {
	if (maze[0][0]==maze[0][1])
	{
	    puts("1");
	    return 0;
	}
	else
	{
	    puts("0");
	    return 0;
	}
    }
    if (n==2&&m==1)
    {
	if (maze[1][0]==maze[0][0])
	{
	    puts("1");
	    return 0;
	}
	else
	{
	    puts("0");
	    return 0;
	}
    }
    total = n+m-3;
    ans  = 0;
    dfs(0,0,maze[0][0],0);

  
	return 0;
}
