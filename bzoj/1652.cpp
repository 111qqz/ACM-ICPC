/* ***********************************************
Author :111qqz
Created Time :2016年04月11日 星期一 20时46分42秒
File Name :code/bzoj/1652.cpp
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
const int N=2E3+3;
int dp[N][N];//dp[i][j]表示最左边取i,最右边取j的最大值。
int n;
int v[N];
bool vis[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d",&n);
	v[0] = 0 ;
	for ( int i = 1 ; i <= n ; i++) scanf("%d",&v[i]);
	ms(dp,0);

	for ( int k = 1 ; k <= n ; k++) //k是i两段的间隔距离，也可以理解成剩余的长度。k=j-i+1;
	{				//这个划分状态的技巧有点厉害
	    for ( int i = 1 ; i+k-1 <= n  ; i++)
	    {
		int t = n-k+1;
		int j = i+k-1;
//		cout<<"i:"<<i<<" j:"<<j<<" t:"<<t<<endl;
		dp[i][j] = max(dp[i+1][j]+t*v[i],dp[i][j-1]+t*v[j]); //转移是倒着进行的，从内向外
	    }
	}

	printf("%d\n",dp[1][n]);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
