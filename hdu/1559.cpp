/* ***********************************************
Author :111qqz
Created Time :2016年08月03日 星期三 21时08分18秒
File Name :code/hdu/1559.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
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
const int N=1E3+7;
int a[N][N];
int sum[N][N];
int n,m,x,y;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    ms(sum,0);
	    scanf("%d%d%d%d",&n,&m,&x,&y);
	    for ( int i = 1  ; i <= n ; i++)
		for ( int j = 1 ; j <= m ; j++)
		{
		    scanf("%d",&a[i][j]);
		    sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1] + a[i][j];
		}
	    int ans = 0 ;
	    for ( int i = 1 ; i <= n-x+1 ; i++)
		for ( int j = 1 ; j <= m-y+1 ; j++)
		    ans = max(ans,sum[i+x-1][j+y-1]-sum[i-1][j+y-1]-sum[i+x-1][j-1]+sum[i-1][j-1]);

	    printf("%d\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
