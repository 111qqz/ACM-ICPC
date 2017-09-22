/* ***********************************************
Author :111qqz
Created Time :2016年06月02日 星期四 19时17分19秒
File Name :code/hdu/2813.cpp
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
int n,m,k;
map<string,int>mp,mp2;
int tot1,tot2;
int w[N][N];
int lx[N],ly[N];
int link[N];
bool visx[N],visy[N];
int slk[N];


bool find( int u)
{
    visx[u] = true;
    for ( int v = 1 ; v <= m ; v++)
    {
	if (visy[v]) continue;
	int tmp = lx[u] + ly[v] - w[u][v];
	if (tmp==0)
	{
	    visy[v] = true;
	    if (link[v]==-1||find(link[v]))
	    {
		link[v] = u;
		return true;
	    }
	}else if (tmp<slk[v]) slk[v] = tmp;
    }
    return false;
}
int KM()
{
    ms(lx,0xc0);
    ms(ly,0);
    ms(link,-1);

    for ( int  i = 1 ; i <= n ; i++)
	for ( int j = 1 ; j <= m ; j++)
	    lx[i] = max(lx[i],w[i][j]);
    
  //  for ( int i = 1 ; i <= n ; i++) cout<<"lx[i]:"<<lx[i]<<endl;
    for ( int i = 1; i <= n ; i++)
    {
	ms(slk,0x3f);

	while (1)
	{
	    ms(visx,false);
	    ms(visy,false);
	    
	    if (find(i)) break;

	    int d = inf;
	    
	    for ( int j = 1 ; j <= m ; j++)
		if (!visy[j]&&slk[j]<d) d = slk[j];
	    
	    for ( int j = 1 ; j <= n ; j++) if (visx[j]) lx[j]-=d;
	    for ( int j = 1 ; j <= m ; j++) if (visy[j]) ly[j]+=d; else slk[j]-=d;
	}
    }
    int res  =  0;
    for ( int i = 1 ; i <= m ; i++)
	if (link[i]>-1) res += w[link[i]][i];

    return -res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
//	ios::sync_with_stdio(false);
	while (scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
	    mp.clear();
	    mp2.clear();
	    tot1 = tot2 = 0;
	    ms(w,0xc0);
	    string u,v;
	    char tmpu[25],tmpv[25];
	    int cost;
	    for ( int i = 1 ; i <= k ; i++)
	    {	
		//cin>>u>>v>>cost;
		scanf("%s %s %d",tmpu,tmpv,&cost);
		u = string(tmpu);
		v = string(tmpv);
		if (!mp[u]) mp[u] = ++tot1;
		if (!mp2[v]) mp2[v] = ++tot2;
		w[mp[u]][mp2[v]] = -cost;
	    }

	    int ans = KM();
	    cout<<ans<<endl;
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
