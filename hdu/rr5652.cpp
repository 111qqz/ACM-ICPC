/* ***********************************************
Author :111qqz
Created Time :2016年03月30日 星期三 13时27分41秒
File Name :code/hdu/rr5652.cpp
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
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=505;
char maze[N][N];
int n,m;
int q;
int l[N*N],r[N*N];
int p[N][N];
int des;
int sea;
int f[N*N];

int root ( int x)
{
    if (x!=f[x]) f[x] = root (f[x]);
    return f[x];
}

void merge(int x,int y)
{
    int rx = root (x);
    int ry = root (y);
    if (rx!=ry)
    {
	//f[rx] = ry;
	if (rand()&1) swap(rx,ry);
	f[ry] = rx;
    }
}

void go( int x,int y)
{
    if (x-1>=0&&maze[x-1][y]=='1') merge(p[x][y],p[x-1][y]);
    if (y-1>=0&&maze[x][y-1]=='1') merge(p[x][y],p[x][y-1]);
    if (x+1<n&&maze[x+1][n]=='1') merge(p[x][y],p[x+1][y]);
    if (y+1<m&&maze[x][y+1]=='1') merge(p[x][y],p[x][y+1]);
    if (y==0) merge(p[x][y],des);
    if (y==m-1) merge(p[x][y],sea);
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
	    ms(p,-1);
	    scanf("%d %d",&n,&m);
	    int cnt = 0 ;
	    for ( int i = 0 ; i < n ; i ++) scanf("%s",maze[i]);
	    for ( int i = 0 ; i < n ; i++)
	    {
		for ( int j =  0 ; j < m ; j++)
		{
		    if (maze[i][j]=='1')
		    {
			cnt++;
			p[i][j] = cnt;
		    }
		}
	    }
	    scanf("%d",&q);
	    for ( int i = 1 ; i <= q ; i++)
	    {
		scanf("%d %d",&l[i],&r[i]);
		cnt++;
		p[l[i]][r[i]] = cnt;
	    }
	    des = n*m+1;
	    sea = n*m+2;
	    for ( int i = 0 ; i <= n*m+2 ; i++) f[i] = i;
	    
	    for ( int i = 0 ; i < n ; i++)
	    {
		if (maze[i][0]=='1') merge(p[i][0],des);
		if (maze[i][m-1]=='1') merge(p[i][m-1],sea);
	    }

	    for ( int i = 0 ; i < n ; i++)
	    {
		for ( int j = 0 ; j < m ; j++)
		{
		    if (maze[i][j]=='0') continue;
		    go(i,j);
		}
	    }

	    int ans = -1;
	    for ( int i = 1 ; i <= q ; i++)
	    {
		int x = l[i];
		int y = r[i];
		go(x,y);
		maze[x][y]='1';
		int rd = root (des);
		int rs = root (sea);
//		cout<<"rd:"<<rd<<" rs:"<<rs<<endl;
		if (rd==rs)
		{
		    ans =  i;
		    break;
		}
	    }
	    cout<<ans<<endl;
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
