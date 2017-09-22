/*************************************************************************
	> File Name: code/2015summer/searching/I.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月27日 星期一 18时25分27秒
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
const int N=1E2+5;
const int inf = 0x7fffffff;
int x[N],y[N];
int cnt;
int m,n;
char maze[11][11];
int d[11][11];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int k;

bool ok (int x,int y)
{
    if (x>=0&&x<n&&y>=0&&y<m&&maze[x][y]=='#'&&d[x][y]==-1)
	  return true;
    return false;
}
int bfs(int x1,int y1,int x2,int y2)
{
    memset(d,-1,sizeof(d));
    queue<int>x;
    queue<int>y;
    x.push(x1);
    x.push(x2);
    y.push(y1);
    y.push(y2);
    d[x1][y1]=0;
    d[x2][y2]=0;
    cnt = 2;
    while (!x.empty()&&!y.empty())
    {
	  int px = x.front();x.pop();
	  int py = y.front();y.pop();
//	  cout<<"px:"<<px<<" py:"<<py<<endl;
	  int tx,ty;
	  for ( int i = 0 ; i < 4 ; i++ )
	  {
		   int  nx = px + dx[i];
		   int  ny = py + dy[i];
		if (ok(nx,ny))
		{
		    d[nx][ny]=d[px][py]+1;
		    x.push(nx);
		    y.push(ny);
		    cnt++;
		    tx = nx;
		    ty = ny;
		}
	  }
	  if (cnt>=k)
	  {
		return  d[tx][ty]; //最后一次烧到的点一定是最远的点
	  }

    }
    return inf;
}
int main()
{
    int T;
    cin>>T;
    int cas = 0;
    while (T--)
    {
	  cas++;
	  scanf("%d %d",&n,&m);
	  for ( int i = 0 ; i < n ; i++ )
	  {
		scanf("%s",maze[i]);
	  }
	   k = 0 ;
	  for ( int i = 0 ; i < n ; i++ )
	  {
		for ( int j = 0 ; j  < m ; j++ )
		{
		    if (maze[i][j]=='#')
		    {
			  k++;
			  x[k]=i;
			  y[k]=j;
		    }
		}
	  }
	  if (k<=2)
	  {

		printf("Case %d: %d\n",cas,0);
		continue;
	  }
	  int ans = inf;
	  for ( int i = 1 ; i <= k ;  i++ )
	  {
		for ( int j = i ; j <= k ; j++ )
		{
		    cnt = 0 ;
		    ans = min(ans,bfs(x[i],y[i],x[j],y[j]));
		}
	  }
	  if (ans!=inf) 
	  printf("Case %d: %d\n",cas,ans);
	  else printf("Case %d: %d\n",cas,-1);

    }
  
	return 0;
}
