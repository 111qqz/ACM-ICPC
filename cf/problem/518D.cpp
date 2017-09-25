/* ***********************************************
Author :111qqz
Created Time :2016年02月02日 星期二 15时57分06秒
File Name :code/cf/518D.cpp
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
const int N=2E3+7;
int n,t;
double p;
double dp[N][N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ms(dp,0);
	dp[0][0] = 1;
	cin>>n>>p>>t;
	for ( int i = 0 ; i <= t ; i++)
	{
	    for ( int j = 0 ; j <= n ; j++)
	    {
		if (j==n)
		{
		    dp[i+1][j]+=dp[i][j];
		}
		else
		{
		    dp[i+1][j+1]+=dp[i][j]*p;
		    dp[i+1][j]+=dp[i][j]*(1-p);
		}
	    }
	}
	double ans = 0 ;
	for ( int j = 1 ; j <= n ; j++)
	    ans +=j*dp[t][j];
	
	printf("%.12f\n",ans);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
