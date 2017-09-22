/* ***********************************************
Author :111qqz
Created Time :2016年04月05日 星期二 09时48分26秒
File Name :code/bzoj/1632.cpp
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
const int dx8[8]={2,2,-2,-2,1,1,-1,-1};
const int dy8[8]={1,-1,1,-1,2,-2,2,-2};
const int inf = 0x3f3f3f3f;
const int N=35;
int maze[N][N];
bool vis[N][N];
int n,m;
int cnt,ans,num;

struct node
{
    int x,y;
    int d;
    int lh;
    int num;

    node()
    {
	lh = inf;
	d = inf;
	num = 0 ;
    }
    bool operator < (node b)const
    {
	return lh>b.lh;
    }


    void look()
    {
	cout<<"x:"<<x<<" y:"<<y<<" d:"<<d<<" lh:"<<lh<<endl;
    }
}s,e;


void bfs()
{
    ms(vis,false);
    queue<node>q;
    vis[s.x][s.y] = true;
    q.push(s);

    while (!q.empty())
    {
	node pre = q.front() ; q.pop();
//	pre.look();
//	if (maze[pre.x][pre.y]==4)
//	{
//	    if (cnt==-1) cnt = pre.lh;
//	    if (pre.lh==cnt) ans = min(ans,pre.d);
//	}
	for ( int i = 0 ; i < 8 ; i++)
	{
	    node nxt ,tmp;
	    tmp.x = pre.x + dx8[i];
	    tmp.y = pre.y + dy8[i];
	    int tlh = pre.lh + (maze[nx][ny]==0);
	    //nxt.lh = pre.lh + nxt.add();
//	    cout<<"bbb:"<<endl;
	    if (nx<0||ny<0||nx>=n||ny>=m||maze[nx][ny]==2) continue;
//	    cout<<"aaa"<<endl;
	    if (tlh<tmp.lh)
	    {
		nxt.lh = tlh;
		nxt.num = pre.num;
		nxt.d = pre.d + 1;
		
		if (vis[nx][ny])
		{
		    q.push(nxt);
		    continue;
		}
		nxt.x = nx;
		nxt.y = ny;
		q.push(nxt);
		vis[nxt.x][nxt.y] = true;
	    }
	    else if(tlh==tmp.lh)
	    {
		 if (pre.d+1<tmp.d)
		 {
		    pre:.d = pre.d + 1;
		     tmp.num = pre.num;
		     if (vis[nx][ny])
		     {
			 q.push(nxt);
			 continue;
		     }
		     nxt.x = nx;
		     nxt.y = ny;
		     q.push(nxt);
		     vis[nxt.x][nxt.y] = true;
		 }
		 else if (pre.d+1==nxt.d)
		    {
			nxt.num += pre.num;
			if (vis[nx][ny]) 
			{
			    q.push(nxt);
			    continue;
			}
			
			nxt.x = nx;
			nxt.y = ny;
			q.push(nxt);
			vis[nxt.x][nxt.y] = true;
		    }
	    }
	    
	}

	vis[pre.x][pre.y] = false;
    }
  /*  queue<node>p;
    ms(vis,false);
    vis[s.x][s.y] = true;
    p.push(s);

    while (!p.empty())
    {
	node pre = p.front() ;p.pop();
	pre.look();
	if (maze[pre.x][pre.y]==4)
	{
	    if (pre.d==ans&&pre.lh==cnt) num++;
	}
	for ( int i = 0 ; i < 8 ; i++)
	{
	    node nxt ;
	    nxt.x = pre.x + dx8[i];
	    nxt.y = pre.y + dy8[i];
	    nxt.d = pre.d + 1;
	    nxt.lh = pre.lh + nxt.add();
	    if (nxt.lh>cnt) continue;
	    if (nxt.d>ans) continue;
	    if (nxt.ok())
	    {
		p.push(nxt);
		vis[nxt.x][nxt.y] = true;
		if (maze[nxt.x][nxt.y]==4) vis[nxt.x][nxt.y] = false;
	    }
	}
    }   */

}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	cin>>n>>m;
	for ( int i = 0 ; i < n;  i++)
	    for ( int j = 0 ; j < m; j++)
	    {
		cin>>maze[i][j];
		if (maze[i][j]==3)
		{
		    s.x = i;
		    s.y = j ;
		    s.d = 0 ;
		    s.lh = 0;
		    s.num = 1;
		}

		if (maze[i][j]==4)
		{
		    e.x = i ;
		    e.y = j ;
		}
	    }

	cnt = -1 ;
	num = 0 ;
	ans = inf;
	bfs();
	ms(vis,false);

	if (e.lh==-1)
	    cout<<e.lh<<endl;
	else cout<<e.lh<<endl<<e.d<<endl<<e.num<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
