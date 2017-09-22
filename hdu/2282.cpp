/* ***********************************************
Author :111qqz
Created Time :2016年06月01日 星期三 21时12分48秒
File Name :code/hdu/2282.cpp
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
const int N=505;
int n,m;
int p[N]; //p[i]表示第i个巧克力的初始位置。
int a[N];
int lx[N],ly[N];
bool visx[N],visy[N];
int link[N];
int slk[N];
int w[N][N];

void init()
{
    m = 0 ;
    ms(p,-1);
}

int calw(int x,int y)
{
    int res = abs(x-y);
    res = min(res,n-res);
    //cout<<"res:"<<res<<endl;
    return -res;
}

bool find( int u)
{
    visx[u] = true;
    
    for ( int v = 1 ; v <= n ; v++)
    {
	if (visy[v]) continue;
	int tmp = lx[u] + ly[v] - calw(p[u],v);

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

    for ( int i = 1 ; i <= m ; i++)
	for ( int j = 1 ; j <= n ;j++)
	    lx[i] = max(lx[i],calw(p[i],j));
 //   for ( int i = 1 ; i <= m ; i++) cout<<"p[i]:"<<p[i]<<endl;
 //   for ( int i = 1 ; i <= m ; i++) cout<<"lx[i]:"<<lx[i]<<endl;

    for ( int i = 1 ; i <= m ; i++)
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

	    for ( int j = 1 ; j <= m ; j++)
		if (visx[j]) lx[j]-=d;
	    for ( int j = 1 ; j <= n ;j++)
		if (visy[j]) ly[j]+=d ; else slk[j]-=d;
	}
    }
    int res = 0 ;
    for ( int i = 1 ; i <= n ; i++) 
	if (link[i]>-1) res += calw(p[link[i]],i);

    return -res;
	
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	
	while (scanf("%d",&n)!=EOF)
	{

	    init();
	    for ( int i = 1 ; i <= n ;i++)
	    {
		int x;
		scanf("%d",&x);
		a[i] = x;
		while (x--)
		{
		    p[++m] = i;
		}
	    }
	 //   cout<<"sadsada"<<endl;
	    int ans = KM();

	    printf("%d\n",ans);

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
