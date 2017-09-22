/* ***********************************************
Author :111qqz
Created Time :2015年12月04日 星期五 15时08分22秒
File Name :code/cf/edu1/D.cpp
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



using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=1E3+3;
int n,m,k;
char maze[N][N];
bool pic[N][N];
int v[N][N];
int ans[N*N];
int res;
int cnt = 0 ;

bool ok ( int x,int y)
{
    if (x>=0&&x<n&&y>=0&&y<m&&v[x][y]==-1)
	return true;
    return false;
}
int dfs ( int x,int y,int kk)
{
    if (!ok(x,y)) return 0;

    if (maze[x][y]=='*') return 1;
    v[x][y] = kk;

    return  dfs(x+1,y,kk)+dfs(x-1,y,kk)+dfs(x,y-1,kk)+dfs(x,y+1,kk);


}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
	 #endif

    scanf("%d%d%d",&n,&m,&k);
    for ( int i = 0  ; i < n ; i++) scanf("%s",maze[i]);
    
    ms(ans,-1);
    ms(v,-1);
    while (k--)
    {
	int x,y;
	scanf("%d %d",&x,&y);

	x--;
	y--;
	if (v[x][y]==-1)
	    ans[k] = dfs(x,y,k);
	else ans[k] = ans[v[x][y]];

	printf("%d\n",ans[k]);
	
    
	
    }


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
