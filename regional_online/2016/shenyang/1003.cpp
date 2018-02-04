/* ***********************************************
Author :111qqz
Created Time :Sun 18 Sep 2016 04:04:28 PM CST
File Name :code/net/2016/shenyang/1003.cpp
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
LL cal(LL x,LL y)
{
    return jc[x+y-1]*ny[x]%mod*ny[y-1]%mod;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
