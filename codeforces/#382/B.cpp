/* ***********************************************
Author :111qqz
Created Time :2016年11月29日 星期二 10时16分46秒
File Name :code/cf/#382/B.cpp
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
LL a[N];
int n,n1,n2;
bool cmp( LL x,LL y)
{
    return x>y;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n>>n1>>n2;
	for ( int i = 1; i <= n ;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	if (n1>n2) swap(n1,n2);
	double ans = 0 ;
	LL sum = 0 ;
	for ( int i = 1 ; i <= n1 ; i++) sum = sum + a[i];
	ans = sum*1.0/n1;
	sum = 0 ;
	for ( int i =n1+1 ; i<= n1+n2 ; i++) sum = sum + a[i];
	ans = ans + sum*1.0/n2;
	printf("%.8f\n",ans);
	


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
