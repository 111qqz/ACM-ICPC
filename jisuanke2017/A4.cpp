#include<stdio.h>  
#include<string.h>  
#include<queue>  
using namespace std;  
int head[100000];  
struct EdgeNode  
{  
    int to;  
    int w;  
    int cost;  
    int next;  
}e[100000];  
struct node  
{  
    int u,val;  
}now,nex;  
int dis[105][10050];  
int vis[105][10050];  
int k,n,m,cont;  
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
int main() {  
    int n,m,a,b,c,d;  
	int T;
	scanf("%d",%T);
	while (T--)
	{
   
	    scanf("%d%d%d",&money,&n,&m);
	    init();  
	 while (m1--)
       {
	   int a,b;
	    scanf("%d %d",&a,&b);
	    add(a,b,0,1);
	    add(b,a,0,1);
	}
       while (m2--)
	{
	    int u,v,c;
	    scanf("%d %d %d",&u,&v,&c);
	    add(u,v,c,c);
	    add(v,u,c,c);
	}
       
       printf("%d\n",min_len(1,n));  
   }  
return 0;  
}  
 
int main()  
{  
    cont=0;  
    memset(head,-1,sizeof(head));  
    scanf("%d%d%d",&k,&n,&m);  
    for(int i=0;i<m;i++)  
    {  
        int x,y,len,cost;  
        scanf("%d%d%d%d",&x,&y,&len,&cost);  
        add(x,y,len,cost);  
    }  
    SPFA(1);  
}  
