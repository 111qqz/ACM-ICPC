/* ***********************************************
Author :111qqz
Created Time :2016年06月01日 星期三 16时45分41秒
File Name :code/hdu/1533.cpp
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
char maze[N][N];
int tot1,tot2;
int w[N][N];
int link[N];
bool visx[N],visy[N];
int lx[N],ly[N];
int slk[N];
struct point
{
    int x,y;

    point(){}
    point(int _x,int _y):
	x(_x),y(_y){};

    int dis(point b)
    {
	int res;
	res = abs(x-b.x)+abs(y-b.y);
	return -res;
    }
}p1[N*N],p2[N*N];

void init()
{
    tot1 = tot2 = 0 ;
    ms(w,0xc0); //初始化为负无穷。。。0xc0这个数吼啊。。。和inf的0x3f的绝对值就差1.
   // cout<<"-inf:"<<w[1][1]<<endl;
   // cout<<"inf:"<<inf<<endl;
}

bool find(int u)
{

    visx[u] = true; //不要忘记标记X集合中找过增广路的点。
    for ( int v = 1 ; v <= tot2 ; v++)
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
	}
	else
	    if (tmp<slk[v]) slk[v] = tmp ;
    }
    return false;
}

int KM()
{
    ms(lx,0xc0); //因为所有的权值都是负的（？，所以初始化不能为0而是负无穷。
    ms(ly,0);
    ms(link,-1);
    
    for ( int i = 1 ; i <= tot1 ; i ++)
	for ( int j = 1 ; j <= tot2 ; j++)
	    lx[i] = max(w[i][j],lx[i]);

 //   cout<<"tot1:"<<tot1<<" tot2:"<<tot2<<endl;
    
 //   for ( int i = 1 ; i <= tot1 ; i ++) cout<<"lx[i]:"<<lx[i]<<" ly[i]:"<<ly[i]<<endl;
    for ( int i = 1 ; i <= tot1 ; i++)
    {
	ms(slk,0x3f);

	while (1)
	{
	    ms(visx,false);
	    ms(visy,false);

	    if (find(i)) break;
	    
	    int d = inf;
	    for ( int j = 1 ; j <= tot1 ; j++)
	    {
		if (!visy[j]&&slk[j]<d) d = slk[j];
	    }

	    for ( int j = 1 ; j <= tot1 ; j++) if (visx[j]) lx[j]-=d;
	    for ( int j = 1 ; j <= tot2 ; j++) if (visy[j]) ly[j]+=d;else slk[j]-=d;
	}
    }

    
    int res = 0 ;
    
    for ( int i = 1 ; i <= tot1 ; i ++)
	if (link[i]>-1) res += w[link[i]][i];

    return -res;


}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (scanf("%d%d",&n,&m)!=EOF)
	{
	    if (n==0&&m==0) break;

	    init();
	    for ( int i = 0 ; i < n ; i++) scanf("%s",maze[i]);
	    
	    for ( int i = 0 ; i < n ; i++)
		for ( int j = 0 ; j < m ; j++)
		    if (maze[i][j]=='m') p1[++tot1] = point(i,j);
		    else if (maze[i][j]=='H')p2[++tot2] = point(i,j);

	    for ( int i = 1 ; i <= tot1 ; i ++)
		for ( int j = 1; j <= tot2 ; j++)
		    w[i][j] = p1[i].dis(p2[j]);
	    
	  //  cout<<"wwwwwwwwwwwwW?????"<<endl;
	    int ans = KM();
	  //  cout<<"kkkkkkkkkkkkkkkkk"<<endl;
	    printf("%d\n",ans);

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
