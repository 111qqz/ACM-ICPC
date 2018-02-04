/* ***********************************************
Author :111qqz
Created Time :2016年02月04日 星期四 02时44分23秒
File Name :code/cf/problem/148D.cpp
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
const int N=1E3+7;
int w,b;
double dp[N][N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>w>>b;
	
	ms(dp,0);
	//dp[i][j]表示有i个白球,j个黑球的时候公主获胜的概率。
	for ( int i = 1 ; i <= w ; i++) dp[i][0] = 1;
	for ( int j = 1 ; j <= b ; j++) dp[0][j]= 0 ; 

	for ( int i = 1 ; i <= w ; i ++)
	{
	    for ( int j = 1 ; j <= b ; j++)
	    {
		double x = i*1.0;
		double y = j*1.0;

		dp[i][j]+=x/(x+y);
		if (j>=3) dp[i][j] +=y/(x+y)*(y-1)/(x+y-1)*(y-2)/(x+y-2)*dp[i][j-3];

		if (j>=2) dp[i][j] +=y/(x+y)*(y-1)/(x+y-1)*(x)/(x+y-2)*dp[i-1][j-2];
	    }
	}
	printf("%.10f\n",dp[w][b]);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
