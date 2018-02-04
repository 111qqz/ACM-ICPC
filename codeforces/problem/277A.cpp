/* ***********************************************
Author :111qqz
Created Time :2015年12月05日 星期六 20时55分14秒
File Name :code/cf/problem/277A.cpp
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
const int N=2E2+5;
int n,m;
vector<int>edge[N];
bool vis[N];

void dfs( int x)
{
  //  cout<<"x:"<<x<<endl;
    vis[x] = true;
    for ( int i = 0 ; i < edge[x].size(); i ++)
    {
	int v = edge[x][i];
//	cout<<"v:"<<v<<endl;
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
	
	scanf("%d %d",&n,&m);
	int p =  0;
	for ( int i = 1 ; i <= n ; i++)
	{
	    int k ;
	    scanf("%d",&k);
	    if (k!=0) p = -1;
	    for ( int j =  0 ; j < k ; j++)
	    {
		int x;
		scanf("%d",&x);
		edge[i].push_back(x+n);
		edge[x+n].push_back(i);
	    }
	}
	int cnt = 0 ;
	ms(vis,false);
	for ( int i = 1 ; i <= n ; i++)
	{
	    if (!vis[i])
	    {
		dfs(i);
		cnt++;
	    }
	}
	cout<<cnt+p<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
