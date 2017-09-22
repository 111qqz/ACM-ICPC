/* ***********************************************
Author :111qqz
Created Time :2016年03月29日 星期二 22时19分37秒
File Name :code/class/algorithm/spfa.cpp
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
const int N=40;

int n,m;
struct node
{
    int u,v,w;
}edge[N];
int s;
int d[N];
void relax(int u,int v,int w)
{
    d[v] = min(d[v],d[u]+w);
}
bool bellman_ford()
{
    for ( int i = 1 ; i  <= n -1 ; i++)
	for ( int j = 1 ; j <= m ; j++)
	    relax(edge[j].u,edge[j].v,edge[j].w);

    bool flag = true;
    
    for ( int i = 1 ;i  <= m ; i++)
	if (d[edge[i].v]>d[edge[i].u]+edge[i].w)
	{
	    flag = false;
	    break;
	}

    return flag;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/class/algorithm/bellman_in.txt","r",stdin);
  #endif
	cin>>n>>m>>s;
	ms(d,0x3f);
	d[s] =  0;
	for ( int i = 1 ; i  <=  m ; i ++)
	{
	    int u,v,w;
	    cin>>u>>v>>w;
	    edge[i].u = u;
	    edge[i].v = v;
	    edge[i].w = w;
	    if (u==s)
		d[v]=w;
	}

	if (bellman_ford())
	{
	    for ( int i = 1 ; i <= n ; i++)
		printf("点%d与点%d之间的最短距离为%d\n",i,s,d[i]);
	}




  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
