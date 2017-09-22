/* ***********************************************
Author :111qqz
Created Time :2016年01月02日 星期六 18时56分17秒
File Name :code/bc/#68/1002.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define fst first
#define sec second
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;
#define pi pair < int ,int >
#define MP make_pair

using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=1E5+7;
int n;
vector<int>Edge[N];
int cnt;
bool vis[N];
int ans[N];
int sum[N];
int path[N];
void print()
{
    for ( int i =1 ; i <= n ; i++)
    {
	cout<<Edge[i].size()<<endl;
    }
}

void dfs(int x)
{
   // cout<<"x:"<<x<<endl;
    vis[x] = true;
    cnt++;
    path[cnt] = x;
    for ( int i = 0 ; i < Edge[x].size() ; i++)
    {
	int v = Edge[x][i];
	if (!vis[v])
	{
	    dfs(v);
	}
    }
    
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    ms(ans,0);
	    ms(vis,false);
	    scanf("%d",&n);
	    for ( int i = 1 ; i <= n ; i++)
	    {
		Edge[i].clear();
		Edge[i].push_back(i);
	    }
	    for ( int i = 1 ; i <= n -1 ; i++)
	    {
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		if (w==1) continue;
		Edge[u].push_back(v);
		Edge[v].push_back(u);
	    }
	    for ( int i = 1 ; i <= n ; i++)
	    {
		cnt = 0 ;
		if (!vis[i])
		{
		    dfs(i);
		}
		for ( int j = 1 ; j <= cnt ; j ++) ans[path[j]] = cnt;
	    }
	  //  print();
	    int total = 0;
	    for ( int i = 1 ; i <= n ; i++)
	    {
	//	cout<<ans[i]<<endl;
		total ^= ans[i];
	    }
	    printf("%d\n",total);

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
