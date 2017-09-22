/* ***********************************************
Author :111qqz
Created Time :2015年12月26日 星期六 20时34分20秒
File Name :code/bc/#67/r1002.cpp
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
const int N=1006;
int n,m;
int a[N][N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%d %d",&n,&m);
	    int cnt = 0 ;
	    for ( int i = 1 ; i <= n ; i++)
		for ( int j = 1 ; j <= m ; j++)
		{
		    scanf("%d",&a[i][j]);
		    if (a[i][j]==0) cnt++;
		}
	    if (cnt%2==0)
	    {
		puts("YES");
	    }
	    else
	    {
		puts("NO");
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
