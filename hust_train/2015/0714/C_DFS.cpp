/*************************************************************************
	> File Name: code/2015summer/0714/C_DFS.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月15日 星期三 08时59分30秒
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
char ch[N][N];
int n,m,sx,sy,ans;
int dirx[4]={0,1,0,-1};
int diry[4]={1,0,-1,0};
bool vis[N][N];

bool ok(int xx,int yy)
{
    if (xx>=0&&xx<n&&yy>=0&&yy<m&&ch[xx][yy]=='.'&&vis[xx][yy]==false)
	  return true;
    return false;
}
void dfs(int x,int y)
{
    for ( int i = 0 ;  i < 4  ; i++ )
    {
	  int newx=x+dirx[i];
	  int newy=y+diry[i];
	  if (ok(newx,newy))
	  {
		ans++;
		vis[newx][newy]=true;
		dfs(newx,newy);
	  }
    }
}
int main()
 {
    while (scanf("%d %d",&m,&n)!=EOF&&n&&m)
      {
	  memset(vis,false,sizeof(vis));
	  ans = 0;
	  getchar();
	  for ( int i = 0 ; i < n ; i++ )
		for ( int  j = 0 ; j < m ; j++ )
 		{
		    scanf("%c",&ch[i][j]);
		    if (ch[i][j]=='@')
		    {
			  sx = i;
			  sy = j;
		    }
		    getchar();
		    
		}
	  dfs(sx,sy);
	  cout<<ans<<endl;
    }
	return 0;
}
