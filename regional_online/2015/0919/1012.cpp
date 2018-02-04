/*************************************************************************
	> File Name: code/0919/1012.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月19日 星期六 12时13分07秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#include<cctype>
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
#define lr dying111qqz
using namespace std;
#define For(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=5E6+7;
LL n,a,b;
LL ans;
struct Q
{
    LL id,val;
}t[N],tt[N];

bool cmp( Q a,Q b)
{
    if (a.val<b.val) return true;
    return false;
}
void solve (int a,int b)
{

    
        if (a>=0&&b>=0)
	{
	    ans += a*tt[n-1].val;
//	    cout<<"ans1:"<<ans<<endl;
	    if (t[n-1].id==tt[n-1].id)
	    {
		ans += b*t[n-2].val;
	    }
	    else
	    {
		ans += b*t[n-1].val;
	    }
//	    cout<<"ans2:"<<ans<<endl;
	    return ;

	}
	if (a>=0&&b<0)
	{
	    ans += a*tt[n-1].val;
	    if (t[0].id==tt[n-1].id)
	    {
		ans += b*t[1].val;
	    }
	    else
	    {
	        ans += b*t[0].val;
	    }
	    return ;
	}
	if (a<0&&b>=0)
	{
	    ans += a*tt[0].val;
	    if (tt[0].id==t[n-1].id)
	    {
		ans += b*t[n-2].val;
	    }
	    else
	    {
		ans +=b*t[n-1].val;
	    }
	    return ;
	}
	if (a<0&&b<0)
	{
	    ans += a*tt[0].val;
	    if (tt[0].id==t[0].id)
	    {
		ans += b*t[1].val;
	    }
	    else
	    {
		ans += b*t[0].val;
	    }

	    return ;
	}

}
int main()
{
  
    int T;
    cin>>T;
    int cas = 0;
    while (T--)
    {
	cas++;
	ans = 0 ;
	scanf("%lld %lld %lld",&n,&a,&b);
	for ( int i = 0 ; i < n ; i++)
	{
	    scanf("%lld",&t[i].val);
	    tt[i].val = t[i].val * t[i].val;
	    t[i].id = i;
	    tt[i].id = i ;
	}
	sort(t,t+n,cmp);
	sort(tt,tt+n,cmp);
//	for ( int i = 0 ; i < n ; i++) cout<<"tt[i]::"<<tt[i]<<endl;
	solve (a,b);
	
	printf("Case #%d: ",cas);
	printf("%lld\n",ans);
    }
  
  
	return 0;
}
