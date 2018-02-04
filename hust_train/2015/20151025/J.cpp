/*************************************************************************
	> File Name: code/hust/20151025/J.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月25日 星期日 13时18分32秒
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
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
char maze[15][15];
bool v[15][15];
int w,h;

struct node
{
    int x,y;
    bool ok()
    {
	if (x>=0&&x<w&&y>=0&&y<h&&maze[x][y]!='*')
	    return true;
	return false;
    }
}s;

void bfs()
{
    queue<node>q;
    q.push(s);
    int ans = 1 ;
    int step = 0 ;
    ms(v,false);

    while (!q.empty()&&step<w*h*5)
    {
	step++;
	node pre=q.front();q.pop();
	
	char tmp = maze[pre.x][pre.y];
//	printf("x: %d y: %d tmp: %c \n",pre.x,pre.y,tmp);
//	cout<<"x:"<<pre.x<<" y:"<<pre.y<<" tmp:"<<tmp<<endl;

	if (maze[pre.x][pre.y]=='.'&&!v[pre.x][pre.y])
	{
	    ans++;
	    v[pre.x][pre.y] = true;
	}
	
	for ( int i = 0 ; i < 4 ; i++)
	{
	    node next;
	    next.x = pre.x + dx4[i];
	    next.y = pre.y + dy4[i];
	    if (next.ok())
	    {
		q.push(next);
		v[next.x][next.y] = true;
	    }
	}
    }
    printf("%d\n",ans);
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   scanf("%d %d",&w,&h);
   for ( int i = 0 ; i < w ; i++) scanf("%s",maze[i]);

   for ( int i = 0 ; i < w ; i++)
       for ( int j = 0 ; j < h ; j++)
	    {
	//	cout<<maze[i][j]<<endl;
		if (maze[i][j]=='U'||maze[i][j]=='D'||maze[i][j]=='R'||maze[i][j]=='L')
		{
		    s.x = i;
		    s.y = j;
	//	    v[i][j] = true;
		    
		}
	    }

   bfs();

  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
