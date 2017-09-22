/* ***********************************************
Author :111qqz
Created Time :2015年12月30日 星期三 22时49分02秒
File Name :code/cf/goodbye2015/B.cpp
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
const int N=1E4+7;
LL a,b;
LL p[N];
LL c[N];
LL cal( LL x)
{
    return ((x-1LL)*x)/2LL;
}
LL solve (LL x)
{
    if (x==0LL) return 0;
    LL res= 0LL;
    LL cnt = 0LL;
    LL xx = x;
    while (xx)
    {
	cnt++;
	p[cnt] = xx%2LL;
	xx/=2LL;
    }
    ms(c,0);
    res+=cal(cnt-1LL);
    LL tmp = (1LL<<cnt)-1LL;
    for ( LL i = 0 ; i <cnt-1 ; i++)
    {
	LL happ = 1LL<<i;
	c[i]=tmp-happ;
    }

    sort(c,c+cnt-1);

    for ( LL i = 0  ; i< cnt -1 ; i++)
    {
	if (x>=c[i]) res++;
    }
    
   
    return res;
}
int main()
{
	
	cin>>a>>b;
	LL ans = solve(b)-solve(a-1LL);
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
