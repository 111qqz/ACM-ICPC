#include<stdio.h>  
#include<string.h>  
#include<queue>  
using namespace std;
const int M=1E5+7;
const int N=210;
int head[N];  
struct EdgeNode  
{  
    int to;  
    int w;  
    int cost;  
    int next;  
}e[M];  
struct node  
{  
    int u,val;  
}now,nex;  
int dis[N][M];  
int vis[N][M];  
int k,n,m1,m2,cont;  
void add(int from,int to,int w,int cost)  
{  
    e[cont].to=to;  
    e[cont].w=w;  
    e[cont].cost=cost;  
    e[cont].next=head[from];  
    head[from]=cont++;  
}  
void SPFA(int ss)  
{  
    for(int i=1;i<=n;i++)  
    {  
        for(int j=0;j<=k;j++)  
        {  
            dis[i][j]=0x3f3f3f3f;  
            vis[i][j]=0;  
        }  
    }  
    now.u=ss;  
    now.val=k;  
    queue<node>s;  
    s.push(now);  
    dis[now.u][now.val]=0;  
    vis[now.u][now.val]=1;  
    while(!s.empty())  
    {  
        now=s.front();  
        s.pop();  
        vis[now.u][now.val]=0;  
        int u=now.u,val=now.val;  
        for(int k=head[u];k!=-1;k=e[k].next)  
        {  
            int v=e[k].to;  
            int cost=e[k].cost;  
            int w=e[k].w;  
            if(val-cost<0)continue;  
            if(dis[v][val-cost]>dis[u][val]+w)  
            {  
                dis[v][val-cost]=dis[u][val]+w;  
                if(vis[v][val-cost]==0)  
                {  
                    vis[v][val-cost]=1;  
                    nex.u=v;  
                    nex.val=val-cost;  
                    s.push(nex);  
                }  
            }  
        }  
    }  
    int output=0x3f3f3f3f;  
    for(int i=0;i<=k;i++)  
    {  
        output=min(output,dis[n][i]);  
    }  
    if(output==0x3f3f3f3f)  
    printf("-1\n");  
    else printf("%d\n",output);  
}  
int main()  
{  
    int T;
    scanf("%d",&T);
    while (T--)
    {
	cont=0;  
	memset(head,-1,sizeof(head));  
	scanf("%d%d%d%d",&n,&m1,&m2,&k);  
	for(int i=0;i<m1;i++)  
	{  
	    int x,y;  
	    scanf("%d%d",&x,&y);  
	    add(x,y,0,1); 
	    add(y,x,0,1);
	}  
	for ( int i = 0 ; i < m2 ; i++)
	{
	    int x,y,len;
	    scanf("%d%d%d",&x,&y,&len);
	    add(x,y,len,len);
	    add(y,x,len,len);
	}
	SPFA(1);  
    }
    return 0;
}  


