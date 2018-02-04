/* ***********************************************
Author :111qqz
Created Time :2015年12月06日 星期日 21时28分14秒
File Name :code/cf/problem/405A.cpp
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



using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=105;
int n;
int a[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n;
	for ( int i = 0 ; i< n ; i++) cin>>a[i];
	sort(a,a+n);
	for ( int i = 0 ; i < n ; i++) cout<<a[i]<<" ";

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
