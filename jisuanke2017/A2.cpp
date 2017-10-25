#include <iostream>  
#include<stdio.h>  
#include<string.h>  
#include<string>  
#include<algorithm>  
#include<stdlib.h>  
#include<queue>  
#define mem(a,b) memset(a,b,sizeof(a))  
#define inf 0x3f3f3f3f  
using namespace std;  
int n,m,k;  
struct node  
{  
    int num,dis,cost;  
    bool friend operator < (node a,node b)  
    {  
        return a.dis>b.dis;  
    }  
};  
int dis[105][10005];  
int u[10005],v[10005],w[10005],c[10005];  
int first[105],nex[10005];  
void spfa()  
{  
    for(int i=1;i<=n;i++)  
    {  
        for(int j=0;j<=k;j++)  
        {  
            dis[i][j]=inf;  
        }  
    }  
    dis[1][0]=0;  
    priority_queue<node>q;  
    node a,b;  
    a.num=1;  
    a.cost=0;  
    a.dis=0;  
    q.push(a);  
    while(!q.empty())  
    {  
        a=q.top();  
        q.pop();  
        if(a.num==n)  
        {  
            printf("%d\n",a.dis);  
            return;  
        }  
        for(int i=first[a.num];i!=-1;i=nex[i])  
        {  
            int cost=a.cost+c[i];  
            if(cost>k)continue;  
            if(dis[v[i]][cost]>a.dis+w[i])  
            {  
            dis[v[i]][cost]=a.dis+w[i];  
            b.num=v[i];  
            b.cost=cost;  
            b.dis=dis[v[i]][cost];  
            q.push(b);  
            }  
        }  
    }  
    printf("-1\n");  
}  
int main()  
{  
    while(~scanf("%d",&k))  
    {  
        scanf("%d",&n);  
        scanf("%d",&m);  
        mem(first,-1);  
        for(int i=0;i<m;i++)  
        {  
            scanf("%d%d%d%d",&u[i],&v[i],&w[i],&c[i]);  
            nex[i]=first[u[i]];  
            first[u[i]]=i;  
        }  
        spfa();  
    }  
    return 0;  
}  

