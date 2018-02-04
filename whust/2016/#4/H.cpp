/* ***********************************************
Author :111qqz
Created Time :2016年08月13日 星期六 13时06分10秒
File Name :code/whust2016/#4/H.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <deque>
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
const int N=65;
const unsigned long long LIMIT = 1LL<<63LL;
LL l,r;
int digit[N];
LL dp[N][N][N];

/*inline int ilog2_kf(LL n)
{
    float q = float(n);
    return (((*i(int*)&q)>>23)+1)&31;
}
LL cal(LL n,LL res,LL num1,LL num0 )
{
    LL ret = res;
    LL cnt = num1+num0;
    if (cnt+ilog2_kf(ret)>ilog2_kf(n)) return res;
    
    ret = ret * (1LL<<cnt);
    LL add = 1LL<<(cnt-1LL);
    for ( LL i = 1 ; i <= num1 ; i++)
    {
	ret +=add;
	if (ret>n) return res;
    }
     

}  */
LL solve ( LL n)
{
    if (n==0) return 0;
    LL res = 0 ;
    ms(digit,0);
    int len = 0 ;
    LL nn = n ;
    while (nn)
    {
	digit[++len] = nn % 2;
	nn/=2;
    }
    
    int k=0;
    for (LL i =0 ; (1LL<<i)<= n ; i++ )
    {
	k = i ;
    }
    cout<<"K:"<<k<<endl;
    res = k ;
    for ( LL i = 1 ; (1LL<<i)<=n ; i++)
	for ( LL j = 1 ; 1LL<<(i+j)<=n ; j++)
	{
	    cout<<"i:"<<i<<" j:"<<j<<endl;
	    if (len%(i+j)==0||len%(i+j)==i)
	    {
		//res = res + (1LL<<(i+j))-1LL;
		if (len%(i+j)==0) res = res + len/(i+j);
		else res = res + (len-i)/(i+j);
			
		cout<<"res:"<<res<<endl;
	    }
	}

    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%lld%lld",&l,&r))
	{
	    cout<<"solve(r):"<<solve(r)<<endl;
	    cout<<"solve(l-1):"<<solve(l-1)<<endl;
	     LL ans = solve(r)-solve(l-1);
	     printf("%lld\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
