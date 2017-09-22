/* ***********************************************
Author :111qqz
Created Time :2015年12月17日 星期四 21时31分05秒
File Name :code/poj/3660.cpp
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
int n ,m;
int v[N][N];


void init()
{
    for ( int i = 0 ; i <= 100 ; i++)
	for ( int j = 0; j <= 100 ; j++)
	    v[i][j]=i==j?1:0;
}

void floyd()
{
    for (int  k = 1 ; k <= n ; k++)
	for ( int i = 1 ; i <= n ; i++)
	    for ( int j = 1 ; j <= n;  j++)
		v[i][j] = v[i][j]||(v[i][k]&&v[k][j]);
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d %d",&n,&m);
	while (m--)
	{
	    int x,y;
	    scanf("%d %d",&x,&y);
	    v[x][y] = 1;
	}
	
	floyd();


	int ans = 0;
	for ( int i =1 ; i <= n;  i++)
	{
	    int cnt = 0 ; 
	    for ( int j = 1 ; j <= n ;j++)
	    {
		if (i==j) continue;
		if (v[i][j]||v[j][i])
		    cnt++;
	    }
	    if (cnt==n-1) ans++;
	}
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
