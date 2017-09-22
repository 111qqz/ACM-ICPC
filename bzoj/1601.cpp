/* ***********************************************
Author :111qqz
Created Time :2016年03月31日 星期四 19时32分43秒
File Name :code/bzoj/1601.cpp
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
const int N=305;
int n;
int w[N],mxw;
int a[N][N];
int m;
int f[N];

int root ( int x)
{
    if (x!=f[x]) f[x] = root (f[x]);
    return f[x];
}

void merge( int x,int y)
{
    int rx = root (x);
    int ry = root (y);
    if (rx!=ry)
    {
	f[rx] = f[ry];
    }
}
struct Edge
{
    int u,v;
    int val;

    bool operator < (Edge b) const
    {
	return val<b.val;
    }
}edge[N*N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	cin>>n;
	int m = 0  ;
	for ( int i = 1 ; i <= n ; i++)
	{
	    cin>>w[i];
	    m++;
	    edge[m].u = 0;
	    edge[m].v = i;
	    edge[m].val = w[i];
	}

	for ( int i = 1 ;i <= n ; i++)
	{
	    for ( int j = 1 ; j <= n ; j++)
	    {
		cin>>a[i][j];
	    }
	}

	
	for ( int i = 1 ; i <= n-1 ; i++)
	    for ( int j = i + 1 ; j <= n ; j++)
	    {
		m++;
		edge[m].u = i;
		edge[m].v = j;
		edge[m].val = a[i][j];
	    }

	sort(edge+1,edge+m+1);
	for ( int i = 0 ;i  <= n ; i++) f[i] = i ;
	
	int cost = 0 ;
	int cnt = 0 ;
	for ( int i = 1 ; i <= m ; i++)
	{
	    int u = edge[i].u;
	    int v = edge[i].v;
	    int val = edge[i].val;
	    if (root(u)==root (v)) continue;
	    cost += val;
	    merge(edge[i].u,edge[i].v);
	    cnt++;
	    if (cnt==n) break;
	}

	cout<<cost<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
