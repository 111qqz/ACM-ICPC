/* ***********************************************
Author :111qqz
Created Time :2015年12月16日 星期三 19时25分50秒
File Name :code/cf/problem/3A.cpp
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

int ans;
int x,y;

char beg[10],tar[10];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%s",beg);
	scanf("%s",tar);
	x = int(tar[0]-beg[0]);
	y = int(tar[1]-beg[1]);
	
	ans = max(abs(x),abs(y));

	int tmp = 



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
