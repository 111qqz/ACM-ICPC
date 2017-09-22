/* ***********************************************
Author :111qqz
Created Time :2016年08月26日 星期五 21时34分59秒
File Name :code/poj/1384.cpp
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
const int N=505;
const int M=1E4+7;
int  n;
int E,F,V;
int dp[M];
void solve(int cost,int value)
{
    for ( int i = cost ; i <= V ; i++)
	dp[i] = min(dp[i],dp[i-cost]+value);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
        #endif
    
	int T;
	cin>>T;
	while (T--)
	{
	    ms(dp,0x3f);
	    dp[0]= 0 ;
	    scanf("%d%d",&E,&F);
	    V  =  F-E;
	    scanf("%d",&n);
	    for ( int i = 1 ; i <= n ; i++)
	    {
		int x,y;
		scanf("%d %d",&x,&y);
		solve(y,x);

	    }
	    if (dp[V]==inf)
		puts("This is impossible.");
	    else printf("The minimum amount of money in the piggy-bank is %d.\n",dp[V]);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
