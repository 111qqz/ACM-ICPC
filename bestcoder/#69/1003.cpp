/* ***********************************************
Author :111qqz
Created Time :2016年01月23日 星期六 19时46分33秒
File Name :code/bc/#69/1003.cpp
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
const double eps = 1E-10;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int ddx4[4]={2,0,0,-2};
const int ddy4[4]={0,-2,2,0};
const int inf = 0x3f3f3f3f;
const int N=200;
char maze[N][N];
bool vis[N][N];
int n,m;
LL sum;
long double cur;

bool hasfound;


int dblcmp( long double d)
{
    return d<-eps?-1:d>eps;
}


bool ok ( int x,int y)
{
    if (x>=0&&x<n&&y>=0&&y<m) return true;
    return false;
}

void dfs( int x,int y,double cur)
{
  //  cout<<"x:"<<x<<" y:"<<y<<" cur:"<<cur<<endl;
    if (fabs(cur-sum)<eps)
    {
	hasfound = true;
	return ;
    }
    if (hasfound) return ;
    if (vis[x][y]) return;
    vis[x][y] = true;

    double ncur = cur;
    
    for ( int i = 0 ; i < 4 ; i++)
    {
	int nnx = x +ddx4[i];
	int nny = y +ddy4[i];
	int nx = x + dx4[i];
	int ny = y + dy4[i];
	if (!ok(nnx,nny)) continue;
	LL val = LL (maze[nnx][nny]-'0');
	if (val==0LL&&maze[nx][ny]=='/') continue;
	if (maze[nx][ny]=='+')
	{
	    ncur = ncur + val;
	}
	if (maze[nx][ny]=='-')
	{
	    ncur = ncur - val;
	}
	if (maze[nx][ny]=='*')
	{
	    ncur = ncur * val;
	}
	if (maze[nx][ny]=='/')
	{
	    ncur = ncur*1.0/val;
	}
	dfs(nnx,nny,ncur);

    }
    vis[x][y]=false;


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
	    hasfound = false;
	    cin>>n>>m>>sum;
	    for ( int i = 0  ; i < n ;i++) scanf("%s",maze[i]);

	    for ( int i = 0 ; i < n ; i=i+2)//只搜数字
	    {
		if (hasfound) break;
		 for ( int j = 0  ; j < m ; j=j+2)
		 {
		  //  cout<<maze[i][j]<<endl;
		     ms(vis,false); //顺序不一样值可能不一样，所以每次都清空
		     dfs(i,j,(maze[i][j]-'0')*1.0);
		     if (hasfound) break;
		 }
		 
	    }
	    if (hasfound)
	    {
		puts("Possible");
	    }
	    else
	    {
		puts("Impossible");
	    }

	    
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
