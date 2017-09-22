/* ***********************************************
Author :111qqz
Created Time :2016年04月04日 星期一 14时43分48秒
File Name :code/bzoj/1627.cpp
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
const int N=1E4+7;
const int C =500;
bool vis[1005][1005];
struct node
{
    int x,y;
    int d;

    bool ok ()
    {
	if (x>=0&&x<=1000&&y>=0&&y<=1000&&!vis[x][y]) return true;
	return false;
    }

    void look()
    {
	cout<<"x:"<<x-C<<" y:"<<y-C<<" d:"<<d<<endl;
    }
}s,tar;
int n;


void bfs()
{
    queue<node>q;
    s.x = 500;
    s.y = 500;
    s.d = 0;
    vis[500][500] = true;
    q.push(s);
    while (!q.empty())
    {
	node pre = q.front() ;q.pop();
//	pre.look();
	if (pre.x==tar.x&&pre.y==tar.y)
	{
	    cout<<pre.d<<endl;
	    return ;
	}
	
	
	for ( int i = 0 ; i < 4 ; i++)
	{
	    node nxt;
	    nxt.x = pre.x + dx4[i];
	    nxt.y = pre.y + dy4[i];
	    nxt.d = pre.d + 1;
	    if (nxt.ok())
	    {
		q.push(nxt);
		vis[nxt.x][nxt.y] = true;
	    }
	}
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>tar.x>>tar.y>>n;
	tar.x+=C;
	tar.y+=C;


	ms(vis,false);
	for ( int i = 1 ; i <= n ; i++)
	{
	    int u,v;
	    cin>>u>>v;
	    u+=C;
	    v+=C;
	    vis[u][v] = true;
	}

	bfs();


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
