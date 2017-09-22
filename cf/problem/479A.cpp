/* ***********************************************
Author :111qqz
Created Time :2015年12月11日 星期五 16时00分07秒
File Name :code/cf/problem/479A.cpp
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
int a[5];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>a[1]>>a[2]>>a[3];
	sort(a+1,a+4);
	int ans = 0 ;
	ans = a[1]+a[2]+a[3];
	ans = max(ans,a[1]*a[2]*a[3]);
//	cout<<ans<<endl;
	ans = max(ans,a[1]*(a[2]+a[3]));
	ans = max(ans,(a[1]+a[2])*a[3]);
	ans = max(ans,(a[1]+a[3])*a[2]);
	
	ans = max(ans,a[1]+a[2]*a[3]);
	ans = max(ans,a[1]*a[2]+a[3]);
	ans = max(ans,a[1]*a[3]+a[2]);
	cout<<ans<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
