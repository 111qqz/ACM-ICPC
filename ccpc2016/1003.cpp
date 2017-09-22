/*
HDU 2196
G++ 46ms  916K

*/

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int MAXN=10010;
int n;
struct Node
{
    int to;
    int next;
    int len;
}edge[MAXN*2];//因为存无向边，所以需要2倍
int head[MAXN];//头结点
int tol;
int maxn[MAXN];//该节点往下到叶子的最大距离
int smaxn[MAXN];//次大距离
int maxid[MAXN];//最大距离对应的序号
int smaxid[MAXN];//次大的序号
int dianquan[N];

void init()
{
    tol=0;
    memset(head,-1,sizeof(head));
}

void add(int a,int b,int len)
{
    edge[tol].to=b;
    edge[tol].len=len;
    edge[tol].next=head[a];
    head[a]=tol++;
    edge[tol].to=a;
    edge[tol].len=len;
    edge[tol].next=head[b];::
    head[b]=tol++;
}

//求结点v往下到叶子结点的最大距离
//p是v的父亲结点
void dfs1(int u,int p)
{
    maxn[u]=0;
    smaxn[u]=0;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==p)continue;//不能往上找父亲结点
        dfs1(v,u);
        if(smaxn[u]<maxn[v]+edge[i].len)
        {
            smaxn[u]=maxn[v]+edge[i].len;
            smaxid[u]=v;
            if(smaxn[u]>maxn[u])
            {
                swap(smaxn[u],maxn[u]);
                swap(smaxid[u],maxid[u]);
            }
        }
    }
}
//p是u的父亲结点，len是p到u的长度
void dfs2(int u,int p)
{
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==p)continue;
        if(v==maxid[u])
        {
            if(edge[i].len+smaxn[u]>smaxn[v])
            {

                smaxn[v]=edge[i].len+smaxn[u];
                smaxid[v]=u;
                if(smaxn[v]>maxn[v])
                {
                    swap(smaxn[v],maxn[v]);
                    swap(smaxid[v],maxid[v]);
                }
            }
        }
        else
        {
            if(edge[i].len+maxn[u]>smaxn[v])
            {
                smaxn[v]=edge[i].len+maxn[u];
                smaxid[v]=u;
                if(smaxn[v]>maxn[v])
                {
                    swap(smaxn[v],maxn[v]);
                    swap(maxid[v],smaxid[v]);
                }
            }
        }
        dfs2(v,u);
    }
}
int main()
{
    freopen("code/in.txt","r",stdin);

    int T;
    cin>>T;
    while (T--)
    {	
	scanf("%d",&n);
	init();
	for ( int i = 1 ; i <= n ; i++) scanf("%d\n",dianquan[i]);
	for(int i=2;i<=n;i++)
	{
	    int u,v,w;
	    scanf("%d%d",&u,&v,&w);
	    add(u,v,w);
	}
	dfs1(1,-1);
	dfs2(1,-1);
	for(int i=1;i<=n;i++)
	    printf("%d\n",maxn[i]);
    }
    return 0;
}
