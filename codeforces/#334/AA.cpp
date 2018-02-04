/* ***********************************************
Author :111qqz
Created Time :2015年12月02日 星期三 00时22分39秒
File Name :code/cf/#334/AA.cpp
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
int w[10];
int m[10];
int s[10];
int s250[10];
int h1,h2;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	
	s[1] = 500;
	s[2] = 1000;
	s[3] = 1500;
	s[4] = 2000;
	s[5] = 2500;
	for ( int i = 1 ; i <= 5 ; i++) scanf("%d",&m[i]);
	for ( int i = 1 ; i <= 5 ; i++) scanf("%d",&w[i]);
	scanf("%d %d",&h1,&h2);
	int ans =  0;
	for ( int i = 1 ; i <= 5 ; i++)
	{
	    ans =ans+max(150*i,i*500-2*i*m[i]-50*w[i]);
	}
	ans = ans + 100*h1;
	ans = ans - 50*h2;
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
