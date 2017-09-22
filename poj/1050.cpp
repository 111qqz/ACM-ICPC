/* ***********************************************
Author :111qqz
Created Time :2016年05月19日 星期四 20时09分14秒
File Name :code/poj/1050.cpp
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
int n;
int a[N][N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d",&n);
	for ( int i = 1 ; i <= n ; i++)
	    for ( int j = 1 ; j <= n ; j++) scanf("%d",&a[i][j]);

	int lst = 0 ;
	int ans = -inf;
	for ( int i = 1 ; i <= n ;  i++)
	{
	    lst = 0 ;
	    ans = -inf;
	    for ( int j = 1 ; j  <= n ; j++)
	    {
		lst = max(0,lst) + a[i][j];
		ans  = max(ans,lst);
	    }
	}
	printf("%d\n",ans);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
