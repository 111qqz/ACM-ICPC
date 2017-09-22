/* ***********************************************
Author :111qqz
Created Time :2016年06月03日 星期五 15时46分12秒
File Name :code/hdu/3315.cpp
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
const int N=105;
int n;
int val[N];
int h[N],p[N],a[N],b[N];
int win[N][N];
int w[N][N];
int lx[N],ly[N];
bool visx[N],visy[N];
int link[N];
int slk[N];
int num;


bool find( int u)
{
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
	}else if (tmp<slk[v]) slk[v] = tmp;
    }

    return false;
}

int KM()
{
    ms(link,-1);
    ms(lx,0xc0);
    ms(ly,0);

    for ( int i = 1 ; i <= n ; i++)
	for ( int j = 1 ; j <= n ; j++)
	    lx[i] = max(lx[i],w[i][j]);

    for ( int i = 1 ; i <= n ; i++)
    {
	ms(slk,0x3f);

	while(1)
	{
	    ms(visx,false);
	    ms(visy,false);

	    if (find(i)) break;

	    int d = inf;

	    for ( int j = 1 ; j <= n ; j++)
		if (!visy[j]&&slk[j]<d)  d = slk[j];

	    for ( int j = 1 ; j <= n ; j++)
		if (visx[j]) lx[j]-=d;
	    for ( int j = 1 ; j <= n ; j++)
		if (visy[j]) ly[j]+=d; else slk[j]-=d;
	}
    }

    for ( int i = 1 ; i <= n ; i++)
    {
	if (link[i]>-1)
	{
	    num = num + (link[i]==i);
	}
    }
   // cout<<"num:"<<num<<endl;
    //num%=N;
  //  cout<<"num:"<<num<<endl;
    int res = 0 ;
    for ( int i = 1 ; i <= n ; i++)
    {
	if (link[i]>-1)
	{
	    if (w[link[i]][i]>0) res = res + w[link[i]][i]/N;
	    else res = res + (w[link[i]][i]-2)/N; //???
	}
    }

    return res;


}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (scanf("%d",&n)!=EOF)
	{
	    if (n==0) break;
	    ms(w,0xc0);
	    ms(win,0);
	    num =  0;
	    for ( int i = 1 ; i <= n ; i++) scanf("%d",&val[i]);
	    for ( int i = 1 ; i <= n ; i++) scanf("%d",&h[i]);
	    for ( int i = 1 ; i <= n ; i++) scanf("%d",&p[i]);
	    for ( int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);
	    for ( int i = 1 ; i <= n ; i++) scanf("%d",&b[i]);

	    for ( int i = 1 ;i <= n ;i++)
		for  (int j  = 1 ; j <= n ; j++)
		{
		    win[i][j] = (h[i]+b[j]-1)/b[j]+1>(p[j]+a[i]-1)/a[i]?1:-1;
		}


	    for ( int i = 1 ;i <= n ; i++)
		for ( int j = 1 ;j  <= n ; j++)
		    w[i][j] = win[i][j]*val[i]*N;

	    for ( int i = 1; i <= n ; i++) w[i][i]++;

	    int ans = KM();
	    if (ans<=0)
	    {
		puts("Oh, I lose my dear seaco!");
	    }
	    else
	    {
		double ret = num*1.0/(n*1.0);
		ret = ret * 100.0;
		printf("%d %.3f%%\n",ans,ret);
	    }


	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
