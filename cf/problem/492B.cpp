/* ***********************************************
Author :111qqz
Created Time :2015年12月13日 星期日 19时06分51秒
File Name :code/cf/problem/492B.cpp
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
const int N=1E3+7;
int n ;
set<int>se;
set<int>::iterator  it;
int  l;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n>>l;
	int mx=0,mi=l;
	for ( int i = 0 ; i < n ; i++)
	{
	    int x;
	    cin>>x;
	    se.insert(x);
	    if (x>mx) mx = x;
	    if (x<mi) mi = x;
	}
	int maxdis = 0 ;
	for ( it = se.begin(); it!=se.end() ;it++)
	{
	    int x1 = *it;
	    it++;
	   // if (it==se.end()) break;
	    int x2 = *it;
	    maxdis = max(maxdis,x2-x1);
	    it--;
	}
	double ans = (maxdis*1.0)/2.0;
	ans = max(ans,mi*1.0);
	ans = max(ans,(l*1.0-mx*1.0));
	printf("%.9f\n",ans);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
