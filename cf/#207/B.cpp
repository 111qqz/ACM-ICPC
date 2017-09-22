/* ***********************************************
Author :111qqz
Created Time :2015年12月23日 星期三 19时47分53秒
File Name :code/cf/#207/B.cpp
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
const int N=1E5+7;
int n ,m;
int color[N];
int v[N][4];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n>>m;
	ms(color,-1);
	ms(v,false);
	for ( int i = 0 ; i < m ; i++)
	{
	    int x,y,z;
	    cin>>x>>y>>z;
	    if (color[x]!=-1)
	    {
		v[i][color[x]] = true;
	    }
	    if (color[y]!=-1)
	    {
		v[i][color[y]] = true;
	    }
	    if (color[z]!=-1)
	    {
		v[i][color[z]] = true;
	    }
	    for ( int j = 1 ; j <=3 ;j++)
	    {
		if (color[x]==-1&&!v[i][j])
		{
		    color[x] = j;
		    v[i][j] = true;
		}
	    }
	    for ( int j = 1 ; j <= 3 ; j++)
	    {
		if (color[y]==-1&&!v[i][j])
		{
		    color[y] = j;
		    v[i][j] = true;
		}
	    }
	    for ( int j = 1 ;  j<= 3 ;  j++)
	    {
		if (color[z]==-1&&!v[i][j])
		{
		    color[z] = j;
		    v[i][j] = true;
		}
	    }
	}
	for ( int i = 1;  i <= n-1 ; i++)
	{
	    printf("%d ",color[i]);
	}
	printf("%d\n",color[n]);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
