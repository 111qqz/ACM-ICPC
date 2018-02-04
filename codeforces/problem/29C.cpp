/* ***********************************************
Author :111qqz
Created Time :2015年12月30日 星期三 19时55分15秒
File Name :code/cf/problem/29C.cpp
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
map<int,vector<int> >e;
map<int,bool>vis;
map<int,int>in;
map<int,int>::iterator it;
int beg;
int n ;
void dfs( int x)
{
    vis[x] = true;
    printf("%d ",x);
    for ( int i  = 0 ; i < e[x].size() ; i++ )
    {
	int v = e[x][i];
	if (!vis[v]) dfs(v);
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n;
	vis.clear();
	in.clear();

	
	for ( int i = 1 ; i <= n ; i++)
	{
	    int u,v;
	    scanf("%d %d",&u,&v);
	    e[u].push_back(v);
	    e[v].push_back(u);
	    in[u]++;
	    in[v]++;
	}

	for ( it=in.begin() ;it!=in.end();it++)
	{
	    if (it->second ==1)
	    {
		beg = it->first;
		break;
	    }
	}
	dfs(beg);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
