/* ***********************************************
Author :111qqz
Created Time :2015年12月22日 星期二 14时44分04秒
File Name :code/cf/problem/602B.cpp
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
int n;
int a[N];

void ruler()
{
    int head = 1;
    int tail = 1;
    int len;
    int mx,mi;
    int ans = 0 ;

    while (tail<=n)
    {
	len++;
	if (abs())

    }

}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d",&n);
	for ( int i = 1 ; i <= n; i++) scanf("%d",&a[i]);

	ruler();

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
