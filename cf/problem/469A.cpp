/* ***********************************************
Author :111qqz
Created Time :2015年12月06日 星期日 21时19分58秒
File Name :code/cf/problem/469A.cpp
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
bool vis[N];
int n;
int p;
int q;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n;
	cin>>p;
	ms(vis,false);
	for ( int i = 0 ; i < p ; i++)
	{
	    int x;
	    cin>>x;
	    vis[x] = true;
	}
	cin>>q;
	for ( int i = 0 ; i < q ; i++)
	{
	    int x;
	    cin>>x;
	    vis[x] = true;
	}
	int cnt = 0 ;
	for ( int i = 1 ; i <= n ;i++)
	{
	    if (vis[i]) cnt++;
	}
	if (cnt==n) puts("I become the guy.");
		    else puts("Oh, my keyboard!");

	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
