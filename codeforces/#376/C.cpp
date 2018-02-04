/* ***********************************************
Author :111qqz
Created Time :Sun 16 Oct 2016 05:43:06 PM CST
File Name :code/cf/#376/C.cpp
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
const int N = 2E5 + 7 ;
int n,m,k;
int c[N];
pi a[N];
int f[N];
int cnt[N];
set<int>se[N];
set<int>id;
void init()
{
    for ( int i = 1 ; i < N ; i ++) f[i] = i;
}
int root ( int x)
{
    if (x!=f[x]) f[x] = root (f[x]);
    return f[x];
}
void merge( int x,int y)
{
    int rx = root(x);
    int ry = root(y);
    if (rx==ry) return ;
    f[rx] = ry;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n>>m>>k;
	ms(cnt,0);
	init();
	for ( int i = 1 ; i <= n ; i++) scanf("%d",&c[i]);
	for ( int i = 1 ; i <= m ; i++) 
	{
	    scanf("%d %d",&a[i].fst,&a[i].sec);
	    int x = a[i].fst;
	    int y = a[i].sec;
	    cnt[x]++;
	    cnt[y]++;
	    if (root(x)!=root(y)) merge(x,y);
	}

	for ( int i = 1 ; i <= n ; i++)
	{
	    int x = root(i);
	    id.insert(x);
	    se[x].insert(i);
	}

	LL ans = 0 ;
	for ( auto it = id.begin() ; it != id.end() ;it++)
	{
	    int tmp = * it;
	    int mx = -1;
	    int mxid = 0;
	    for ( auto it2 = se[tmp].begin() ; it2!=se[tmp].end() ; it2++)
	    {
		int tmp2 = * it2;
		if (cnt[tmp2]>mx)
		{
		    mx = cnt[tmp2];
		    mxid = tmp2;
		}
	    }
	    for ( auto it2 = se[tmp].begin() ; it2!=se[tmp].end() ; it2++)
	    {
		int tmp2 = * it2;
		if (c[tmp2]==c[mxid]) continue;
		ans = ans + 1LL*cnt[tmp2];
		cnt[tmp2] = 0 ;
	    }
	}
	cout<<ans<<endl;

	


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
