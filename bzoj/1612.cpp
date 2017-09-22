/* ***********************************************
Author :111qqz
Created Time :2016年04月02日 星期六 15时20分50秒
File Name :code/bzoj/1612.cpp
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
int d[N][N];
int n,m;

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	cin>>n>>m;
	ms(d,0);
	for ( int i = 1 ;i  <= m ; i++)
	{
	    int u,v;
	    cin>>u>>v;
	    d[u][v]=1;
	    
	}
	
	for ( int k = 1 ; k <= n ; k++)
	    for ( int i = 1 ; i <= n ; i++)
		for ( int j = 1 ; j <= n ; j++)
		    d[i][j] = d[i][j]|(d[i][k]&&d[k][j]);

	int ans = 0 ;
	for ( int i = 1 ;i <= n ; i++)
	{
	    int cnt = 0;
	    for ( int j = 1 ; j <= n ; j++)
	    {
		if (i==j) continue;
		if (d[i][j]||d[j][i]) cnt++;
	    }
	    if (cnt==n-1) ans++;
	}
	printf("%d\n",ans);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
