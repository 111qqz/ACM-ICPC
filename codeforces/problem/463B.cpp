/* ***********************************************
Author :111qqz
Created Time :2015年12月16日 星期三 16时40分57秒
File Name :code/cf/problem/463B.cpp
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
int h[N];
int cur;
int ans;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n;
	h[0] = 0  ;
	for ( int i = 1 ; i <= n ; i++) scanf("%d",&h[i]);

	cur  = 0;
	ans = 0 ;
	for ( int i = 0 ; i <= n-1 ; i++)
	{
	    int delta = h[i]-h[i+1];
	    if (cur+delta>=0)
	    {
		cur +=delta;
	    }
	    else
	    {
		ans+=abs(cur+delta);
		cur = 0 ;

	    }
	}
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
