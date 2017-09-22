/* ***********************************************
Author :111qqz
Created Time :2016年03月27日 星期日 20时11分02秒
File Name :code/bc/#77/1003.cpp
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
int f[N*N];
int n,m;
int q;
int p[N][N];
int china;
int india;
struct node
{
    int x,y;
    int id;

}shan[N*N],kong[N*N];

int root ( int x)
{
    if (x!=f[x]) f[x] = root (f[x]);
    return f[x];
}

void merge( int x,int y)
{
    int rx = root (x);
    int ry = root (y);
//    cout<<"rx::"<<rx<<"   ry::"<<ry<<endl;
    if (rx!=ry)
    {
//	f[rx] = ry ;
	f[ry] = rx;
    }
}

void addegg( int x,int y)
{
    if (x-1>=0&&maze[x-1][y]=='0') merge(p[x][y],p[x-1][y]);
    if (x+1<n&&maze[x+1][y]=='0') merge(p[x][y],p[x+1][y]);
    if (y-1>=0&&maze[x][y-1]=='0') merge(p[x][y],p[x][y-1]);
    if (y+1<m&&maze[x][y+1]=='0') merge(p[x][y],p[x][y+1]);
    if (x==0) merge(p[x][y],china);
    if (x==n-1) merge(p[x][y],india);
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
	    scanf("%d %d",&n,&m);
	    for ( int i = 0 ; i < n ; i++) scanf("%s",maze[i]);

	    scanf("%d",&q);
	    for ( int i = 1 ; i <= q ; i++)
	    {
		int x,y;
		scanf("%d %d",&x,&y);
		shan[i].x = x;
		shan[i].y = y;
		shan[i].id = i;
//		maze[x][y] = '1';  //先统计空位。
	    }

	    int cnt = 0 ;
	    ms(p,-1);
	    for ( int i = 0 ; i  < n ; i++)
	    {
		for ( int j = 0 ; j < m;  j++)
		{
		    if (maze[i][j]=='0')
		    {
			cnt++;
			kong[cnt].x = i ;
			kong[cnt].y = j;
			kong[cnt].id = i;
			p[i][j] = cnt;
		    }
		}
	    }

	    for ( int i  = 1 ; i <= q ; i ++)
	    {
		int x = shan[i].x;
		int y = shan[i].y;
		maze[x][y]='1';
	    }
	    //check kong...ok!
	    //for ( int i = 1 ; i  <= cnt ; i++) cout<<"kong:"<<kong[i].x<<" "<<kong[i].y<<endl;

	        china = n*m+1;
	        india = n*m+2;
	    for ( int i = 0 ; i <= n*m+2 ; i++) f[i] =  i;
	//    f[china] = china;
	  //  f[india] = india;
	 //   cout<<"china:"<<china<<endl;
	   // cout<<"india:"<<india<<endl;
	    for ( int j = 0 ; j  < m ; j++)
	    {
		if (maze[0][j]=='0')
		{   
		    merge(china,p[0][j]);
	//	    cout<<"p[0][j]:"<<p[0][j]<<endl;
		}
		if (maze[n-1][j]=='0')
		{
		    merge(india,p[n-1][j]);
		}
	    }

	    for ( int i = 0 ;i < n ; i++)
	    {
		for ( int j = 0 ; j < m ; j ++)
		{
		    if (maze[i][j]=='1') continue;
		    if (maze[i-1][j]=='0') merge(p[i-1][j],p[i][j]);
		    if (maze[i][j-1]=='0') merge(p[i][j-1],p[i][j]);
		  // below nesscery or not?  
	//	    if (maze[i+1][j]=='0') merge(p[i+1][j],p[i][j]);
	//	    if (maze[i][j+1]=='0') merge(p[i][j+1],p[i][j]);
		}
	    }

//	    int rc = root (china);
//	    int ri = root (india);
	    //cout<<"rc:"<<rc<<" "<<"ri:"<<ri<<endl;
	    if (root(china)==root(india))
	    {
		puts("-1");
		continue;
	    }

	    for ( int i = q ; i >= 1 ; i--)
	    {
		int x = shan[i].x;
		int y = shan[i].y;

		maze[x][y] = '0';
		addegg(x,y);
		if (root(china)==root(india))
		{
		    printf("%d\n",i);
		    break;
		}
	    } 
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
