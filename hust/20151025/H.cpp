/*************************************************************************
	> File Name: code/hust/20151025/H.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月27日 星期二 19时30分28秒
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
                 
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
#define pb push_back
using namespace std;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=5E4+7;

int n,m,k;
vector<int> adj[N];
vector<pair< pair<int,int> ,int> > ans;
int pa[N];
int kt[N];
bool spe[N];
void init()
{
    ms(spe,false);
    ms(pa,0);
    scanf("%d %d %d",&n,&m,&k);
    for ( int i = 0,u,v; i < m ; i++)
    {
	scanf("%d %d",&u,&v);
	adj[u].push_back(v);
	adj[v].push_back(u);
    }

    for ( int i = 0,u ; i < k ; i++)
    {
	scanf("%d",&u);
	spe[u] = true;
    }

}

void dfs( int u)
{
 //   cout<<"u:"<<u<<endl;
    vector<int> tmp;
    tmp.clear();

    for ( int j = 0 ; j < adj[u].size(); j++)
    {
	int v =adj[u][j];
	if (pa[v]==0)
	{
	    pa[v] =  u;
	    dfs(v);
	    if (kt[v]) tmp.push_back(kt[v]);
	}
    }
    while (tmp.size()>1)
    {
	int x1 = tmp.back();tmp.pop_back();
	int x2 = tmp.back(); tmp.pop_back();
//	cout<<"x1:"<<x1<<" x2:"<<x2<<endl;
	ans.pb(make_pair(make_pair(x1,x2),u));
    }
    if (tmp.size()>0)
    {
	int x = tmp.back();tmp.pop_back();

//	cout<<"x:"<<x<<endl;
	if (spe[u])
	{
	    ans.push_back(make_pair(make_pair(x,u),u));
	}
	else kt[u] = x;
    }
    else 
    {
	if (spe[u]) kt[u] =  u;
    }
}

void solve()
{
    for ( int i = 1 ; i <n+1 ; i++)
	if (!pa[i])
	{
	    pa[i] = -1;
	    dfs(i);
	}

    vector<int>p,q;
   // printf("%d\n",ans.size());
      cout<<ans.size()<<endl;
    for ( int i = 0 ; i < ans.size(); i++)
    {
	int u = ans[i].first.first;
	int v = ans[i].first.second;
	int r = ans[i].second;
//	cout<<"************************"<<endl;
//	cout<<"u:"<<u<<" v:"<<v<<" r:"<<r<<endl;
//	cout<<"************************"<<endl<<endl;

	p.clear();
	q.clear();
	while (u!=r)
	{
	    p.push_back(u);
	    u = pa[u];
	}

	while (v!=r)
	{
	    q.push_back(v);
	    v = pa[v];
	}

	//printf("%d ",p.size()+q.size());
	cout<<p.size()+q.size()<<" ";
	for ( int j = 0 ; j < p.size(); j++) printf("%d ",p[j]);
	printf("%d ",r);
    
	reverse(q.begin(),q.end());
	for ( int j = 0 ; j < q.size(); j++) printf("%d ",q[j]);
	puts("");    
	
    }
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
   init();
   solve();
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
