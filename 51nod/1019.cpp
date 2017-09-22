/*************************************************************************
	> File Name: code/51nod/1019.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月11日 星期日 16时29分14秒
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
const int N=5E4+7;
int a[N];
int ref[N];
int t[N];


struct Q
{
    int val;
    int id;
}q[N];

bool cmp( Q a,Q b)
{
    return a.val<b.val;
}
int n ;
int lowbit( int x){return x&(-x);};
void update(int x,int delta)
{
    for ( int i = x ; i <=  n ; i += lowbit(i))
    {
	t[i] = t[i] + delta;
    }
}
int sum( int x)
{
    int res = 0 ;
    for ( int i = x; i >= 1 ; i -= lowbit(i))
    {
	res = res + t[i];
    }
    return res;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
 //  freopen("in.txt","r",stdin);
  #endif
   scanf("%d",&n);
   for ( int i = 1 ; i <= n ; i++)
   {
       scanf("%d",&q[i].val);
       q[i]. id = i ;  
   }
   sort(q+1,q+n+1,cmp);
   q[0].val = -1;
   for ( int i = 1 ; i <= n ; i++)
    {
	if (q[i].val!=q[i-1].val)
	{
	    ref[q[i].id] = i;
	}
	else
	{
	    ref[q[i].id] =ref[q[i-1].id];
	}
    }
   ms(t,0);
   LL ans = 0 ;
   for ( int i = 1; i <= n ; i++)
    {
//	cout<<ref[i]<<"  a"<<endl;
	update (ref[i],1);
	ans = ans + i-sum(ref[i]);
    }
   cout<<ans<<endl;
  
   
 #ifndef ONLINE_JUDGE  
//  fclose(stdin);
  #endif
	return 0;
}
