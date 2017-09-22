/* ***********************************************
Author :111qqz
Created Time :2015年12月16日 星期三 19时36分18秒
File Name :code/cf/problem/44A.cpp
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
bool tri[3000];
int  n;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	
	ms(tri,false);
	for ( int i = 1 ; i <= 50 ; i++) tri[i*(i+1)/2] = true;
	cin>>n;
	if (tri[n]) puts("YES"); else puts("NO");

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
