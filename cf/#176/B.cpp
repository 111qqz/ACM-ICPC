/* ***********************************************
Author :111qqz
Created Time :2015年12月16日 星期三 20时14分52秒
File Name :code/cf/#176/B.cpp
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

LL n,k;

void solve()
{

    LL mx = k*(k-1)/2;
    if (n-1>mx) 
    {
	puts("-1");
	return ;
    }
    cout<<(n+k-3)/(k-1)<<endl;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n>>k;
	solve();


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
