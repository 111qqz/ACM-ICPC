/*************************************************************************
	> File Name: code/hdu/3333.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月07日 星期五 17时04分07秒
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
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x7fffffff;
const int N=3E4+3;
LL c[N];
LL n,m,qur;
LL ref[N];
LL pre[N];
LL ori[N];
struct Q
{
    LL val,id;
}q[N];
struct S
{
     LL x,y;
     LL id,ans;
}s[100005];
bool cmp( Q a,Q b)
{
    if (a.val<b.val) return true;
    return false;
}
bool cmp2(S a,S b)
{
    if (a.y<b.y) return true;
    return false;
}
LL lowbit ( int x)
{
    return x&(-x);
}
void update ( LL x,LL delta)
{
    for ( LL i = x ; i <= n ; i = i + lowbit(i))
    {
	c[i] = c[i] + delta;
    }
}
LL sum( LL x)
{
    LL res = 0 ;
    for ( LL i = x; i >= 1 ; i = i - lowbit(i))
    {
	res = res + c[i];
    }
    return res;
}
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
	memset(ref,0,sizeof(ref));
	memset(c,0,sizeof(c));
	memset(pre,-1,sizeof(pre)); //标记上次出现位置的数组
	scanf("%lld",&n);
	for ( LL i = 1 ; i <= n ; i++)
	{
	    scanf("%lld",&q[i].val);
	    q[i].id  = i;
	}
	sort(q+1,q+n+1,cmp);
	LL cnt  = 0;
	for ( LL i = 1 ; i <= n ; i++ )
	{
	    if (q[i].val!=q[i-1].val)
	    {
		cnt++;
	    }
	    ref[q[i].id] = cnt;
	    ori[q[i].id] = q[i].val;
	}
	scanf("%lld",&qur);
	for ( LL i = 1 ;i  <= qur; i++ )
	{
	    scanf("%lld %lld",&s[i].x,&s[i].y);
	    s[i].id = i;
	}
	sort(s+1,s+1+qur,cmp2);
	s[0].y = 0;
	for ( LL i = 1 ; i <= qur  ; i++)
	{
	    for ( LL j = s[i-1].y+1 ; j <= s[i].y ; j++)
	    {
		int tmp = ref[j];
		if (pre[tmp]==-1)
		{
		    update(j,ori[j]);
		}
		else
		{
		    update (j,ori[j]);
		    update (pre[tmp],-ori[j]);
		}
		pre[tmp] =  j;
	    }
	    s[s[i].id].ans = sum(s[i].y)-sum(s[i].x-1);
	}
	for ( int i = 1 ; i <= qur ; i++ )
	{
	    cout<<s[i].ans<<endl;
	}
    }
	return 0;
}
