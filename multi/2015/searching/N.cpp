/*************************************************************************
	> File Name: code/2015summer/searching/N.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月25日 星期六 13时54分49秒
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
const int N= 2E2+5;
char st[N][N];
int n,m;
int d[N][N];
int dd[N][N];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
struct node
{
    int x,y;
}kfc[N];
node M,Y;
void bfs(int xo,int yo)
{
    memset(d,-1,sizeof(d));
    queue<int>x;
    queue<int>y;
    x.push(xo);
    y.push(yo);
    d[xo][yo]=0;
    while (!x.empty())
    {
	   int px=x.front();x.pop();
	   int py=y.front();y.pop();
	   for ( int i = 0 ; i < 4 ; i++ )
	   {
		 int nx = px+dx[i];
		 int ny = py+dy[i];
		 if (nx>=0&&nx<n&&ny>=0&&ny<m&&d[nx][ny]==-1&&st[nx][ny]!='#')
		 {
	 	     d[nx][ny]=d[px][py]+1;
		     x.push(nx);
		     y.push(ny);
		 }
	   }

    }
  //  cout<<"res1:"<<res<<endl;
}
void bfs2(int xo,int yo)
{
    memset(dd,-1,sizeof(dd));
    queue<int>x;
    queue<int>y;
    x.push(xo);
    y.push(yo);
    dd[xo][yo]=0;
    while (!x.empty())
    {
	  int px = x.front();x.pop();
	  int py =y.front();y.pop();
	  for ( int i = 0 ;  i <4 ; i++ )
	  {
		int nx = px +dx[i];
		int ny = py +dy[i];
		if (nx>=0&&nx<n&&ny>=0&&ny<m&&dd[nx][ny]==-1&&st[nx][ny]!='#')
		{
		    dd[nx][ny]= dd[px][py]+1;
		    x.push(nx);
		    y.push(ny);
		}
	  }
    }

}




int main()
{
    while (scanf("%d %d",&n,&m)!=EOF)
    {
	  for ( int i = 0 ; i < n ; i++ )
	  {
		cin>>st[i];
	  }
	  int k = 0;
	  for ( int i = 0 ;  i < n ; i++)
	  {
		for ( int j = 0 ; j < m ; j++ )
		{
		    if (st[i][j]=='Y')
		    {
			  Y.x=i;
	 		  Y.y=j;
		    }
		    if (st[i][j]=='M')
		    {
	 		  M.x=i;
			  M.y=j;
	 	    }
		}
	  }
	  bfs(Y.x,Y.y);
	  bfs2(M.x,M.y);
	  int ans = 99999999;
	  for ( int i =  0 ; i < n ; i++ )
	  {
		for ( int j = 0 ;  j < m ; j++ )
		{
		    if (st[i][j]=='@')
		    {
			 // cout<<d[i][j]<<"  "<<dd[i][j]<<endl;
			  if (d[i][j]==-1||dd[i][j]==-1) continue;
			  ans = min(ans,d[i][j]+dd[i][j]);
		    }
		}
	  }
	  
	  cout<<ans*11<<endl;
    }
  
	return 0;
}
