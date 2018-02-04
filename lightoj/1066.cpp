/*************************************************************************
	> File Name: code/loj/1066.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月11日 星期二 18时30分39秒
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
const int N=13;
int sx,sy;
int n;
char maze[N][N];
int d[N][N];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int ans;
int seek[N][N];
int cnt;
bool v[N][N];
int bfs(int xx,int yy,char ch)
{
    memset(d,-1,sizeof(-1)); 
    queue<int>x;
    queue<int>y;
    x.push(xx);
    y.push(yy);
    d[xx][yy] = 0;
    maze[xx][yy]='.';
    while (!x.empty())
    {
	int px = x.front();x.pop();
	int py = y.front();y.pop();
//	cout<<"px:"<<px<<" py:"<<py<<endl;
	if (maze[px][py]==ch)
	{
	    sx = px;
	    sy = py;
	    return d[px][py];
	}
	for ( int i = 0 ; i< 4 ; i++ )
	{
	    int nx = px + dx[i];
	    int ny = py + dy[i];
	    if (nx>=0&&nx<n&&ny>=0&&ny<n&&d[nx][ny]==-1&&(maze[nx][ny]=='.'||maze[nx][ny]==ch))
	    {
		d[nx][ny] =  d[px][py] + 1;
		x.push(nx);
		y.push(ny);
	    }
	}
    }
    return -1;
}
int main()
{
    int T;
    cin>>T;
    int cas = 0 ;
    while ( T-- )
    {
	cas++;
	ans = 0;
	scanf("%d",&n);
	for ( int i = 0 ; i  < n ; i++ )
	{
	    scanf("%s",maze[i]);
	}
	 cnt = 0 ;// 统计食物的数量
	for ( int i = 0 ; i < n ; i++ )
	{
	    for ( int j = 0 ; j < n ; j ++)
	    {
		if (maze[i][j]=='A')
		{
		    sx = i ;
		    sy = j;
		}
		if (maze[i][j]!='#'&&maze[i][j]!='.')
		{
		    cnt++;
		}
	    }
	}
	memset(d,-1,sizeof(d));
	d[sx][sy]  = 0;
	bool flag = false;
	for ( int i = 0 ; i < cnt ; i++ )
	{
	    int tmp = bfs(sx,sy,char(i+'A'));
	 //  cout<<"tmp:"<<tmp<<endl;
	    if (tmp==-1)
	    {
		flag = true;
		break;
	    }
	    ans += tmp;
//	    cout<<"tmp:"<<tmp<<" ans:"<<ans<<endl;
	}
//	for ( int i = 0 ; i < n ; i++ )
//	{
//	    for ( int j = 0 ; j < n ; j++ )
//	    {
//		cout<<d[i][j]<<" ";
//	    }
//	    cout<<endl;
//	}
	if (flag)
	{
	    printf("Case %d: %d\n", cas, ans);
	}
	else
	{
		    printf("Case %d: Impossible\n", cas);
	}
    }
	return 0;
} 
