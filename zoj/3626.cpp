/*************************************************************************
	> File Name: code/zoj/3626.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月27日 星期二 21时25分20秒
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
#include<cctype>
                 

using namespace std;
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=1E2+5;
int val[N];
vector<int> adj[N*2];
int w[N][N];
int n,k,m;
int dp[N][N],vis[N];
void dfs(int u)
{
    vis[u]=1;
    dp[u][0]=val[u];
    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if(vis[v]==0)
        {
            dfs(v);
            for(int j=m;j>=0;j--)
            {
                for(int k=0;k<=j-w[u][v];k++)
                {
                    dp[u][j]=max(dp[u][j],dp[u][j-k-w[u][v]]+dp[v][k]);
                }
            }
        }
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        adj[i].clear();
	ms(dp,0);
	ms(vis,0);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&val[i]);
            dp[i][0]=val[i];
        }
        for(int i=1,u,v,cost;i<n;i++)
        {
            scanf("%d%d%d",&u,&v,&cost);
            adj[u].push_back(v);
            adj[v].push_back(u);
            w[u][v]=w[v][u]=cost;
        }
        scanf("%d%d",&k,&m);
        m/=2;
        dfs(k);
        int ans=-1;
        for(int i=0;i<=m;i++)
        {
            if(dp[k][i]>ans)
            ans=dp[k][i];
        }
        printf("%d\n",ans);
    }
    return 0;
}

