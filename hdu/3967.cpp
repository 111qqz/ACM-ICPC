/* ***********************************************
Author :111qqz
Created Time :Thu 29 Sep 2016 02:49:50 PM CST
File Name :code/hdu/3967.cpp
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
int k;
LL l,r;
int digit[20];
LL dp[20][20][20][20][2];
LL dfs( int pos,LL sum1,LL sum2,bool limit,int cut,int prehasnonzero)
{
    if (pos==0) return (sum1+sum2)%k==0;
    if (!limit&&dp[pos][sum1%k][sum2%k][cut][prehasnonzero]!=-1) return dp[pos][sum1%k][sum2%k][cut][prehasnonzero];
    int mx = limit?digit[pos]:9;
    LL res = 0 ;
    for ( int i = 0 ; i <= mx;  i++)
    {
	if (pos<cut) res = res + dfs(pos-1,sum1,sum2*10+i,limit&&i==mx,cut,prehasnonzero||i!=0);
	else
	{
	    if (!prehasnonzero&&pos==cut&&i==0) continue; //前半部分可以有前导0，但是不能全为0.
	    res = res + dfs(pos-1,sum1*10+i,sum2,limit&&i==mx,cut,prehasnonzero||i!=0);
	}
    }
    if (!limit) dp[pos][sum1%k][sum2%k][cut][prehasnonzero] = res;
    return res;
}
LL solve( LL n)
{
  //  if (n<10) return 0;
    ms(digit,0);
    int len = 0 ;
    ms(dp,-1);// 每次计算的时候都要初始化dp。。。因为d不一样。。。。。。
    while (n)
    {
	digit[++len] = n % 10;
	n /= 10;
    }
    LL res = 0 ;
    for ( int i = 2 ; i  <= len ; i++)
	res = res + dfs(len,0,0,true,i,0);
   // cout<<"res:"<<res<<endl;
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%lld%lld%d",&l,&r,&k))
	{
	    LL ans = solve(r) - solve(l-1);
	    printf("%lld\n",ans);
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
