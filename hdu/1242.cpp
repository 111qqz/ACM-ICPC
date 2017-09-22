/*************************************************************************
	> File Name: code/hdu/1242.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月02日 星期五 14时38分17秒
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
#include<cctype>
using namespace std;
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
#define lr dying111qqz
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=2E2+5;
char maze[N][N];
int m,n;
int ans;
bool vis[N][N];
struct node
{
    int x,y;
    int d;

    bool ok ()
    {
	if (x>=0&&x<n&&y>=0&&y<m&&!vis[x][y]&&maze[x][y]!='#') return true;
	return false;
    }
    bool hasguard()
    {
	if (maze[x][y]=='x') return true;
	return false;
    }
    bool goal()
    {
	if (maze[x][y]=='r') return true;
	return false;
    }
}s;

bool operator<(const node &a,const node &b)    //重载优先级的<关系...返回true时优先级更小，在队列的更后面．
{
    return a.d>b.d;
}

bool bfs()
{
    priority_queue<node>q;
    q.push(s);
    
    while (!q.empty())
    {
	node pre = q.top();
	q.pop();
//	cout<<pre.x<<" "<<pre.y<<" "<<pre.d<<endl;
	if (pre.goal())
	{
	    ans = pre.d;
	    return true;
	}

	for ( int i = 0 ; i < 4 ; i++)
	{
	    node next;
	    next.x = pre.x + dx4[i];
	    next.y = pre.y + dy4[i];
	    next.d = pre.d + 1;
	    if (!next.ok()) continue;
	    vis[next.x][next.y] = true;
	    if (next.hasguard()) next.d++;
	    q.push(next);
	    

	}
    }
    return false;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
    while(scanf("%d %d",&n,&m)!=EOF){
	ms(vis,false);
    for ( int i = 0 ; i < n ; i++) scanf("%s",maze[i]);
    for ( int i = 0 ; i < n ; i++)
    {
	for ( int j = 0 ; j < m ; j++)
	{
	    if (maze[i][j]=='a')
	    {
		s.x = i ;
		s.y = j ;
		s.d = 0 ;
		vis[i][j] = true;
		break;
	    }
	}
    }

    if (bfs())
    {
	printf("%d\n",ans);
    }
    else
    {
	puts("Poor ANGEL has to stay in the prison all his life.");
    }
}
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
