#include<cstdio>
#include<cstring>
#include<queue>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long LL;
const int N=1e3+5;
const int INF=0x3f3f3f3f;
struct E
{
    int u,to,w,next;
    bool operator<(const E &rhs)const
    {
        return w>rhs.w;
    }
} edge[100*N];
int head[N],tot,n,m,dis[N];
void add(int u,int v,int w)
{
    edge[tot].u=u;
    edge[tot].to=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot++;
}
priority_queue<E>Q;
vector<int>g[N];
bool v[N];
bool dij(int s,int t)
{
    for(int i=1; i<=n; ++i)dis[i]=INF,v[i]=0;
    dis[s]=0,Q.push(E {0,s,0,0});
    while(!Q.empty())
    {
        while(!Q.empty()&&v[Q.top().to])Q.pop();
        if(Q.empty())break;
        int u=Q.top().to;
        Q.pop();
        v[u]=1;
        for(int i=head[u]; ~i; i=edge[i].next)
        {
            int to=edge[i].to;
            if(dis[to]==dis[u]+edge[i].w)
                g[to].push_back(i);
            else if(!v[to]&&dis[to]>dis[u]+edge[i].w)
            {
                g[to].clear(),g[to].push_back(i);
                dis[to]=dis[u]+edge[i].w;
                Q.push(E {0,to,dis[to],0});
            }
        }
    }
    return dis[t]==INF?false:true;
}
struct Edge
{
    int from,to,cap,flow;
    Edge(int u,int v,int c,int d):from(u),to(v),cap(c),flow(d) {}
};
struct dinic
{
    int s,t;
    vector<Edge>edges;
    vector<int>G[N];
    int d[N];
    int cur[N];
    bool vis[N];
    void init()
    {
        edges.clear();
        for(int i=0; i<N; ++i)
            G[i].clear();
    }
    bool bfs()
    {
        memset(vis,0,sizeof(vis));
        queue<int>q;
        q.push(s);
        d[s]=0;
        vis[s]=1;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(int i=0; i<G[x].size(); i++)
            {
                Edge &e= edges[G[x][i]];
                if(!vis[e.to]&&e.cap>e.flow)
                {
                    vis[e.to]=1;
                    d[e.to]=d[x]+1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    int dfs(int x,int a)
    {
        if(x==t||a==0)return a;
        int flow=0,f;
        for(int &i=cur[x]; i<G[x].size(); i++)
        {
            Edge &e=edges[G[x][i]];
            if(d[x]+1==d[e.to]&&(f=dfs(e.to,min(a,e.cap-e.flow))))
            {
                e.flow+=f;
                edges[G[x][i]^1].flow-=f;
                flow+=f;
                a-=f;
                if(a==0)break;
            }
        }
        return flow;
    }
    int maxflow(int s,int t)
    {
        this->s=s;
        this->t=t;
        int flow=0;
        while(bfs())
        {
            memset(cur,0,sizeof(cur));
            flow+=dfs(s,INF);
        }
        return flow;
    }
    void addedge(int u,int v,int c)
    {
        Edge x(u,v,c,0),y(v,u,0,0);
        edges.push_back(x);
        edges.push_back(y);
        int l=edges.size();
        G[u].push_back(l-2);
        G[v].push_back(l-1);
    }
} solve;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(head,-1,sizeof(head));
        for(int i=1; i<=n; ++i)g[i].clear();
        tot=0;
        for(int i=1; i<=m; ++i)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            if(u==v)continue;
            add(u,v,w);
        }
        int s,t;
        scanf("%d%d",&s,&t);
        if(!dij(s,t))
        {
            printf("0\n");
            continue;
        }
        solve.init();
        for(int i=1; i<=n; ++i)
        {
            for(int j=0; j<g[i].size(); ++j)
            {
                int k=g[i][j];
                int u=edge[k].u,v=edge[k].to;
                solve.addedge(u,v,1);
            }
        }
        printf("%d\n",solve.maxflow(s,t));
    }
    return 0;
}
