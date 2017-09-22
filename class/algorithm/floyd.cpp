/* ***********************************************
Author :111qqz
Created Time :2016年03月29日 星期二 21时50分59秒
File Name :code/class/algorithm/floyd.cpp
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
int n,m;
int d[20][20];

void floyd()
{
    for ( int k = 1 ; k <= n ; k++)
	for ( int i = 1 ; i  <= n ; i++)
	    for ( int j = 1 ; j <= n ; j++)
		d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/class/algorithm/in1.txt","r",stdin);
  #endif
	
	cin>>n>>m;
	ms(d,0x3f);
	for ( int i = 1 ; i <= m ; i++)
	{
	    int u,v,cost;
	    cin>>u>>v>>cost;
	    d[u][v] = cost;
	}

	floyd();
	for ( int i = 1; i  <= n ; i++)
	{

	    for ( int j = 1 ; j<= n ; j++)
	    {
		printf("%d ",d[i][j]);
	    }
	    printf("\n");
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
