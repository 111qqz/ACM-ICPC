/* ***********************************************
Author :111qqz
Created Time :2016年09月01日 星期四 01时13分04秒
File Name :code/hdu/4751.cpp
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
int n;
bool know[N][N];
int col[N];
vector<int>edge[N];

bool dfs( int u,int x)
{
    col[u] = x;
    int siz = edge[u].size();
    for ( int i = 0 ; i < siz;  i++)
    {
	int v  = edge[u][i];
	if (col[v]==x) return false;
	if (col[v]==1-x) continue;
	if (!dfs(v,1-x)) return false;
    }
    return true;
}

bool ok()
{
    for ( int i = 1 ; i <= n ; i++)  //每个联通分量都合法才合法。
	if (col[i]==-1)
	    if (!dfs(i,0)) return false;

    return true;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%d",&n))
	{
	    ms(col,-1);
	    for ( int i = 0 ; i <= n ;i++) edge[i].clear();
	    ms(know,false);
	    for ( int i = 1 ; i <= n ; i++)
	    {
		int x;
		while (~scanf("%d",&x)&&x!=0)
		{
		    know[i][x] = true;
		}
	    }
	    
	    for ( int i = 1 ; i <= n ; i++)
		for ( int j = i+1 ; j <= n ; j++)
		{
		    if (know[i][j]&&know[j][i]) continue;
		   // cout<<"i:"<<i<<" j:"<<j<<endl;
		    edge[i].push_back(j);
		    edge[j].push_back(i);
		}

	    if (ok())
		puts("YES");
	    else puts("NO");
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
