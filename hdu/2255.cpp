/* ***********************************************
Author :111qqz
Created Time :2016年06月01日 星期三 11时23分42秒
File Name :code/hdu/2255.cpp
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
const int N=305;
int w[N][N];
int n;
int link[N];
int lx[N],ly[N];//顶标
int slk[N]; //slk为一个优化函数，表示在DFS增广过程中，所有搜到的与该Y方点关联的边的(lx+ly-W)的最小值
bool visx[N],visy[N];
bool find( int u)
{
    visx[u] = true;
    for ( int v = 1 ; v <= n ; v++) //这道题特殊：每两个点都有边相连。
    {				    //对于有些题目中可能两个集合某些点没有边相连，我们可以看作有权值为0的边。
	if (visy[v]) continue;  
	int tmp = lx[u] + ly[v] - w[u][v]; //要时刻保证tmp>=0，并称一样一组点标为可行的。
//	cout<<"tmp:"<<tmp<<endl;
	if (tmp==0) 
	{
	    visy[v] = true;
	    if (link[v]==-1||find(link[v]))
	    {
	//	cout<<"link[v]:"<<link[v]<<endl;
		link[v] = u;
		return true;
	    }
	}
	else
	    if (tmp<slk[v]) slk[v] = tmp; //顺便（？）更新slk
    }
    return false;
}
int KM()
{
    
    ms(link,-1);//初始没有找到匹配，同hungary
    ms(ly,0);
    ms(lx,0);//因为要使得所有lx[i]+ly[j]-w[i][j]>=0,所以初始化的时候（不妨）lx[i]=max(w[i][j]),ly[i]=0;
    for ( int i = 1 ;  i <= n ; i++)
	for ( int j = 1 ; j <= n ; j++)
	    lx[i] = max(w[i][j],lx[i]);


    for ( int i =  1 ; i <= n ; i++)
    {
//	ms(slk,0x3f);
	for ( int j = 1 ; j <= n ; j++) slk[j] = inf;
	while (true)
	{
	 //   cout<<"mio mio mio "<<endl;
	    ms(visx,false);
	    ms(visy,false);
	    
	    if (find(i)) break;
	    int d = inf;
	    for ( int j = 1 ; j <= n ; j++)
	    {
		if (!visy[j]&&slk[j]<d) d= slk[j]; //d取所有slk值的最小值。
						    //这样有两个作用，一个是可以保证所有所有【点标对】仍然可行。
						    //另一个是这样的d每次都可以增加一条<可行边>进入相等子图。
	    }

	    for (int j = 1 ; j <= n ; j++) if (visx[j]) lx[j]-=d;
	    for (int j = 1 ; j <= n ; j++) if (visy[j]) ly[j]+=d;else slk[j]-=d;
	}
    }

    int res = 0 ;
    for ( int i = 1 ; i <= n ; i++)
    {
	if (link[i]>-1)
	{
	    res += w[link[i]][i];
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
	    for ( int i = 1 ; i <= n ; i++)
		for ( int j = 1 ; j <= n ; j++) 
		    scanf("%d",&w[i][j]);
	    int ans = KM();
	    printf("%d\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
