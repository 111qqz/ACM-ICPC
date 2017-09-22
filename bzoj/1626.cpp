/* ***********************************************
Author :111qqz
Created Time :2016年04月04日 星期一 13时49分48秒
File Name :code/bzoj/1626.cpp
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
#include <iomanip>
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
int f[N];
int n,m;
bool conc[N][N];
struct node
{
    long double x,y;

    void input()
    {
	cin>>x>>y;
    }

    long double dis(node p)
    {
	long double res;
	res = (x-p.x)*(x-p.x)+(y-p.y)*(y-p.y);
	res = sqrt(res);
	return res;
    }
}p[N];

struct edge
{
    int u,v;
    long double  w;

    bool operator < (edge b)const
    {
	return w<b.w;
    }

}e[N*N];
int root (int x)
{
    if (x!=f[x]) f[x] = root (f[x]);
    return f[x];
}

void merge( int x,int y)
{
//    cout<<"x:"<<x<<" y:"<<y<<endl;
    int rx = root (x);
    int ry = root (y);
    if (rx!=ry)
    {
	f[rx]=ry;
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n>>m;
	for ( int i = 1 ;i <= n ; i++) p[i].input();
        for ( int i = 1 ; i < N ; i++) f[i] =  i;	
	ms(conc,false);
	int total = 0 ;
	for ( int i = 1 ; i <= m ; i++)
	{
	    int u,v;
	    cin>>u>>v;
	    conc[u][v] = true;
	    conc[v][u] = true;
	    if (root(u)==root(v)) continue;
	    merge(u,v);
	    total++;
	}
    
	int cnt = 0 ;
	for ( int i = 1 ; i <= n ; i++)	
	    for ( int j = i+1 ; j <= n ; j++)
		if (!conc[i][j])
		{
		    ++cnt;
		    e[cnt].u = i;
		    e[cnt].v = j;
		    e[cnt].w = p[i].dis(p[j]);
		}

	sort(e+1,e+cnt+1);
//	cout<<"cnt:"<<cnt<<endl;
	long double res = 0 ;
	for ( int i = 1 ; i <= cnt ;i++)
	{
	    if (root(e[i].u)==root(e[i].v)) continue;
	    merge(e[i].u,e[i].v);
	    total++;
	    res +=e[i].w;
	  //  cout<<"res:"<<res<<endl;

	    if (total>=n-1) break;
	}

	cout<<fixed<<setprecision(2)<<res<<endl;


	
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
