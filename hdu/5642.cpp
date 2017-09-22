/* ***********************************************
Author :111qqz
Created Time :2016年03月16日 星期三 14时32分09秒
File Name :code/hdu/5642.cpp
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
const LL MOD =1E9+7;
const int N=2E3+3;
LL n;
LL dp[N][27][5];

LL dfs( int pos,int k,int cnt)
{
    if (pos==0) return 1;
    if (dp[pos][k][cnt]!=-1) return dp[pos][k][cnt]%MOD;

    int mx = 26;

    LL res =  0LL;
    for ( int i = 1 ; i <= mx ; i++)
    {
	if (k==i&&cnt==3) continue;
	res = (res + dfs(pos-1,i,i==k?cnt+1:1))%MOD;
    }

    dp[pos][k][cnt] = res%MOD;
    return res%MOD;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	cin>>T;
	ms(dp,-1);
	while (T--)
	{
	    scanf("%lld",&n);
	    ms(dp,-1);
	    LL ans = dfs(n,0,0);

	    cout<<ans<<endl;
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
