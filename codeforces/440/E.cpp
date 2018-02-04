/* ***********************************************
Author :111qqz
Created Time :2017年10月23日 星期一 15时51分51秒
File Name :E.cpp
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
#define PB push_back
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
const LL mod = 1E9+7;
struct point 
{
    int x,y;
    int id;
    bool operator < ( point b)
    {
	return  id < b.id;
    }
}p[N];


vector < int>edge[N];
bool cmpx ( point a,point b) { return a.x < b.x;}
bool cmpy( point a,point b){ return a.y<b.y;}

int n;
int cnt;
set<int>X,Y;
bool vis[N];
LL ksm ( LL a,LL b)
{
    LL res = 1;
    while (b)
    {
	if (b&1) res = res * a % mod;
	b = b >> 1LL;
	a = a * a % mod;
    }
    return res;
}
void dfs  ( int u)
{
    X.insert(p[u].x);
    Y.insert(p[u].y);
    vis[u] = true;
    cnt++;
    for ( auto v : edge[u])
	if (!vis[v]) dfs(v);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif

	cin>>n;
	for ( int i = 1 ; i <= n ; i++) cin>>p[i].x >> p[i].y,p[i].id = i;
	sort(p+1,p+n+1,cmpx);
	for ( int i = 2 ; i <= n  ; i++) 
	    if (p[i].x==p[i-1].x)
	    {
		edge[p[i].id].push_back(p[i-1].id);
		edge[p[i-1].id].push_back(p[i].id);
	    }

	sort(p+1,p+n+1,cmpy);
	for ( int i = 2 ; i <= n ; i++)
	    if (p[i].y==p[i-1].y)
	    {
		edge[p[i].id].PB(p[i-1].id);
		edge[p[i-1].id].PB(p[i].id);
	    }
	
	ms(vis,false);
	sort(p+1,p+n+1);
	LL ans = 1LL;
	for ( int i = 1 ; i <= n ; i++)if (!vis[i])
	{
	    X.clear();
	    Y.clear();
	    cnt = 0;
	    dfs(i);
	    int sum = X.size() + Y.size();
	    //cout<<"sum:"<<sum<<endl;
	    if (sum<=cnt) ans = ans * ksm(2,sum) % mod;
	    else ans = ans * (ksm(2,sum)-1 + mod) % mod;
	}
	cout<<ans<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
