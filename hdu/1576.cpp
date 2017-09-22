/* ***********************************************
Author :111qqz
Created Time :Wed 12 Oct 2016 07:18:48 PM CST
File Name :code/hdu/1576.cpp
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
const LL MOD = 9973;
LL ksm( LL a,LL b)
{
    LL ret = 1;
    while (b)
    {
	if (b&1) ret = (ret * a) % MOD;
	b = b >> 1;
	a = ( a * a ) % MOD;
    }
    return ret;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    LL n,B;
	    scanf("%lld %lld",&n,&B);
	    LL ans = (n * ksm(B,MOD-2)+MOD)%MOD;
	    printf("%lld\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
