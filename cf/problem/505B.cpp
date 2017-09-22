/* ***********************************************
Author :111qqz
Created Time :2015年12月07日 星期一 09时52分33秒
File Name :code/cf/problem/505B.cpp
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
#define pi pair<int ,int >
typedef long long LL;



using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=105;
int n,m,q;
vector<pi>edge[N];

bool vis[N];


void dfs (int x,int y,int col)
{
//    cout<<"x:"<<x<<" col:"<<col<<endl;
    vis[x] = true;
    if (x==y) return;
    for ( int i = 0 ; i < edge[x].size();  i++)
    {
	pi v =  edge[x][i];
//	cout<<"to:"<<v.sec<<endl;
	if (v.sec ==col &&!vis[v.fst])
	    dfs(v.fst,y,col);
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	scanf("%d %d",&n,&m); 
	for ( int i = 0 ; i < m ; i++)
	{
	    int x,y,z;
	    cin>>x>>y>>z;
	    edge[x].push_back(make_pair(y,z));
	    edge[y].push_back(make_pair(x,z));
	  //  cnt[x][y].insert(z);
	  //  cnt[y][x].insert(z);
	}
	scanf("%d",&q);
	for ( int i = 0 ; i < q ; i ++)
	{
	    int u,v;
	    scanf("%d %d",&u,&v);
	    int res = 0 ;
	    for ( int j = 0 ; j <=100 ; j++)  //把j++写成了i++,调了半小时2333
	    {
		ms(vis,false);
		dfs(u,v,j);
		if (vis[v]) res++;
	    }
	    cout<<res<<endl;
	}
	




  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
