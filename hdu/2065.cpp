/* ***********************************************
Author :111qqz
Created Time :2016年02月28日 星期日 14时01分58秒
File Name :code/hdu/2065.cpp
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
typedef unsigned long long LL;
#define pi pair < int ,int >
#define MP make_pair

using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const LL MOD = 100;
LL n;
LL ksm(LL a,LL b)
{
    LL res = 1LL;
    while (b)
    {
	if (b&1) res = (res*a)%MOD;
	b = b>>1;
	a =(a*a)%MOD;
    }
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;

	while (~scanf("%d",&T))
	{
	    if (T==0) break;
	    int cas = 0 ;
	    while (T--)
	    {
		printf("Case %d: ",++cas);
		scanf("%llu",&n);
		LL ans = ksm(4,n-1)+ksm(2,n-1);
		ans %=MOD;
		printf("%llu\n",ans);
	    }
	    printf("\n");
	}
	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
