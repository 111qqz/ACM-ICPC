/* ***********************************************
Author :111qqz
Created Time :2016年02月01日 星期一 20时46分24秒
File Name :code/cf/problem/9A.cpp
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
int a,b;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>a>>b;
	if (a>b) swap(a,b);
	int ans = 6-b+1;
	if (ans==1||ans==5) printf("%d/6\n",ans);
	if (ans==2) puts("1/3");
	if (ans==3) puts("1/2");
	if (ans==4) puts("2/3");
	if (ans==6) puts("1/1");

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
