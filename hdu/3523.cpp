/* ***********************************************
Author :111qqz
Created Time :2016年06月03日 星期五 19时34分36秒
File Name :code/hdu/3523.cpp
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
int n,m;
int a[N][N];
int w[N][N];

int lx[N],ly[N];
int link[N];
bool visx[N],visy[N];
int slk[N];

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
		link[v] =  u;
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

    int res = 0 ;

    for ( int i = 1 ; i <= n ; i++)
	if (link[i]>-1) res +=w[link[i]][i];

    return -res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	int cas = 0 ;
	cin>>T;
	while (T--)
	{

	    scanf("%d%d",&n,&m);

	    ms(w,0xc0);
	    for ( int i = 1 ; i <= m ; i++)
		for ( int j = 1 ; j <= n ; j++)
		    scanf("%d",&a[i][j]);

	    for ( int i = 1 ; i <= n ; i++) //n个数
	    {
		for ( int j = 1 ; j <= n ; j++)  //n列
		{
		    int sum = 0 ;
		    for ( int k = 1 ; k <= m ; k++)
		    {
			sum+=abs(i-a[k][j]);
//			cout<<"i:"<<i<<" j:"<<j<<" sum:"<<sum<<endl;
		    }
		    w[i][j] = -sum;
		}
	    }
	    
//	    for ( int i = 1 ; i <= n ; i++)
//	    {
//		for ( int j = 1 ; j <= n ; j++) cout<<w[i][j]<<" ";
//
//		cout<<endl;
//	    }
	    int ans = KM();

	    printf("Case #%d: %d\n",++cas,ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
