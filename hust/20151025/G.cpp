/*************************************************************************
	> File Name: code/hust/20151025/G.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月27日 星期二 15时47分20秒
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
                 
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=2E5+7;
struct Q
{
    LL d,r;
    int id;
}q[N];
LL t[N];
int n,m;
LL ans[N];

bool cmp(Q a,Q b )
{
    if (a.d==b.d)
	return a.r<b.r;
    return a.d<b.d;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

    ms(q,0);
    ms(ans,0);
   scanf("%d %d",&n,&m);
   for  ( int i = 1 ; i <= m ; i++) scanf("%lld",&t[i]);
   
   for ( int i = 1 ; i  <= n ; i++) scanf("%lld %lld",&q[i].d,&q[i].r),q[i].id = i;
   sort(q+1,q+n+1,cmp);

   LL sum=0 ; //sum表示当前完成的工作量
   int k=1;
   for ( int i = 1 ; i <= n ; i++)
   {
//	if (q[i].d!=q[i-1].d)
//	{
	    sum = 0 ;
	    k = 1;
//	}
//	else
//	{
///	    if (sum>=q[i].r)
//	    {
//		ans[q[i].id] = k;
//		continue;
//	    }
//	    else k++;
//	}
  
	    for (;k<=m;k++)
	{
	    LL tmp = t[k]-q[i].d;
	    if (tmp>0) sum = sum + tmp;
	    if (sum>=q[i].r) 
	    {
		ans[q[i].id] = k;
		break;
	    }
	}
   }
   for ( int i = 1 ; i < n ; i++) printf("%lld ",ans[i]);
   printf("%lld\n",ans[n]);



  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
