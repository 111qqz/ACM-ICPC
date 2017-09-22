/* ***********************************************
Author :111qqz
Created Time :2015年12月22日 星期二 16时28分59秒
File Name :code/cf/#333/C.cpp
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
const int N=4E2+7;
int n ,m;
int road[N][N];
int rail[N][N];

int floyd()
{
    for ( int k = 1 ; k <= n ; k++)
	for ( int i = 1 ; i <= n ; i++)
	    for ( int j = 1 ; j <= n ; j++)
		if (rail[i][j]>rail[i][k]+rail[k][j]) rail[i][j] = rail[i][k] + rail[k][j];
    if (rail[1][n]==inf) return -1;
	else return rail[1][n];
}

int floyd2()
{
    for ( int k = 1 ; k <= n ; k++)
	for ( int i =1 ;  i <= n ; i++)
	    for ( int j = 1 ; j <= n ;j++)
		road[i][j] = min(road[i][j],road[i][k]+road[k][j]);
    if (road[1][n]==inf) return -1;
	else return road[1][n];

}

void init()
{
  //  for ( int i = 0 ; i <= 400 ; i++)
//	for ( int j = 0 ; j <= 400 ; j ++)
//	{
//	    rail[i][j] = 99999;
//	    road[i][j]=  99999;
//	}
    ms(rail,0x3f);
    ms(road,0x3f);
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n>>m;
	init();
//	cout<<road[1]<<inf<<endl;
	for ( int i = 0 ; i < m ; i++)
	{
	    int u,v;
	    scanf("%d %d",&u,&v);
	    rail[u][v] = 1;
	    rail[v][u] = 1;
	}
	
	for ( int i = 1 ; i <= n-1 ; i++)
	{
	    for ( int j = i+1 ; j <= n ; j++)
	    {
	//	cout<<"aaaa?"<<endl;
		if (rail[i][j]==inf)
		{
		    road[i][j] = 1;
		    road[j][i] = 1;
		}
	    }
	}
	int ans;
	if (rail[1][n]==1)
	{
	    ans = floyd2();
	    cout<<ans<<endl;
	}
	else
	{
	    
	 //   cout<<"aaa?"<<endl;
	    ans = floyd();
	    cout<<ans<<endl;
	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
