/*************************************************************************
	> File Name: code/2015summer/searching/L.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月25日 星期六 15时29分28秒
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

const int N = 1E2+5;
char st[N][N];
int m,n;
bool v[N][N];
int dx[8]={0,0,1,1,1,-1,-1,-1};
int dy[8]={1,-1,0,-1,1,0,-1,1};
void dfs(int x,int y)
{
    v[x][y]=true;
    for ( int i = 0 ;  i < 8 ; i++ )
    {
	  int newx=x+dx[i];
	  int newy=y+dy[i];
	  if (newx>=0&&newx<m&&newy>=0&&newy<n&&!v[newx][newy]&&st[newx][newy]=='@')
	  {
		dfs(newx,newy);
	  }
    }
}

int main()
{
    while (scanf("%d %d",&m,&n))
    {
	  if (m==0) break;
	  int ans = 0;
	  memset(v,false,sizeof(v));
	  for (int i = 0 ; i < m ; i++ )
		scanf("%s",st[i]);
	  for ( int i = 0 ;  i  < m ; i++ )
	  {
		for ( int  j = 0 ; j < n ; j++)
		{
		    if (st[i][j]=='@'&&!v[i][j])
		    {
			  ans++;
			  dfs(i,j);
		    }
		}
	  }
    queue<int>q;
    stack<int>s;
    
	  cout<<ans<<endl;
    }
	return 0;
}
