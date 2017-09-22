/* ***********************************************
Author :111qqz
Created Time :2015年12月01日 星期二 23时20分45秒
File Name :code/cf/#334/A.cpp
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
const int N=10;
int m[N];
int w[10];
int hs,hu;
int s[10]={500,1000,1500,2000,2500};
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	for ( int i = 0 ; i < 5 ; i++) scanf("%d",&m[i]);
	for ( int i = 0 ; i < 5 ; i++) scanf("%d",&w[i]);
	scanf("%d %d",&hs,&hu);
	int ans = 0 ;
	for ( int i = 0 ; i < 5 ; i++)
	{
	    ans = ans +max(s[i]*3/10,s[i]-m[i]*s[i]/250-50*w[i]);
	}
	ans = ans + hs*100;
	ans = ans - hu*50;

	cout<<ans<<endl;




  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
