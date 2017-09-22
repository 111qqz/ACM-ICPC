/* ***********************************************
Author :111qqz
Created Time :Wed 19 Oct 2016 06:05:30 PM CST
File Name :code/hdu/1420.cpp
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
LL a,b,c;
int n;
LL ksm(LL a,LL b,LL mod)
{
    LL res = 1;
    while (b>0)
    {
	if (b&1) res = (res * a)%mod;
	b = b >> 1;
	a = (a * a)%mod;
    }
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%d",&n))
	{
	    for ( int i = 1 ; i <= n ; i++)
	    {
		scanf("%lld%lld%lld",&a,&b,&c);
		printf("%lld\n",ksm(a,b,c));
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
