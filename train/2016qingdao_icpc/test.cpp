/* ***********************************************
Author :111qqz
Created Time :2017年10月13日 星期五 20时53分01秒
File Name :test.cpp
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
#define PB push_back
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
const int N=1E6+7;
int F[N];
void get_fib()
{
    F[0] = 0;
    F[1] = 1;
    for ( int i = 1 ; i < N ; i++) F[i] = F[i-1] + F[i-2];
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	get_fib();


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
