/* ***********************************************
Author :111qqz
Created Time :2016年06月02日 星期四 23时37分55秒
File Name :code/hdu/3722.cpp
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
char st[N][1005];
int w[N][N];
int link[N];
int lx[N],ly[N];
bool visx[N],visy[N];
int slk[N];
int solve(string a,string b)
{
    int la = a.length();
    int lb = b.length();
    int len = min(la,lb);
    int res = 0 ;
    for ( int i = 0 ; i < len ; i++)
    {
	if (b[i]==a[la-1-i]) res++;
	else break;
    }
    return res;
}

bool find( int u)
{
   // cout<<"u:"<<u<<endl;
    visx[u] = true;
    for ( int v  = 1 ; v <= n ; v++)
    {
	if (visy[v]) continue;

	int tmp = lx[u] + ly[v] - w[u][v];
	if (tmp==0)
	{
	    visy[v] = true;
	    if (link[v]==-1||find(link[v]))
	    {
		link[v] = u ;
		return true;
	    }	
	}else if (tmp<slk[v]) slk[v] = tmp;
    }
    return false;
}
int KM()
{
    ms(lx,0);
    ms(ly,0);
    ms(link,-1);

    for ( int i = 1 ; i <= n ; i++)
	for  ( int j = 1 ; j <= n ; j++ )
	    lx[i] = max(lx[i],w[i][j]);

    for ( int i = 1; i <= n ; i++)
    {
	ms(slk,0x3f);

	while (1)
	{
	    ms(visx,false);
	    ms(visy,false);

	    if (find(i)) break;

	    int d = inf;

	    for ( int j = 1 ; j <= n ; j++)
		if (!visy[j]&&slk[j]<d) d= slk[j];

	    for ( int j = 1 ; j <= n ; j++)
		if (visx[j]) lx[j]-=d;

	    for ( int j = 1 ; j <= n ; j++)
		if (visy[j]) ly[j]+=d ; else slk[j]-=d;
	}
    }
    int res = 0 ;
    for ( int i = 1 ; i <= n ; i++)
	if (link[i]>-1) res += w[link[i]][i];

    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%d",&n))
	{
	    for ( int i = 1 ; i <= n ; i++) scanf("%s",st[i]);
	    
	    ms(w,0);

	    for ( int i = 1 ; i <= n ; i++)
		for ( int j = 1 ; j <= n ; j++)
		    if (i!=j) w[i][j] = solve(string(st[i]),string(st[j]));

	 //   for ( int i = 1 ; i <= n ; i++)
	//	for ( int j = 1 ; j <= n ; j++) if (i!=j) cout<<"w[i][j]:"<<w[i][j]<<endl;
		
	    int ans = KM();
	    printf("%d\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
