/* ***********************************************
Author :111qqz
Created Time :2016年06月03日 星期五 03时07分16秒
File Name :code/hdu/2448.cpp
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
int n,m,k,p;
int id[N];
int a[N][N],b[N][N];
int lx[N],ly[N];
int link[N];
bool visx[N],visy[N];
int slk[N];
int w[N][N];

bool find( int u)
{
 //   cout<<"u:"<<u<<endl;
    visx[u] = true;

    for ( int v = 1 ; v <= n ; v++)
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
	}else if(tmp<slk[v]) slk[v] = tmp;
    }
    return false;
}
LL KM()
{
    ms(link,-1);
    ms(lx,0xc0);
    ms(ly,0);

    for ( int i = 1 ; i <= n ; i++)
	for ( int j =  1 ; j <= n ; j++)
	    lx[i] = max(lx[i],w[i][j]);


    for ( int i = 1 ; i <= n ; i++)
    {
	ms(slk,0x3f);

	while (1)
	{
	    ms(visx,false);
	    ms(visy,false);

	    if (find(i)) break;

	    int d = inf;

	    for ( int j = 1 ; j <= n ; j++)
		if (!visy[j]&&slk[j]<d) d = slk[j];

	    for ( int j = 1 ; j <= n ; j++)
		if (visx[j]) lx[j]-=d;
	    for ( int j = 1 ; j <= n ; j++) 
		if (visy[j]) ly[j]+=d ; else slk[j]-=d;
	}
    }
    LL res = 0LL ;

    for ( int i= 1 ; i <= n ; i++)
	if (link[i]>-1) res += LL(w[link[i]][i]);

    return -res;
    
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (scanf("%d%d%d%d",&n,&m,&k,&p)!=EOF)
	{
	    ms(a,0x3f);
	    ms(b,0x3f);
	    ms(id,0);
	    ms(w,0x3f);
	    for ( int i = 1 ;i <= m ; i++) a[i][i] = 0 ;
	    for ( int i = 1 ; i <= n ; i++) scanf("%d",&id[i]);

	    for ( int i = 1 ; i <= k ; i++)
	    {
		int u,v,cost;
		scanf("%d%d%d",&u,&v,&cost);
		//a[u][v] = max(a[u][v],-w);
		a[u][v] = min(a[u][v],cost);
		a[v][u] = min(a[v][u],cost);
	    }

	    for ( int kk = 1 ; kk <= m ; kk++)
		for ( int i = 1 ; i <= m ; i++)
		    for ( int j = 1 ; j <= m ; j++)
			a[i][j] = min(a[i][j],a[i][kk]+a[kk][j]);
	    for ( int i = 1 ; i <= p ; i++)
	    {
		int u,v,cost;
		scanf("%d%d%d",&u,&v,&cost);
		for ( int j = 1 ; j <= n ; j++)
		    w[j][u] = min(w[j][u],a[id[j]][v]+cost); 
		//b[u][v] = max(b[u][v],-w);
		//b[u][v] = min(b[u][v],cost);
		//b[v][u] = min(b[v][u],cost);
	    }


//	    for ( int kk = 1 ; kk <= m ; kk++)  //这只是港口经过中间station到达station的距离近了，还有station经过中间station到达station距离近的情况没考虑,必须放在一起更新。
//		for ( int i = 1 ; i <= n ; i++)
//		    for ( int j = 1 ; j <= m ; j++)
//			if (b[i][kk]+a[kk][j]<b[i][j]) b[i][j] = b[i][kk] + a[kk][j];

	    for ( int i = 1 ; i <= n ; i++)
		for ( int j = 1 ; j <= n ; j++)
		     w[i][j]=-w[i][j];
	    
	    LL ans = KM();
	    printf("%lld\n",ans);


	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
