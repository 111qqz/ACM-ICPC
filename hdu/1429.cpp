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
const int N=101;
int n,m,t;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int vis[N][N][1025];
int ans;
char maze[N][N];
struct node
{
    int x,y;
    int key;
    int time;
    bool ok()
    {
    if (x>=0&&x<n&&y>=0&&y<m&&maze[x][y]!='0')
        return true;
    return false;
    }
}s;

void bfs()
{
    
    queue<node>Q;
    Q.push(s);
    while (!Q.empty())
    {
    node pre;
        pre = Q.front();Q.pop();
    if (maze[pre.x][pre.y]=='3')
    {
        ans = pre.time;
        return;
    }
    for ( int i = 0 ; i < 4 ; i++)
    {
        node next;
        next.x = pre.x + dx[i];
        next.y = pre.y + dy[i];
        next.time = pre.time + 1;
        next.key = pre.key;
        if (!next.ok()) continue;
        if (maze[next.x][next.y]>='a'&&maze[next.x][next.y]<='j')
        {
        int nkey = 1<<(maze[next.x][next.y]-'a'); //计算当前钥匙在钥匙串中的位置
        next.key = (next.key | nkey);          //将当前钥匙添加到钥匙串(状态压缩重点!)
        if (!vis[next.x][next.y][next.key])
        {
            vis[next.x][next.y][next.key]=true;
            Q.push(next);
        }

        }
        else
        if (maze[next.x][next.y]>='A'&&maze[next.x][next.y]<='J')
        {
        int needkey = (maze[next.x][next.y]-'A');// 计算当前门所需要的钥匙在钥匙串中的位置
        if (((next.key>>needkey)&1)&&!vis[next.x][next.y][next.key]) //next.key>>needkey 取出所需钥匙的状态 (状态压缩重点!)
        {
            vis[next.x][next.y][next.key] = true;
            Q.push(next); 
        }
        }
        else
        {
        if (!vis[next.x][next.y][next.key])
        {
            vis[next.x][next.y][next.key] = true;
            Q.push(next);
        }
        }

    }

    }

}
int main()
{
    freopen("./in.txt","r",stdin) ;
    while (scanf("%d %d",&n,&m)!=EOF)
    {
    memset(vis,false,sizeof(vis));
    for ( int i = 0 ; i < n ; i++ )
    {
        scanf("%s",maze[i]);
    }
    string kong;
    //    cin>>kong;
    for ( int i = 0 ; i < n ; i++ )
    {
        for ( int j = 0 ; j < m ; j ++ )
        {
        if (maze[i][j]=='2')
        {
            s.x = i;
            s.y = j;
        }
        }
    }
    s.key = 0;
    s.time  =0;
    vis[s.x][s.y][s.key]=true;
    ans = inf/2; //走不出可能是时间不够,也可能是时间够也走不出去(本身迷宫没有通路),因为忽略后一种情况wa了几次==
    bfs();
        cout<<ans<<endl;
    }
    return 0;
}
