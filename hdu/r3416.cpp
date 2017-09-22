//============================================================================
// Name        : HDU.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXN=2010;
const int MAXM=2000010;
const int INF=0x3f3f3f3f;

//最大流SAP

struct Node
{
    int to,next,cap;
}edge[MAXM];
int tol;
int head[MAXN];
int gap[MAXN],dis[MAXN],pre[MAXN],cur[MAXN];
void init()
{
    tol=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int w,int rw=0)
{
    edge[tol].to=v;edge[tol].cap=w;edge[tol].next=head[u];head[u]=tol++;
    edge[tol].to=u;edge[tol].cap=rw;edge[tol].next=head[v];head[v]=tol++;
}

int sap(int start,int end,int nodenum)
{
    memset(dis,0,sizeof(dis));
    memset(gap,0,sizeof(gap));
    memcpy(cur,head,sizeof(head));
    int u=pre[start]=start,maxflow=0,aug=-1;
    gap[0]=nodenum;
    while(dis[start]<nodenum)
    {
        loop:
        for(int &i=cur[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].cap&&dis[u]==dis[v]+1)
            {
                if(aug==-1||aug>edge[i].cap)
                    aug=edge[i].cap;
                pre[v]=u;
                u=v;
                if(v==end)
                {
                    maxflow+=aug;
                    for(u=pre[u];v!=start;v=u,u=pre[u])
                    {
                        edge[cur[u]].cap-=aug;
                        edge[cur[u]^1].cap+=aug;
                    }
                    aug=-1;
                }
                goto loop;
            }
        }
        int mindis=nodenum;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].cap&&mindis>dis[v])
            {
                cur[u]=i;
                mindis=dis[v];
            }
        }
        if((--gap[dis[u]])==0)break;
        gap[dis[u]=mindis+1]++;
        u=pre[u];
    }
    return maxflow;
}




//SPFA
int first[MAXN];
bool vis[MAXN];
int cnt[MAXN];
int que[MAXN];
int dist[MAXN];
struct Edge
{
    int to,v,next;
}edge1[MAXM];
int tt;
void add(int a,int b,int v)
{
    edge1[tt].to=b;
    edge1[tt].v=v;
    edge1[tt].next=first[a];
    first[a]=tt++;
}
bool SPFA(int start,int n)
{
    int front=0,rear=0;
    for(int v=1;v<=n;v++)
    {
        if(v==start)
        {
            que[rear++]=v;
            vis[v]=true;
            cnt[v]=1;
            dist[v]=0;
        }
        else
        {
            vis[v]=false;
            cnt[v]=0;
            dist[v]=INF;
        }
    }
    while(front!=rear)
    {
        int u=que[front++];
        vis[u]=false;
        if(front>=MAXN)front=0;
        for(int i=first[u];i!=-1;i=edge1[i].next)
        {
            int v=edge1[i].to;
            if(dist[v]>dist[u]+edge1[i].v)
            {
                dist[v]=dist[u]+edge1[i].v;
                if(!vis[v])
                {
                    vis[v]=true;
                    que[rear++]=v;
                    if(rear>=MAXN)rear=0;
                    if(++cnt[v]>n)return false;
                }
            }
        }
    }
    return true;
}
int a[100010],b[100010],c[100010];
int dist1[MAXN],dist2[MAXN];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    int n,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        int A,B;
        for(int i=0;i<m;i++)
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
        scanf("%d%d",&A,&B);
        tt=0;
        memset(first,-1,sizeof(first));
        for(int i=0;i<m;i++)
            add(a[i],b[i],c[i]);
        SPFA(A,n);
//        if(dist[B]==INF)
//        {
//            printf("0\n");
//            continue;
//        }
        memcpy(dist1,dist,sizeof(dist));
        tt=0;
        memset(first,-1,sizeof(first));
        for(int i=0;i<m;i++)
            add(b[i],a[i],c[i]);
        SPFA(B,n);
        memcpy(dist2,dist,sizeof(dist));
        init();
        for(int i=0;i<m;i++)
        {
            if(a[i]!=b[i] && dist1[a[i]]+dist2[b[i]]+c[i]==dist1[B])
                addedge(a[i],b[i],1);
        }
        printf("%d\n",sap(A,B,n));
    }
    return 0;
}
