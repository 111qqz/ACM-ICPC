/*************************************************************************
  > File Name: code/hud/1394.cpp
  > Author: 111qqz
  > Email: rkz2013@126.com 
  > Created Time: 2015年10月28日 星期三 21时16分47秒
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
const int N=5E3+7;
int c[N];
int n,a[N];
int lowbit( int x)
{
    return x&(-x);
}
void update ( int x,int delta)
{
    for ( int i = x ; i <= n ; i = i + lowbit(i)) c[i] = c[i] + delta;
}
int Sum( int x)
{
    int res = 0 ;
    for ( int i = x ;i >= 1; i = i - lowbit(i))
    {
	res = res + c[i];
    }
    return res;
}
int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("in.txt","r",stdin);
#endif
    while (scanf("%d",&n)!=EOF)
    {
	ms(c,0);
	for ( int i = 1 ; i <= n ; i++)
	{
	    scanf("%d",&a[i]);
	    a[i]++;
	}
	int cnt = 0 ;
	int ans = inf;
	for ( int i = 1  ; i <= n ; i++)
	{
	    update(a[i],1);
	    cnt = cnt + i - Sum(a[i]);
	}
	if (cnt<ans) ans = cnt;
	for ( int i = 1 ; i <= n ; i++)
	{
	    cnt =cnt -a[i]+n-a[i]+1;
	    if (cnt<ans&&cnt>0) ans = cnt;
	}
	printf("%d\n",ans);
    }
#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
