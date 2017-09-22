/* ***********************************************
Author :111qqz
Created Time :2016年02月27日 星期六 16时39分53秒
File Name :code/poj/3734.cpp
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
const LL MOD =1E4+7;
LL n;
LL res;
LL ksm(LL a,LL b)
{
    LL res = 1;
    while (b)
    {
	if (b&1) res=(res*a)%MOD;
	b = b>>1;
	a = (a*a)%MOD;
    }
    return res;
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
	    scanf("%lld",&n);
	    
	    LL ans = ksm(4,n-1)+ksm(2,n-1);
	    ans %=MOD;
	    printf("%lld\n",ans);

	}

	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
