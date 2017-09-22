/* ***********************************************
Author :111qqz
Created Time :2016年11月18日 星期五 17时07分23秒
File Name :code/bzoj/2013.cpp
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
const int N=7E5+7;
int n,d;
const int mod = 1E9+7;
int a[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n>>d;
	for ( int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);
	LL ans = 1LL,id;
	sort(a+1,a+n+1);
	for ( int i = 1 ; i  <= n ; i++) id = lower_bound(a+1,a+i,a[i]-d)-a,ans = ans*(i-id+1)%mod;
	printf("%lld\n",ans);


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
