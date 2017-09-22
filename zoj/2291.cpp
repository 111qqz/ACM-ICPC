/*************************************************************************
	> File Name: code/zoj/2291.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月13日 星期四 21时08分40秒
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
char maze[21][21];
bool vis[21][21][(1<<5)+1];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int cnt[10];  //记录每把钥匙的数量
int ans;
int n,m;
int keynum[(1<<5)+1][10];
struct node
{
    int x,y;
    int time;
    int key;
    bool ok()
    {
	if (x>=0&&x<m&&y>=0&&y<n&&maze[x][y]!='X')
	    return true;
	return false;
    }
}s;
void bfs()
{
    s.time = 0;
    s.key = 0;
    vis[s.x][s.y][s.key] =  true;
    queue<node>Q;
    Q.push(s);
    while (!Q.empty())
    {
	node pre;
	pre = Q.front();
	Q.pop();
	cout<<pre.x<<" "<<pre.y<<" "<<pre.key<<endl;
	if (maze[pre.x][pre.y]=='G')
	{
	    ans = pre.time;
	    return;
	}
	
	for ( int i = 0 ; i < 4 ; i++ )
	{
	    node next;
	    next.x = pre.x + dx[i];
	    next.y = pre.y + dy[i];
	    next.time = pre.time + 1;
	    next.key = pre.key;
	    if (!next.ok()) continue;
//	    cout<<next.x<<" "<<next.y<<endl;
	    int ch = maze[next.x][next.y];
	    if (ch>='a'&&ch<='e')
	    {
		if (keynum[next.key][ch-'a']+1==cnt[ch-'a'])
		{
		    int newkey = 1<<(ch-'a');
		 if (ch=='a') cout<<cnt[ch-'a']<<endl;
		    next.key = next.key | newkey;
		}
		if (!vis[next.x][next.y][next.key])
		{
		    vis[next.x][next.y][next.key]=true;
		    keynum[next.key][ch-'a']++;
    		    
		    Q.push(next);
		}
	    }
	    else
	    if (ch=='A'&&ch<='E')
	    {
		int needkey = ch-'A';
	    //	cout<<"needkey:"<<needkey<<" "<<next.key<<endl;
		if (((next.key>>needkey)&1)&&!vis[next.x][next.y][next.key])
		{
			vis[next.x][next.y][next.key] = true;
			Q.push(next);
		}
	    }
	    else
	    {
		if (!vis[next.x][next.y][next.key])
		{
		    vis[next.x][next.y][next.key] = true;
		    Q.push(next);
		}
	    }


	}
	
    }

}
int main()
{
    while (~scanf("%d %d",&m,&n))
    {
	memset(keynum,0,sizeof(keynum));
	memset(cnt,0,sizeof(cnt));
	if (n==0&&m==0) break;
	for ( int i = 0 ; i < m ; i++ )
	{
	    scanf("%s",maze[i]);
	}
	for ( int i = 0 ; i < m ; i ++)
	{
	    for ( int j = 0 ; j < n ; j++)
	    {
		if (maze[i][j]=='S')
		{
		    s.x = i;
		    s .y = j;
		}
		if (maze[i][j]>='a'&&maze[i][j]<='e')
		{
		    cnt[maze[i][j]-'a']++;
		} 
		
	    }
	}
	memset(vis,false,sizeof(vis));
	bfs();

	if (ans==-1)
	{
	    cout<<"NO"<<endl;
	}
	else
	{
	    cout<<"YES"<<endl;
	}
    }
  
	return 0;
}
