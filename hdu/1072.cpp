/*************************************************************************
    > File Name: code/hdu/1072.cpp
    > Author: 111qqz
    > Email: rkz2013@126.com 
    > Created Time: 2015年10月03日 星期六 23时23分40秒
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
const int N=10;
int a[N][N];
bool vis[N][N][N];
int n,m;
struct node{
    int x,y;
    int t;
    int d;
    bool ok()
    {
    if (x>=0&&y>=0&&x<n&&y<m&&!vis[x][y][t]&&a[x][y]>0&&t>0) return true;
    return false;
    }

    bool escape()
    {
    if (a[x][y]==3)
    return true;
    return false;
    }
    bool rbomb()
    {
    if (a[x][y]==4) return true;
    return false;
    }
    void mark()
    {
    vis[x][y][t] = true;
    }
}s;

bool bfs()
{
    queue<node>q;
    q.push(s);
    int step = 0;
    while (!q.empty()&&step<n*m*n*m)
    {
	step++;
    node pre = q.front();q.pop();
//    cout<<"x:"<<pre.x<<" y:"<<" a[x][y]:"<<a[pre.x][pre.y]<<" t:"<<pre.t<<" d:"<<pre.d<<endl;
    if (pre.escape())
    {
        printf("%d\n",pre.d);
        return true;
    }
    
    for ( int  i = 0 ; i < 4 ; i++)
    {
        node next;
        next.x = pre.x + dx4[i];
        next.y = pre.y + dy4[i];
        next.d = pre.d + 1;
        next.t = pre.t - 1;
        if (!next.ok()) continue;
        if (next.rbomb())
        {
        next.t = 6;
        }
        next.mark();
        q.push(next);


    }
    }
    return false;

}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   int T;
   scanf("%d",&T);
   while (T--)
    {
    ms(vis,false);
    scanf("%d %d",&n,&m);
    for ( int i = 0  ; i < n;  i++)
        for ( int j = 0 ; j < m ; j++)
        {
        scanf("%d",&a[i][j]);
        if (a[i][j]==2)
        {
            s.x = i;
            s.y = j;
            s.d = 0;
            s.t = 6;
            vis[s.x][s.y][s.t] = true;
        }
        }
    if(!bfs())
    {
        puts("-1");
    }
        
    }
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
