/* ***********************************************
Author :111qqz
Created Time :2016年02月18日 星期四 16时02分06秒
File Name :code/zoj/3690.cpp
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
const LL MOD  =1E9+7;
LL n,m,k;
LL ans;
LL bad;
LL cur;
LL ksm(LL a,LL b)
{
    LL res = 1;
    while (b>0)
    {
	if (b&1)
	    res = (res *a)%MOD;
	b = b>>1;
	a = (a*a)%MOD;
    }
    return res;
}

LL cal(LL x,LL y)
   {
    return (x * y)%MOD;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (scanf("%lld %lld %lld",&n,&m,&k)!=EOF)
	{
	    ans = ksm(m,n);
	    if (k==0)
	    {
		printf("%lld\n",ans);
		continue;
	    }
//	    cout<<"ans:"<<ans<<endl;
	    bad  = 0LL;
//	    cout<<"m:"<<m<<" n:"<<n<<endl;
	    LL ny = ksm(m-1,MOD-2);
	    
	    cur = ksm(m,n-2)-1;
//	    cout<<"cur1:"<<cur<<endl;
	    cur = cal(cur,ny);

	  //  cout<<"cur2:"<<cur<<endl;
	    cur = cal(cur,m-1);
	    cur = cal(cur,2);
	 //   cout<<"cur3:"<<cur<<endl;
	    bad = cur%MOD;

	    cur =  cal(ksm(m,n-3)-1,ny);
	    cur = cal(cur,(m-1)*(m-1));
	    
	    bad = (bad + cur )%MOD;
	    
	    
//	    cout<<"bad5:"<<bad<<endl;
	    bad++;
	    bad = cal(bad,k);
	
	    printf("%lld\n",ans-bad);


	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
