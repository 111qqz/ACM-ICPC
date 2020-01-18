#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+1;
const int INF=1e9;
const LL MOD = 20010905;
struct node
{
    int b;
    int w;
    int next;
};
node edge[maxn];
int s;
int n,m;
int head[maxn];
int que[maxn];
int vis[maxn];
int dis[maxn];
int ip = 0;
LL cnt[maxn]={0LL};
void add(int u,int v,int c)
{
    edge[ip].b=v; edge[ip].w=c; edge[ip].next=head[u]; head[u]=ip++;
}
void spfa(int start,int numpoint)
{
    memset(vis,0,sizeof(vis));
    for(int i=0;i<=numpoint;i++)
         dis[i]=INF;
    int front=-1,tail=-1;
    dis[start]=0; vis[start]=1;  que[++tail]=start;
    cnt[start]=1;
    int top,to;
    int temp;
    while(front!=tail)
    {
        if(++front>numpoint) front-=numpoint;//循环队列
        top=que[front];  vis[top]=0;
        for(int p=head[top];p!=-1;p=edge[p].next)
        {
            to=edge[p].b; temp=dis[top]+edge[p].w;
            if (dis[to]==temp)
            { 
                cnt[to] = (cnt[to] + cnt[top])%MOD;
                puts("miaomi");
            }
            if(dis[to]>temp)
            {
                dis[to]=temp;
                cnt[to]=cnt[top];
            }
                if(cnt[to]&&!vis[to])
                {
                    if(++tail>numpoint) tail-=numpoint;
                    que[tail]=to;
                    vis[to]=1;
                }
            
        }
        // cnt[top] = 0;
    }
}
int main()
{
   
    scanf("%d%d",&n,&m);
        memset(head,-1,sizeof(head));//head数组初始化
        ip=0;
        for(int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            add(x,y,z);
        }
        spfa(1,n);
        // for ( int i = 1; i <= n ; i++) cout<<cnt[i]<<endl;
        // printf("%d\n",dis[n]);
        printf("%lld\n",cnt[n]);
    
    return 0;
}
