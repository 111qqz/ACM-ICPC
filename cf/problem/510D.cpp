/* ***********************************************
Author :111qqz
Created Time :2016年02月05日 星期五 16时53分48秒
File Name :code/cf/problem/510D.cpp
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
const int N=103;
double dp[N][N][N];
int r,s,p;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>r>>s>>p;

	ms(dp,0);
	dp[r][s][p] = 1.0;  //dp[i][j][k]表示出现有i个石头，s个剪刀，p个布的状态的概率。
	for ( int i = r;  i >= 0  ; i--)
	    for ( int j = s  ; j >=0 ; j-- )
		for ( int k = p ; k >=0 ; k-- )
		{
		    double total = i*j*1.0+j*k*1.0+k*i*1.0;
		    if (total==0) continue;
		    if (i>0)
		    dp[i-1][j][k] += i*k*1.0*dp[i][j][k]/total;
		    if (j>0)
		    dp[i][j-1][k] +=i*j*1.0*dp[i][j][k]/total;
		    if (k>0)
		    dp[i][j][k-1] +=j*k*1.0*dp[i][j][k]/total;
		}



	
	double p1=0,p2=0,p3= 0;

	for ( int i = 1 ; i <= r;  i++) p1+=dp[i][0][0];
	for ( int j = 1 ; j <= s ; j++) p2+=dp[0][j][0];
	for ( int k = 1 ; k <= p ; k++) p3+=dp[0][0][k];

	printf("%.12f %.12f %.12f\n",p1,p2,p3);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
