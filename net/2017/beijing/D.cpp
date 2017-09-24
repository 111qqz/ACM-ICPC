/* ***********************************************
/* ***********************************************
 *
Author :111qqz
Created Time :2017年09月23日 星期六 12时50分44秒
File Name :D.cpp
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
#define PB push_back
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
const int N=1E3+7;
vector< int >edge[N]; // w=1 
int n;
bool vis[N];
int d[N]; //距离
int beg; //直径的起点
int lst ;//直径的终点
int pre[N]; //记录前缀
vector<int>path; //记录最长路径。
int in[N];
bool ok[N]; //标记直径上的点
int dep[N]; //维护直径上的点的最大深度.
void  bfs( int s)
{
    ms(d,0);
    ms(vis,false);
    ms(pre,-1);

    queue<int>q;
    q.push(s);
    vis[s] = true;
    while (!q.empty())
    {
	int u = q.front();
	q.pop();
	int siz = edge[u].size();
	for ( int i = 0 ; i < siz;  i++)
	{
	    int v  = edge[u][i];
	    if (vis[v]) continue;
	    d[v] = d[u] + 1;
	    pre[v] =  u;
	    vis[v] = true;
	    q.push(v);
	}
    }


}

int getdep( int x)
{
    ms(d,0);
    ms(vis,false);
    ms(pre,-1);
    queue<int>q;
    q.push(x);
    vis[x] = true;
    int ret =  0;
    while (!q.empty())
    {
	int u = q.front();
	q.pop();
	int siz  = edge[u].size();
	for ( int i = 0 ; i < siz;  i++)
	{
	    int v = edge[u][i];
	    if (vis[v]||ok[v]) continue;
	    d[v] = d[u] + 1;
	    ret = max(ret,d[v]);
	    vis[v] = true;
	    q.push(v);
	}
    }
    return ret;
}
void getdir( int x)
{
    while (x!=-1)
    {
	path.push_back(x);
	ok[x] = true;
	x = pre[x];
    }
    int siz = path.size();
    for ( int i = 0 ; i < siz ; i++) 
    {
	int v = path[i];
	dep[v] = getdep(v); 
//	printf("%d ",v);
    }
 //   cout<<"depth:"<<endl;
    for ( int i = 0 ;i < siz ; i++)
    {
	int v = path[i];
//	printf("dep:%d \n",dep[v]);
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("./in.txt","r",stdin);
  #endif
    int T;
    cin>>T;
    while (T--)
    {
	ms(in,0);
	ms(ok,false);
	path.clear();
	for ( int i = 0 ; i <1002 ; i++) edge[i].clear();
	scanf("%d",&n);
	
	for ( int i = 1 ; i <= n-1 ; i++)
	{
	    int x,y;
	    scanf("%d%d",&x,&y);
	    edge[x].push_back(y);
	    edge[y].push_back(x);
	    in[x]++;
	    in[y]++;
	}
	bfs(1);
	int mx =  0;
	for (  int i = 1 ; i <=  n ; i++)
	{
	    if (d[i]>mx)
	    {
		mx = d[i];
		lst =  i;
	    }
	}
	bfs(lst);
	mx = 0;
	for ( int i = 1 ; i <= n ; i++)
	{
	    if (d[i]>mx)
	    {
		mx = d[i];
		beg = i;
	    }
	}
	getdir(beg);
	int mn1=inf,mn2=inf;
	int s,t;
	int path_s = path.size();
	for ( int i = 0 ; i < path_s;  i++ )
	{
	    int v = path[i];
	    int id = i;
	    if (id>(path_s-1)/2) id = path_s-id-1;
	    int val = id-dep[v];
	    if (i+1>path_s/2)
	    {
		if (val<mn2)
		{
		    mn2 = val;
		    t = v;
		}
	    }else
	    {
		if (val<=mn1)
		{
		    mn1 = val;
		    s = v;
		}
	    }

//	    printf("id:%d val:%d\n",id,val);
	}
	    
//	cout<<"s:"<<s<<" t:"<<t<<endl;
	s = path[0];
	t = path[path_s-1];
//	cout<<"s:"<<s<<endl;
//	cout<<"t:"<<t<<endl;
	edge[s].push_back(t);
	edge[t].push_back(s);

	bfs(1);
	mx =  0;
	for ( int i = 1 ; i <= n ; i++)
	{
	    if (d[i]>mx)
	    {
		mx = d[i];
		lst = i ;
	    }
	}
	bfs(lst);
	mx =  0;
	for ( int i = 1 ; i <= n ; i++)
	{
	    if (d[i]>mx)
	    {
		mx = d[i];
		beg =  i;
	    }
	}
	printf("%d\n",mx);
    }
	
	    

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
Author :111qqz
Created Time :2017年09月23日 星期六 12时50分44秒
File Name :D.cpp
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
#define PB push_back
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
const int N=1E3+7;
vector< int >edge[N]; // w=1 
int n;
bool vis[N];
int d[N]; //距离
int beg; //直径的起点
int lst ;//直径的终点
int pre[N]; //记录前缀
vector<int>path; //记录最长路径。
int in[N];
bool ok[N]; //标记直径上的点
int dep[N]; //维护直径上的点的最大深度.
void  bfs( int s)
{
    ms(d,0);
    ms(vis,false);
    ms(pre,-1);

    queue<int>q;
    q.push(s);
    vis[s] = true;
    while (!q.empty())
    {
	int u = q.front();
	q.pop();
	int siz = edge[u].size();
	for ( int i = 0 ; i < siz;  i++)
	{
	    int v  = edge[u][i];
	    if (vis[v]) continue;
	    d[v] = d[u] + 1;
	    pre[v] =  u;
	    vis[v] = true;
	    q.push(v);
	}
    }


}

int getdep( int x)
{
    ms(d,0);
    ms(vis,false);
    ms(pre,-1);
    queue<int>q;
    q.push(x);
    vis[x] = true;
    int ret =  0;
    while (!q.empty())
    {
	int u = q.front();
	q.pop();
	int siz  = edge[u].size();
	for ( int i = 0 ; i < siz;  i++)
	{
	    int v = edge[u][i];
	    if (vis[v]||ok[v]) continue;
	    d[v] = d[u] + 1;
	    ret = max(ret,d[v]);
	    vis[v] = true;
	    q.push(v);
	}
    }
    return ret;
}
void getdir( int x)
{
    while (x!=-1)
    {
	path.push_back(x);
	ok[x] = true;
	x = pre[x];
    }
    int siz = path.size();
    for ( int i = 0 ; i < siz ; i++) 
    {
	int v = path[i];
	dep[v] = getdep(v); 
//	printf("%d ",v);
    }
 //   cout<<"depth:"<<endl;
    for ( int i = 0 ;i < siz ; i++)
    {
	int v = path[i];
//	printf("dep:%d \n",dep[v]);
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("./in.txt","r",stdin);
  #endif
    int T;
    cin>>T;
    while (T--)
    {
	ms(in,0);
	ms(ok,false);
	path.clear();
	for ( int i = 0 ; i <1002 ; i++) edge[i].clear();
	scanf("%d",&n);
	
	for ( int i = 1 ; i <= n-1 ; i++)
	{
	    int x,y;
	    scanf("%d%d",&x,&y);
	    edge[x].push_back(y);
	    edge[y].push_back(x);
	    in[x]++;
	    in[y]++;
	}
	bfs(1);
	int mx =  0;
	for (  int i = 1 ; i <=  n ; i++)
	{
	    if (d[i]>mx)
	    {
		mx = d[i];
		lst =  i;
	    }
	}
	bfs(lst);
	mx = 0;
	for ( int i = 1 ; i <= n ; i++)
	{
	    if (d[i]>mx)
	    {
		mx = d[i];
		beg = i;
	    }
	}
	getdir(beg);
	int mn1=inf,mn2=inf;
	int s,t;
	int path_s = path.size();
	for ( int i = 0 ; i < path_s;  i++ )
	{
	    int v = path[i];
	    int id = i;
	    if (id>(path_s-1)/2) id = path_s-id-1;
	    int val = id-dep[v];
	    if (i+1>path_s/2)
	    {
		if (val<mn2)
		{
		    mn2 = val;
		    t = v;
		}
	    }else
	    {
		if (val<=mn1)
		{
		    mn1 = val;
		    s = v;
		}
	    }

//	    printf("id:%d val:%d\n",id,val);
	}
	    
//	cout<<"s:"<<s<<" t:"<<t<<endl;
	s = path[0];
	t = path[path_s-1];
//	cout<<"s:"<<s<<endl;
//	cout<<"t:"<<t<<endl;
	edge[s].push_back(t);
	edge[t].push_back(s);

	bfs(1);
	mx =  0;
	for ( int i = 1 ; i <= n ; i++)
	{
	    if (d[i]>mx)
	    {
		mx = d[i];
		lst = i ;
	    }
	}
	bfs(lst);
	mx =  0;
	for ( int i = 1 ; i <= n ; i++)
	{
	    if (d[i]>mx)
	    {
		mx = d[i];
		beg =  i;
	    }
	}
	printf("%d\n",mx);
    }
	
	    

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
