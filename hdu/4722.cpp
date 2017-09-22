/* ***********************************************
Author :111qqz
Created Time :2016年03月16日 星期三 08时10分19秒
File Name :code/hdu/4722.cpp
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
LL l,r;
int  digit[30];
LL dp[30][15];


LL dfs ( int pos,int sum,bool limit)
{
    if (pos==0)
    {
	if (sum==0) return 1;
	else return 0;
    }
    if (!limit&&dp[pos][sum]!=-1) return dp[pos][sum];

    int mx = limit?digit[pos]:9;

    LL res = 0 ;
    for ( int i = 0 ; i <= mx; i ++)
    {
	res+=dfs(pos-1,(sum+i)%10,limit&&i==mx);
    }

    if (!limit) dp[pos][sum] = res;
    
    return res;

}
LL solve ( LL n)
{
//    if (n==0) return 1;
  //  if (n<=9) return 0;
    if (n<0) return 0;
    ms(digit,0);
    int len =  0 ;
    while (n)
    {
	digit[++len] = n % 10;
	n /= 10;
    }
    
    return dfs(len,0,true);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
//	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	ms(dp,-1);
	int cas = 0 ; 
	while (T--)
	{
	    scanf("%lld %lld",&l,&r);
	    LL ans = solve (r)-solve(l-1);

	    printf("Case #%d: %lld\n",++cas,ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
