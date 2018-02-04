/* ***********************************************
Author :111qqz
Created Time :2016年03月12日 星期六 18时15分00秒
File Name :code/bc/#75/1003.cpp
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
const LL mod =1E9+7;
LL n;
LL ksm ( LL a,LL b)
{
    LL res = 1LL;
    if (b<=0)  return 0;
    while (b>0)
    {
	if (b%2==1) res = (res *a)%mod;
	b = b >> 1;
	a = (a*a)%mod;
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
	    LL ans = ksm(26,n);
	//    cout<<"ans:"<<ans<<endl

	    LL ans2 = 0LL ;
	    if (n>=4)
	    {
		ans2 = ksm(26,n-3);
		ans2 = (ans2 * (n-3) )%mod;
	    }
	    ans -= ans2;
	    ans +=mod;
	    ans %=mod;


	    printf("%lld\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
