/* ***********************************************
Author :111qqz
Created Time :2016年01月23日 星期六 23时35分25秒
File Name :code/cf/#340/A.cpp
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
int x;
int ans;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>x;
	ans = 0 ;
	for ( int i = 5 ; i >=1 ; i--)
	{
	    ans =ans + x/i;
	    x = x % i ;
	}
	cout<<ans<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
