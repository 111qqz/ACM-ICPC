/* ***********************************************
Author :111qqz
Created Time :2016年07月12日 星期二 13时29分49秒
File Name :code/hdu/2196.cpp
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
const int N=1E4+7;
int n,m;
vector < pi >edge[N];
int d[N];
int ans[N];
bool vis[N];
int beg,lst;
int far;
void bfs( int s)
{
    ms(d,0x3f);
    ms(vis,false);
    queue<int>q;
    q.push(s);
    vis[s] = true;
    d[s] = 0 ;

    while (!q.empty())
    {
    int u = q.front(); q.pop();

    int siz = edge[u].size();

    for ( int i = 0 ; i < siz;  i++)
    {
        int v = edge[u][i].fst;
        if (vis[v]) continue;
        vis[v] = true;
        d[v] = d[u] + edge[u][i].sec;
        q.push(v);
    }
    }


}
int main()
{
    #ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
  #endif

    while (~scanf("%d",&n))
    {
        ms(ans,0);
        for ( int i = 1 ; i <= n ; i++) edge[i].clear();
        for ( int i = 2 ; i <= n ; i++)
        {
        int u,v,w;
        u = i;
        scanf("%d %d",&v,&w);
        edge[v].push_back(make_pair(u,w));
        edge[u].push_back(make_pair(v,w));
        }

        bfs(1);
        int mx = 0;
        for ( int i = 1 ; i <= n ; i++)
        {
        if (d[i] > mx)
        {
            mx = d[i];
            lst = i ;
        }
        }
     //   cout<<"lst:"<<lst<<endl;

        far = 0 ;
        bfs(lst);
        for ( int i = 1 ; i <= n ; i++)
        {
        if (d[i]>far)
        {
            far = d[i];
            beg = i ;
        }
        }

     //   cout<<"far:"<<far<<endl;
     //   cout<<"beg:"<<beg<<endl;
        bfs(beg);
        for ( int i = 1 ; i <= n ; i++)
        ans[i] = max(ans[i],d[i]);
        bfs(lst);
        for ( int i = 1 ; i <= n ;i++)
        ans[i] = max(ans[i],d[i]);

        for ( int i = 1 ; i <= n ; i++)
        cout<<ans[i]<<endl;
    
        
        
    }

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
