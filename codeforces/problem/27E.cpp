/* ***********************************************
Author :111qqz
Created Time :Wed 21 Sep 2016 04:48:42 PM CST
File Name :code/cf/problem/27E.cpp
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
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int n;
LL ans = 1LL<<60;
void dfs( int depth,LL val,int num)
{
    if (num>n) return;
    if (num==n&&val<ans) ans = val;
    for ( int i = 1 ; i <=63 ; i++) //最多63个质数。。。因为2^64>1E18
    {
	if (val*prime[depth]>ans) break;
	dfs(depth+1,val*=prime[depth],num*(i+1));
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n;
	dfs(0,1,1);
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
