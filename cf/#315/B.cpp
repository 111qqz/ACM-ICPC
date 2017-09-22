/*************************************************************************
	> File Name: code/cf/#315/B.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月11日 星期二 00时37分43秒
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
int n;
bool vis[N];
int b[N];
int main()
{
    cin>>n;
    memset(vis,false,sizeof(vis));
    for ( int i = 0 ; i < n; i ++ )
    {
	scanf("%d",&a[i]);
	vis[a[i]]=true;
    }
    int cnt  = 0;
    for ( int i = 1 ; i <= n ; i++)
    {
	if (!vis[i])
	{
	    cnt++;
	    b[cnt] = i;
	}
    }
    memset(vis,false,sizeof(vis));
    cnt  = 1;
    for ( int i = 0 ; i < n ; i++)
    {
	if (vis[a[i]]||a[i]>n)
	{
	    a[i] = b[cnt];
	    cnt++;
	}
	else
	{
	    vis[a[i]] = true;
	}
    }
    cout<<a[0];
    for ( int i = 1 ; i < n; i ++)
    {
	cout<<" "<<a[i];
    }
    cout<<endl;
	return 0;
}
