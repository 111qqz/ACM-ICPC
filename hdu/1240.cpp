/*************************************************************************
	> File Name: code/hdu/1240.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月05日 星期一 18时44分48秒
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
                 
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const int dx6[6]={1,0,0,-1,0,0};
const int dy6[6]={0,-1,1,0,0,0};
const int dz6[6]={0,0,0,0,-1,1};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=11;
char sta[30],en[30];
char maze[N][N][N];
bool vis[N][N][N];
int n ;
struct node
{
    int x,y,z;
    int d;

    bool ok()
    {
	if (x>=0&&y>=0&&z>=0&&x<n&&y<n&&z<n&&!vis[z][x][y]&&maze[z][x][y]!='X')
	    return true;
	return false;
    }
    

}s,tar;

int ans;
bool bfs()
{
    vis[s.z][s.x][s.y] = true;
    s.d = 0 ;
    queue<node>q;
    q.push(s);
    while (!q.empty())
    {
	node pre=q.front();q.pop();
//	cout<<"x:"<<pre.x<<" y:"<<pre.y<<" z:"<<pre.z<<" d:"<<pre.d<<endl;

	if (pre.x==tar.x&&pre.y==tar.y&&pre.z==tar.z)
	{
	    ans = pre.d;
	    return true;
	}

	for ( int i = 0 ; i < 6 ; i++)
	{
	    node next;
	    next.x = pre.x + dx6[i];
	    next.y = pre.y + dy6[i];
	    next.z = pre.z + dz6[i];
	    next.d = pre.d + 1;
	    if (next.ok())
	    {
		vis[next.z][next.x][next.y] = true;
		q.push(next);
	    }

	}
    }
    
    return false;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
   while(scanf("%s",sta)!=EOF)
   {
       ms(vis,false);
       scanf("%d",&n);
       for ( int k = 0 ; k < n ; k++)
	   for ( int  i = 0 ; i < n ; i++)
		scanf("%s",maze[k][i]);
       scanf("%d %d %d",&s.x,&s.y,&s.z);
       scanf("%d %d %d",&tar.x,&tar.y,&tar.z);
       scanf("%s",en);
       if (bfs())
       {
	   printf("%d %d\n",n,ans);
       }
       else
       {
	   puts("NO ROUTE");
       }
     
   }
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
