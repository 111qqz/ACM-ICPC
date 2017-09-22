/*************************************************************************
	> File Name: code/poj/rr2688.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月16日 星期日 03时39分34秒
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
const int inf = 0x7fffffff;
const int N=25;
int w,h;
char maze[N][N];
int dist[N][N];
int cnt;//机器人与脏地的个数
int tag[N][N];//标记
bool vist[N][N];
struct node
{
    int x,y;
    int step;
    bool ok ()
    {
	if (x<1||x>h||y<1||y>w||vist[x][y]||maze[x][y]=='x')
	    return false;
	return true;
    }
}pos[N*N];

node robot;
int dir[4][2]={0,-1,0,1,-1,0,1,0};
void bfs(node p,int po)
{
    vist[p.x][p.y]=1;
    queue<node>q;
    q.push(p);
    while(!q.empty())
    {
        node cur=q.front();
        q.pop();
        if(maze[cur.x][cur.y]=='o' || maze[cur.x][cur.y]=='*')
            dist[po][tag[cur.x][cur.y]]=cur.step;
        node next;
        next.step=cur.step+1;
        for(int i=0;i<4;i++)
        {
            next.x=cur.x+dir[i][0];
            next.y=cur.y+dir[i][1];
            if(!next.ok())
                continue;
            q.push(next);
            vist[next.x][next.y]=1;
        }
    }
}

int ans=inf;
bool vis[N];
void dfs(int x,int step,int s)
{
    if(step==cnt)
    {
        if(s<ans)
            ans=s;
        return ;
    }
    if(s>ans)
        return ;
    for(int j=1;j<=cnt;j++)
    {
        if(vis[j])
            continue;
        vis[j]=1;
        dfs(j,step+1,s+dist[x][j]);
        vis[j]=0;
    }
}

int main()
{
    while(~scanf("%d%d",&w,&h))
    {
        if(w==0&&h==0)
            break;
       // getchar();
        cnt=0;
        memset(pos,0,sizeof(pos));
        memset(tag,0,sizeof(tag));
        for(int i=1;i<=h;i++)
        {
            scanf("%s",maze[i]+1);
            for(int j=1;j<=w;j++)
                if (maze[i][j]=='o')
                {
                     pos[++cnt].x=i;
                    pos[cnt].y=j;
                    robot.x=i;
                    robot.y=j;
                    tag[i][j]=cnt;
                }
                else if(maze[i][j]=='*')
                {
                     pos[++cnt].x=i;
                    pos[cnt].y=j;
                    tag[i][j]=cnt;
                }
        }
        for(int i=1;i<=cnt;i++)
            for(int j=1;j<=cnt;j++)
                if(i !=j)
                    dist[i][j]=inf;
                else
                    dist[i][j]=0;
        for(int i=1;i<=cnt;i++)
        {    
            memset(vist,0,sizeof(vist));
            pos[i].step=0;
            bfs(pos[i],i);
        }
        bool flag=1;
        for(int i=1;i<=cnt && flag;i++)
            for(int j=1;j<=cnt && flag;j++)
                if(dist[i][j]==inf)
                     flag=0;

        if(flag==0)
        {
            puts("-1");
            continue;
        }
        memset(vis,0,sizeof(vis));
        vis[tag[robot.x][robot.y]]=1;
        ans=inf;
        dfs(tag[robot.x][robot.y],1,0);
        printf("%d\n",ans);

    }
    return 0;
}
