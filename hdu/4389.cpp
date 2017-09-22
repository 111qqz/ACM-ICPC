/* ***********************************************
Author :111qqz
Created Time :2016年03月18日 星期五 15时10分01秒
File Name :code/hdu/4389.cpp
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
int l,r;
int digit[15];
int dp[15][100][100];


int dfs( int pos,int digsum,int sum ,bool limit)
{
    int mod = -1;
    if (digsum!=0) mod = sum % digsum;
    if (pos==0) return mod==0;
    if (!limit&&mod!=-1&&dp[pos][mod][digsum]!=-1) return dp[pos][mod][digsum];

    int mx = limit?digit[pos]:9;

    int res =  0;
    for  ( int i = 0 ; i <= mx;  i++)
    {
	res += dfs(pos-1,digsum+i,sum*10+i,limit&&i==mx);
    }

    if (!limit)
    {
	if (mod!=-1)
	    dp[pos][mod][digsum] = res;
    }
    return res;
}
int solve ( int n)
{
   if (n==0) return 0;
    int len  = 0;
    ms(digit,0);

    while (n)
    {
	digit[++len] = n % 10;
	n /= 10;
    }

   return dfs(len,0,0,true);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	cin>>T;
	int cas = 0 ;
	ms(dp,-1);
	while (T--)
	{
	    scanf("%d %d\n",&l,&r);
	    int ans = solve (r) - solve (l-1);
	    printf("Case %d: %d\n",++cas,ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
