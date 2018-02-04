/*************************************************************************
	> File Name: code/2015summer/0713kk.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月13日 星期一 15时21分40秒
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
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int N=1E3+5;
vector<int> edge[N];
int query[N][N],f[N],count[N],indeg[N];
int vis[N],n,m;

int findSet(int x)
{
    if(x!=f[x])
    {
        f[x]=findSet(f[x]);
    }
    return f[x];
}

void Tarjan(int u)
{
    f[u]=u;
    for(int i=0;i<edge[u].size();i++)
    {
        Tarjan(edge[u][i]);
        father[edge[u][i]]=u;
    }
    vis[u]=1;
    for(int i=1;i<=n;i++)
        if(vis[i] && query[u][i])
            count[findSet(i)]+=query[u][i];
}
void init()
{

}

int main()
{

    while(scanf("%d",&n)!=EOF)
	{
        for(int i=1;i<=n;i++)
            edge[i].clear();
        memset(query,0,sizeof(query));
        memset(vis,0,sizeof(vis));
        memset(count,0,sizeof(count));
        memset(indeg,0,sizeof(indeg));
        int u,v;
        for(int i=0;i<n;i++)
	  {
            scanf("%d:(%d)",&u,&m);
            while(m--)
		{
                scanf(" %d",&v);
                edge[u].push_back(v);
                indeg[v]++;
            }
        }
        scanf(" %d",&m);
        for(int i=0;i<m;i++){
            scanf(" (%d %d)",&u,&v);
            query[u][v]++;
            query[v][u]++;
        }
        for(int i=1;i<=n;i++)
            if(indeg[i]==0){
                Tarjan(i);
                break;
            }
        for(int i=1;i<=n;i++)
            if(count[i])
                printf("%d:%d\n",i,count[i]);
    }
    return 0;
}

