/*************************************************************************
	> File Name: code/cf/#316/D.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月15日 星期六 02时55分55秒
 ************************************************************************/
#include <bits/stdc++.h>


using namespace std;
const int N=5E5+7;
int n,m;
vector<int> adj[N];
char S[N];
vector<int> occ[N][26];
int in[N], out[N], now;

void dfs(int u, int depth)
{
    occ[depth][S[u]-'a'].push_back(++now);
    in[u]=now;
    vector<int>::iterator it;
    for (it=adj[u].begin();it!=adj[u].end();it++)
    {
	dfs(*it,depth+1);
    }
    out[u]=now;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=2; i<=n; i++)
    {
        int a;
        scanf("%d",&a);
        adj[a].push_back(i);
    }
    scanf("%s", S+1);
    dfs(1, 1);
    while(m--)
    {
        int v, h;
        scanf("%d %d",&v,&h);
        int odd=0;
        for(int i=0; i<26; i++)
        {
            int cnt=upper_bound(occ[h][i].begin(), occ[h][i].end(), out[v])-
                    lower_bound(occ[h][i].begin(), occ[h][i].end(), in[v]);
            if(cnt%2==1)
            {
                odd++;
                if(odd>1)
                    break;
            }
        }
        if(odd>1)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
