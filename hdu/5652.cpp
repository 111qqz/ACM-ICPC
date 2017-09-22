/* ***********************************************
Author :111qqz
Created Time :2016年03月28日 星期一 21时12分05秒
File Name :code/hdu/5652.cpp
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
const int N=501;
char maze[N][N];
int n,m;
int q;
bool vis[N][N];

struct node
{
    int x,y;

    bool ok ()
    {
	if (x>=0&&x<n&&y>=0&&y<m&&!vis[x][y]) return true;
	return false;
    }
}shan[250005];


int check( int id)
{
    
    for ( int i = 0 ; i < n ; i++)
    {
	for ( int j = 0 ; j < m ; j ++)
	{
	    if (maze[i][j]=='1') vis[i][j] = true;
		else vis[i][j] = false;
	}
    }

    for ( int i = 1 ; i <= id ; i++)
    {
	int x = shan[i].x;
	int y = shan[i].y;
	vis[x][y] = true;
    }

    queue<node>q;
    for ( int j = 0 ; j  < m ; j++)
    {
	
	if (!vis[0][j])
	{
	    node tmp;
	    tmp.x = 0;
	    tmp.y = j;
	    q.push(tmp);
	}
    }

    while (!q.empty())
    {
	node pre = q.front();q.pop();
	if (pre.x==n-1) return 1;
	for ( int i = 0 ; i < 4 ; i++)
	{
	    node nxt;
	    nxt.x = pre.x + dx4[i];
	    nxt.y = pre.y + dy4[i];
	    if (nxt.ok())
	    {
		vis[nxt.x][nxt.y] = true;
		q.push(nxt);
		
	    }
	}
    }
    return 0;
}

int bin()
{
    int l = 1 ;
    int r = q ;
    int mid;
    while (l<=r)
    {
	mid = (l+r)/2;
	if (check(mid))
	    l = mid + 1;
	else r = mid -1;
    }
    if (l>q) return -1;
    return l;
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
	    scanf("%d%d",&n,&m);
	    for ( int i = 0 ; i  < n;  i++) scanf("%s",maze[i]);
	    scanf("%d",&q);
	    for ( int i = 1 ; i <= q ; i ++) scanf("%d %d",&shan[i].x,&shan[i].y);
	    int ans = bin();
	    printf("%d\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
