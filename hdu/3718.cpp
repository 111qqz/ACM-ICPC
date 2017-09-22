/* ***********************************************
Author :111qqz
Created Time :2016年06月03日 星期五 01时32分27秒
File Name :code/hdu/3718.cpp
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
const int N=1E4+7;
int n,k,m;
char a[35][N];
int w[35][35];
map<char,int>mp1,mp2;
int tot1,tot2;
int lx[35],ly[35];
bool visx[35],visy[35];
int link[35];
int slk[35];


bool find( int u)
{
    visx[u] = true;
    for ( int v = 1 ; v <= k ; v++)
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
    ms(lx,0);
    ms(ly,0);

    for ( int i = 1 ; i <= tot2 ; i++)
	for ( int j = 1 ; j <= k ; j++)
	    lx[i] = max(lx[i],w[i][j]);

    for ( int i = 1 ; i <= tot2 ; i++)
    {
	ms(slk,0x3f);

	while (1)
	{
	    ms(visx,false);
	    ms(visy,false);

	    if (find(i)) break;

	    int d = inf;

	    for ( int j = 1 ;j <= k ; j++) 
		if (!visy[j]&&slk[j]<d) d = slk[j];

	    for ( int j = 1 ; j <= tot2 ; j++)
		if (visx[j]) lx[j]-=d;
	    for ( int j = 1; j <= k ; j++)
		if (visy[j]) ly[j]+=d; else slk[j]-=d;
	}
    }
    int res = 0 ;
    for ( int i = 1 ;  i <= k  ; i++)
	if (link[i]>-1) res += w[link[i]][i];
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	cin>>T;
	while (T--)
	{
	    ms(w,0);
	    mp1.clear();
	    mp2.clear();
	    tot1 = 0 ;
	    tot2 = 0 ;
	    scanf("%d%d%d",&n,&k,&m);
	    getchar();
	    for ( int i = 0 ; i <= m ; i++)
	    {
		for ( int j = 1 ; j <= n ; j++)
		    scanf(" %c",&a[i][j]);
		getchar();

	//	for ( int j = 1 ; j <= n ; j++) cout<<a[i][j]<<" ";

	//	cout<<endl;
	    }
	    
	    for ( int i = 1 ; i <= n ; i++) if (!mp1[a[0][i]]) mp1[a[0][i]]=++tot1;
	    
	    for ( int i = 1;  i <= m ; i++)
	    {
		ms(w,0);
		tot2 = 0 ;
		mp2.clear();

		for ( int j = 1 ; j <= n ; j++) if (!mp2[a[i][j]]) mp2[a[i][j]] = ++tot2;

		for ( int j =  1; j <= n ; j++) 
		{
		    int u = mp1[a[0][j]];
		    int v = mp2[a[i][j]];
		    w[v][u]++;
		}

		int ret = KM();
		double ans;
		ans = ret*1.0/(n*1.0);
		printf("%.4f\n",ans);
	    }

	    

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
