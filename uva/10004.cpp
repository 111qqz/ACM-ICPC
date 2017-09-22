/* ***********************************************
Author :111qqz
Created Time :2016年08月31日 星期三 21时50分16秒
File Name :code/uva/10004.cpp
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
const int N=205;
vector <int>edge[N];
int n,m;
int col[N];
bool dfs( int u,int x)
{
    col[u] = x;
    int siz = edge[u].size();
    for ( int i = 0 ; i < siz ; i++)
    {
	int v = edge[u][i];
	if (col[v]==1-x) continue;
	if (col[v]==x) return false;
	if (!dfs(v,1-x)) return false;
    }
    return true;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%d",&n))
	{
	    if (n==0) break;
	    ms(col,-1);
	    for ( int i =  0 ;i <= n ; i++) edge[i].clear();
	    scanf("%d",&m);
	    for ( int i = 1 ; i <= m ; i++)
	    {
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	    }
	    if (dfs(0,0))
		puts("BICOLORABLE.");
	    else puts("NOT BICOLORABLE.");
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
