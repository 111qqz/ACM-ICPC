/* ***********************************************
Author :111qqz
Created Time :2015年12月05日 星期六 20时18分23秒
File Name :code/problem/217A.cpp
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



using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=105;
int n;
bool vis[N];
int x[N],y[N];

vector<int>edge[N];

void dfs( int x)
{
    vis[x] = true;
    for ( int i = 0 ; i < edge[x].size() ; i++)
    {
	int v = edge[x][i];
	if  (!vis[v])
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

	scanf("%d",&n);
	for ( int i = 0 ; i < n ; i++) scanf("%d %d",&x[i],&y[i]);

	for ( int i = 0 ; i  < n-1 ; i++)
	{
	    for ( int j = i+1 ; j < n ; j++)
	    {
		if (x[i]==x[j])
		{
		    edge[i].push_back(j);
		    edge[j].push_back(i);
		}
		if (y[i]==y[j])
		{
		    edge[i].push_back(j);
		    edge[j].push_back(i);
		}

	    }
	}
	ms(vis,false);
	int cnt = 0 ;
	for ( int i = 0 ; i < n ; i++)
	{
	    if (!vis[i])
	    {
		dfs(i);
		cnt++;
	    }
	}
	cout<<cnt-1<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
