/* ***********************************************
Author :111qqz
Created Time :2015年12月25日 星期五 18时17分05秒
File Name :code/cf/problem/455A.cpp
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
const int N=1E5+7;
int n ;
int a[N];
LL cnt[N];
LL dp[N];

bool cmp( int a,int b)
{
    return a>b;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	ms(cnt,0);
	for ( int i = 0 ; i < n ; i++)
	{
	    scanf("%d",&a[i]);
	    cnt[a[i]]++;
	}

	dp[0] = 0 ;  //dp[i]表示到数字i时能得到的最多分数
	dp[1] = cnt[1];
	for ( int i = 2 ; i <= 1E5 ; i++)
	{
	    dp[i] = max(dp[i-1],dp[i-2]+i*cnt[i]);
	}
	cout<<dp[100000]<<endl;
	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
