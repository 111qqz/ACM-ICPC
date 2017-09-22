/* ***********************************************
Author :111qqz
Created Time :2016年03月24日 星期六 21时00分28秒
File Name :code/poj/1284.cpp
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
const int N=7E4+7;
int phi[N];
int n;
void solve()
{
    ms(phi,0);
    phi[1] = 1;
    for ( int i = 2 ; i < N ; i++)
    {
	if (!phi[i])
	for ( int j = i ; j < N ; j+=i)
	{
	    if (!phi[j])
		phi[j] = j;
	    phi[j] = phi[j]/i*(i-1);
	}
	
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	solve();
	while (~scanf("%d",&n))
	{
	    printf("%d\n",phi[n-1]);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
