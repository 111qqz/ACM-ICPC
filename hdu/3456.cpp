#include<cstdio>  
#include<cstring>  
#include<cmath>  
#include<cstdlib>  
#include<iostream>  
#include<algorithm>  
#include<vector>  
#include<map>  
#include<queue>  
#include<stack>  
#include<string>  
#include<map>  
#include<set>  
#include<ctime>  
#define eps 1e-6  
#define LL long long  
#define pii pair<int, int>  
//#pragma comment(linker, "/STACK:1024000000,1024000000")  
using namespace std;  
  
const int MAXN = 1100;  
const int MAXM = 100010;  
const int INF = 0x3f3f3f3f;  
int n, m;  
struct Edge1 {  
    int to,next;  
    int w;  
} edge1[MAXM*2], edge2[MAXM*2];  
int head1[MAXN],tot1, head2[MAXN], tot2;  
void init1() {  
    tot1 = tot2 = 0;  
    memset(head1, -1, sizeof(head1));  
    memset(head2, -1, sizeof(head2));  
}  
void addedge1(int u,int v,int w) {  
    edge1[tot1].to = v;  
    edge1[tot1].w = w;  
    edge1[tot1].next = head1[u];  
    head1[u] = tot1++;  
}  
void addedge2(int u,int v,int w) {  
    edge2[tot2].to = v;  
    edge2[tot2].w = w;  
    edge2[tot2].next = head2[u];  
    head2[u] = tot2++;  
}  
//spfa算法,vis1it数组记录x是否在队列中  
bool vis1[MAXN]; //在队列标志  
int cnt[MAXN]; //每个点的入队列次数  
int dist1[2][MAXN];  
bool spfa(int start, int n, int id, int *Head, Edge1 *Edge) {  
    memset(vis1, 0, sizeof(vis1));  
    for(int i = 1; i <= n; i++) dist1[id][i] = INF;  
    vis1[start] = 1;  
    dist1[id][start] = 0;  
    queue<int> q;  
    while(!q.empty()) q.pop();  
    q.push(start);  
    memset(cnt, 0, sizeof(cnt));  
    cnt[start] = 1;  
    while(!q.empty()) {  
        int u = q.front();  
        q.pop();  
        vis1[u] = false;  
        for(int i = Head[u]; i != -1; i = Edge[i].next) {  
            Edge1 e = Edge[i];  
            int v = e.to;  
            if(dist1[id][v] > dist1[id][u]+e.w) {  
                dist1[id][v] = dist1[id][u] + e.w;  
                if(!vis1[v]) {  
                    vis1[v] = true;  
                    q.push(v);  
                    if(++cnt[v]>n) return false;  
                }  
            }  
        }  
    }  
    return true;  
}  
  
//网络流  
//最大流  
//Dinic算法求最大流，一般效率很高  
//s源点，t汇点，g，e全局变量，表示存边的邻接表  
struct Edge  
{  
    int to, next, cap;  
} edge[MAXM*2];  
int s, t;  
int head[MAXN], tot;  
  
void addedge(int u, int v, int w)  
{  
    edge[tot].to = v;  
    edge[tot].cap = w;  
    edge[tot].next = head[u];  
    head[u] = tot++;  
    edge[tot].to = u;  
    edge[tot].cap = 0;  
    edge[tot].next = head[v];  
    head[v] = tot++;  
}  
  
void init()  
{  
    memset(head, -1, sizeof(head));  
    tot = 0;  
}  
  
queue<int> q;  
bool vis[MAXN];  
int dist[MAXN];  
void bfs()  
{  
    memset(dist, 0, sizeof(dist));  
    while(!q.empty()) q.pop();  
    vis[s] = 1;  
    q.push(s);  
    while(!q.empty())  
    {  
        int u = q.front();  
        q.pop();  
        for(int i = head[u]; i!=-1; i=edge[i].next)  
        {  
            if(!edge[i].cap || vis[edge[i].to]) continue;  
            q.push(edge[i].to);  
            vis[edge[i].to] = 1;  
            dist[edge[i].to] = dist[u] + 1;  
        }  
    }  
}  
  
int dfs(int u, int a)  
{  
    if(u==t) return a;  
    int ret = 0;  
    for(int i = head[u]; a&&i!=-1; i = edge[i].next)  
    {  
        if(edge[i].cap && dist[u]+1==dist[edge[i].to])  
        {  
            int tmp = dfs(edge[i].to, min(a, edge[i].cap));  
            edge[i].cap -= tmp;  
            edge[i^1].cap += tmp;  
            a -= tmp;  
            ret += tmp;  
        }  
    }  
    return ret;  
}  
  
int maxflow()  
{  
    int ret = 0;  
    while(true)  
    {  
        memset(vis, 0, sizeof(vis));  
        bfs();  
        if(!vis[t]) return ret;  
        ret += dfs(s, INF);  
    }  
}  
  
  
int main()  
{  
    //freopen("input.txt", "r", stdin);  
    int T;  
    cin >> T;  
    while(T--)  
    {  
        init1();  
        cin >> n >> m;  
        for(int i = 1; i <= m; i++)  
        {  
            int u, v, w;  
            scanf("%d%d%d", &u, &v, &w);  
            addedge1(u, v, w);  
            addedge2(v, u, w);  
        }  
        cin >> s >> t;  
        spfa(s, n, 0, head1, edge1);  
        spfa(t, n, 1, head2, edge2);  
        init();  
        for(int i = 1; i <= n; i++)  
        {  
            for(int e = head1[i]; e != -1; e = edge1[e].next)  
            {  
                if(dist1[0][i]+dist1[1][edge1[e].to]+edge1[e].w == dist1[0][t])  
                    addedge(i, edge1[e].to, 1);  
            }  
        }  
        int ans = maxflow();  
        cout << ans << endl;  
    }  
    return 0;  
}  
