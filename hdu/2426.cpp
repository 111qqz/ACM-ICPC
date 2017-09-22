/* ***********************************************
Author :111qqz
Created Time :2016年06月01日 星期三 19时35分04秒
File Name :code/hdu/2426.cpp
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
int n,m,e;
int w[N][N];
int link[N];
int lx[N],ly[N];
bool visx[N],visy[N];
int slk[N];

void init()
{
    ms(w,0xc0);
}


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
		link[v] = u ;
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

    for ( int i = 1 ; i <= n ; i++)
	for ( int j = 1 ; j <= m ; j++)
	    lx[i] = max(lx[i],w[i][j]);

    for ( int i = 1 ; i <= n ; i++) if (lx[i]==-inf-1) return -1; 

    for ( int i = 1 ; i <= n ; i++)
    {
	ms(slk,0x3f);

	while (true)
	{
	    ms(visx,false);
	    ms(visy,false);

	    if (find(i)) break;

	    int d = inf;

	    for ( int j = 1 ; j <= m ; j++)
		if (!visy[j]&&slk[j]<d) d = slk[j];
	   // cout<<"d:"<<d<<endl;

	    for ( int j = 1 ; j <= n ; j++)
		if (visx[j]) lx[j]-=d;
	    for ( int j = 1 ;j  <= m ; j++)
		if (visy[j]) ly[j]+=d; else slk[j]-=d;

	}
    }

    int res = 0 ;
    for ( int i = 1 ; i <= m ; i++)
	if (link[i]>-1) res += w[link[i]][i];
    
 //   if (res<-5E8) res = -1;
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	string kong;
	int cas = 0 ;
	while (scanf("%d%d%d",&n,&m,&e)!=EOF)
	{

	    init();
	    for ( int i = 1 ; i <= e ; i++)
	    {
		int u,v,cost;
		scanf("%d%d%d",&u,&v,&cost);
		u++;
		v++;
		if (cost<0) continue;//? mdzz，读漏了。。喜欢程度为负是不能住的。
		w[u][v] = cost;
	    }
	    
	    printf("Case %d: ",++cas);
	    if (n>m)  //学生比房间数多。
	    {
		puts("-1");
		continue;
	    }

	    int ans = KM();
	    printf("%d\n",ans);
	    getline(cin,kong);
	    cout<<" kong:"<<kong<<endl;
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
