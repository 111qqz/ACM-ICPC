/* ***********************************************
Author :111qqz
Created Time :Tue 13 Sep 2016 05:13:15 PM CST
File Name :code/loj/1045.cpp
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
const int N=1E6+7;
int n;
int base;
double sum[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	sum[0] = 0 ;
	for ( int i = 1 ; i < N ; i++) sum[i] = sum[i-1] + log(i);
	int T;
	cin>>T;
	int cas = 0 ;
	while (T--)
	{
	    scanf("%d%d",&n,&base);
	    double ans = sum[n]/log(base)+1;
	    printf("Case %d: %d\n",++cas,int(ans));
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
