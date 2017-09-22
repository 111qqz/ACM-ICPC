/* ***********************************************
Author :111qqz
Created Time :2016年04月03日 星期日 20时01分12秒
File Name :code/bzoj/1619.cpp
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
const int dx8[8]={1,1,1,0,0,-1,-1,-1};
const int dy8[8]={1,0,-1,-1,1,1,0,-1};
const int inf = 0x3f3f3f3f;
const int N=705;
int h[N][N];
bool bad[N][N];
int n,m;
bool vis[N][N];
void checkvis();

struct node
{
    int x,y;

    bool inmaze ()
    {
	if (x>=1&&y>=1&&x<=n&&y<=m)  return true;
	return false;
    }

    void look()
    {
	cout<<x<<" "<<y<<endl;
    }
}s;
bool ok ( int x,int y)
{
 //   if (x-1>=1&&h[x-1][y]>h[x][y])  return false;
 //   if (x+1<=n&&h[x+1][y]>h[x][y])  return false;
 //   if (y-1>=1&&h[x][y-1]>h[x][y])  return false;
 //   if (y+1<=m&&h[x][y+1]>h[x][y])  return false;

    for ( int i = 0 ; i < 8 ; i++)
    {
	int nx = x + dx8[i];
	int ny = y + dy8[i];
	if (nx<1||nx>n||ny<1||ny>m) continue;
	if (h[nx][ny]>h[x][y]) return false;
    }
    return true;
}


bool bfs( int x,int y)
{
    queue<node>q;
    s.x = x;
    s.y = y;
    q.push(s);
    vis[x][y] = true;
    bool res = true;
    while (!q.empty())
    {
	node pre = q.front() ;q.pop();
//	pre.look();
//	checkvis();
	if (!res) bad[pre.x][pre.y] = true;


	for ( int i = 0 ; i < 8 ; i++)
	{
	    node nxt;
	    nxt.x = pre.x + dx8[i];
	    nxt.y = pre.y + dy8[i];
	    if (!nxt.inmaze()) continue;
	    if (vis[nxt.x][nxt.y]) continue;
	  //  vis[nxt.x][nxt.y] = true;
	    if (h[nxt.x][nxt.y]!=h[pre.x][pre.y]) continue;
	    if (bad[nxt.x][nxt.y])
	    {
		res = false;
	    }
	    if (!ok(nxt.x,nxt.y))
	    {
		res = false;
	    }
//	    nxt.look();
	    q.push(nxt);
	    vis[nxt.x][nxt.y] = true;
	}
    }

    return res;

}

void checkbad()
{
    for ( int i = 1 ; i <= n ; i++)
    {
	for ( int j = 1 ; j <= m ; j++)
	{
	    cout<<bad[i][j]<<" ";
	}
	cout<<endl;
    }
}

void checkvis()
{
    for ( int i = 1 ; i <= n ; i++)
    {
	for ( int j = 1 ; j <= m ; j++)
	{
	    cout<<vis[i][j]<<" "; 
	}
	cout<<endl;
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	cin>>n>>m;
	for ( int i = 1 ; i <= n ; i++)
	    for ( int j = 1 ; j <= m ; j++) cin>>h[i][j];
	ms(bad,false);

	for ( int i = 1 ; i <= n ; i++)
	{
	    for ( int j = 1 ; j <= m ; j++)
	    {
		if (!ok(i,j)) bad[i][j] = true;
	    }
	}
	ms(vis,false);
//	checkbad();
	int ans = 0 ;
	for ( int i = 1 ; i <= n ; i++)
	{
	    for ( int j = 1 ; j  <= m ; j++)
	    {
		if (vis[i][j]) continue;
		if (bad[i][j]) continue;
		if (bfs(i,j))
		{
		    ans++;
		  //  cout<<i<<" "<<j<<endl;
		}
	//	else cout<<"bad:"<<endl;
	    }
	}

	cout<<ans<<endl;



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
