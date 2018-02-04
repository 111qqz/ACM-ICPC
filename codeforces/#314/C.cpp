/*************************************************************************
	> File Name: code/cf/#314/C.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月06日 星期四 01时10分32秒
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
const int N=2E5+7;
int a[N];
int n,k;
bool v[N];
LL b[N],c[N];
int cnt;
int n1;
int n2;
void dfs( int x,int num )
{
    if (num==3)
    {
	ans++;
	return;
    }
    for ( int i = x+1 ; i <= n1 ; i++ )
    {
	if (b[x]*k==b[i])
	{
	    dfs(i,num);
	}
    }
}
int main()
{
    cin>>n>>k;
    ans  = 0;
    cnt  =0;
    n1 = 0;
    n2 = 0;
    memset(v,false,sizeof(v));
    for ( int i = 0 ;  i < n ; i++ )
    {
	scanf("%d",&a[i]);
	if (a[i]==0)
	{
	    cnt++;
	}
	if (a[i]>0)
	{
	    n1++;
	    b[n1] = a[i];
	}
	if (a[i]<0)
	{
	    n2++;
	    c[n2] = a[i];
	}

    }
    dfs(1,1);
  
	return 0;
}
