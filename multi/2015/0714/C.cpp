/*************************************************************************
	> File Name: code/2015summer/0714/C.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月14日 星期二 16时11分23秒
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
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int N=50;
char mymap[N][N];
int sx,sy,n,m;
int ans;
int dirx[4]{0,1,0,-1};
int diry[4]={1,0,-1,0};
int d[N][N];
bool ok(int tx,int ty)
{
    if (tx>=0&&tx<n&&ty>=0&&ty<m&&mymap[tx][ty]=='.'&&d[tx][ty]==-1)
	  return true;
    return false;
}
void bfs()
{
    memset(d,-1,sizeof(d));
    queue<int>x;
    queue<int>y;
    x.push(sx);
    y.push(sy);
    d[sx][sy]=0;
    while (!x.empty()&&!y.empty())
    {
	  int xx=x.front();
	  int yy=y.front();
	  x.pop();
	  y.pop();
	  for ( int i = 0 ; i < 4 ; i++ )
	  {
		int tmpx=xx+dirx[i];
		int tmpy=yy+diry[i];
		if (ok(tmpx,tmpy))
		{
		    d[tmpx][tmpy]=d[xx][yy]+1;
		    if (d[tmpx][tmpy]>ans) ans = d[tmpx][tmpy];
		    x.push(tmpx);
		    y.push(tmpy);
		}

	  }

    }
}
int main()
{
 //   while (scanf("%d %d",&m,&n)!=EOF&&n&&m)
    {
	  scanf("%d%d",&m,&n);
	  ans =  -1;
	  getchar();
	  for ( int i = 0 ; i <n ; i++)
	  {
		for ( int j = 0 ; j < m ;j++)
		{
		    scanf("%c",&mymap[i][j]);
		    if (mymap[i][j]=='@')
		    {
			  sx = i;
			  sy = j;
		    }
		}
		getchar();
	  }
	 cout<<ans<<endl; 
    }
	return 0;
}
