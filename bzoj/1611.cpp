/* ***********************************************
Author :111qqz
Created Time :2016年04月02日 星期六 14时23分42秒
File Name :code/bzoj/1611.cpp
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
const int N=305;
int n;
int star[N][N];
bool vis[N][N];
struct node
{
    int x,y;
    int d;

    bool ok ()
    {
	if (x>=0&&y>=0&&!vis[x][y]&&d<star[x][y]) return true;
	return false;
    }

    bool safe()
    {
	//	cout<<"x:"<<x<<" y:"<<y<<endl;
	if (star[x][y]==inf) return true;
	return false;
    }

    void where()
    {
	cout<<"x:"<<x<<" y:"<<y<<" d :"<<d<<endl;
    }
}s;

void boom(int x,int y,int t)
{
    if (x-1>=0) star[x-1][y]=min(star[x-1][y],t);
    if (y-1>=0) star[x][y-1]=min(star[x][y-1],t);
    star[x+1][y]=min(star[x+1][y],t);
    star[x][y+1]=min(star[x][y+1],t);
    star[x][y]  =min(star[x][y] , t);
}

int bfs()
{
    queue<node>q;
    q.push(s);

    while (!q.empty())
    {

	node pre = q.front();q.pop();
	if (pre.safe()) return pre.d;
	//	pre.where();
	for ( int i = 0 ; i < 4 ; i++)
	{
	    node nxt;
	    nxt.x = pre.x + dx4[i];
	    nxt.y = pre.y + dy4[i];
	    nxt.d = pre.d + 1;
	    //   cout<<"nxt.d:"<<nxt.d<<endl;
	    if (nxt.ok())
	    {
		q.push(nxt);
		vis[nxt.x][nxt.y] = true;
	    }
	}
    }
    return -1;
}
int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
#endif                  //感觉题意有问题啊。。。这个第一象限大概是包括坐标轴的。。。不然从原点不可能一步到第一象限啊。

    scanf("%d",&n);
    ms(star,0x3f);
    for ( int i = 1 ;i  <= n ; i++)
    {
	int x,y,t;
	scanf("%d %d %d",&x,&y,&t);
	boom(x,y,t);

    }
    s.x = 0 ;
    s.y = 0;
    s.d = 0;
    vis[0][0] = true;
    printf("%d\n",bfs());




#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
