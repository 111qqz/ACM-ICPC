/* ***********************************************
Author :111qqz
Created Time :2016年03月19日 星期六 11时03分10秒
File Name :code/cf/problem/437C.cpp
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
const int N=1E3+7;
bool conc[N][N];
pi val[N];
vector < int  > edge[N]; 
int n,m;

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (  int i = 1 ; i <= n ; i++)
	{
	    int tmp ;
	    cin>>tmp;
	    val[i] = MP(tmp,i);
	}
	sort(val+1,val+n+1);
	
	ms(conc,false);
	for ( int i = 1 ; i <= m ; i++)
	{
	    int u,v;
	    cin>>u>>v;
	    conc[u][v] = true;
	    conc[v][u] = true;
	    edge[u].push_back(v);
	    edge[v].push_back(u);
	}

	int ans = 0 ;
	for ( int i = 1; i  <= n ; i++)
	{
	    int u = val[i].sec;
	    for ( int j = 0 ; j < edge[u].size() ; j++)
	    {
		int v = edge[u][j];
		if (conc[u][v])
		{
		    ans += val[i].fst;
		    conc[u][v] = false;
		    conc[v][u] = false;
		}
	    }
	}
	cout<<ans<<endl;

	



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
