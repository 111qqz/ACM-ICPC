/* ***********************************************
Author :111qqz
Created Time :2016年06月03日 星期五 14时35分46秒
File Name :code/hdu/2853.cpp
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
const int N = 55;
int n,m;
int w[N][N];
int id[N];
int lx[N],ly[N];
int link[N];
bool visx[N],visy[N];
int slk[N];
int num;

bool find( int u)
{
    visx[u] = true;

    for ( int v = 1 ; v <= m ;v++)
    {
	if(visy[v]) continue;
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

    for ( int i = 1 ; i <= n ; i++)
	for ( int j = 1 ; j <= m ; j++)
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

	    for ( int j = 1 ; j <= m ; j++)
		if (!visy[j]&&slk[j]<d) d = slk[j];

	    for ( int j = 1 ; j <= n ; j++)
		if (visx[j])  lx[j]-=d;

	    for ( int j = 1 ; j <= m ; j++)
		if (visy[j]) ly[j]+=d; else slk[j]-=d;
	}
    }

    int res = 0 ;
    for ( int i = 1 ; i <= m ; i++)
	if (link[i]>-1)
	{
	    res = res + w[link[i]][i]/N;
	    num = num + w[link[i]][i];
	}

//    cout<<"num:"<<num<<endl;
    num%=N;

    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cout<<-21%5<<endl;
	while (scanf("%d%d",&n,&m)!=EOF)
	{

	    ms(w,0);
	    num = 0 ;
	    for ( int i = 1 ; i <= n ; i++)
		for ( int j = 1 ; j <= m ; j++)
		    scanf("%d",&w[i][j]),w[i][j]*=N;
	    
	    int sum = 0;
	    for ( int i  = 1 ; i <= n ; i++)
	    {
		scanf("%d ",&id[i]);
		sum = sum + w[i][id[i]]/N;
		w[i][id[i]]++; //太神了。
	    }
	    
	    int ans = KM();

	    printf("%d %d\n",n-num,ans-sum);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
