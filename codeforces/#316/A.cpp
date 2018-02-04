/*************************************************************************
	> File Name: code/cf/#316/A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月14日 星期五 01时20分40秒
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
const int N=1E2+5;
int a[N][N];
int n,m;
int mx;
int cnt[N];
int main()
{
    cin>>n>>m;
    for ( int i = 1 ; i<= m ;i ++)
    {
	for ( int j = 1 ; j <= n ; j++ )
	{
	    scanf("%d",&a[i][j]);
	}
    }
    memset(cnt,0,sizeof(cnt));
    for ( int i = 1 ;i <= m ; i++ )
    {
	mx = -1;
	int p = -1;
	for ( int j = 1 ; j <= n ; j++ )
	{
	    if (a[i][j]>mx)
	    {
		mx = a[i][j];
		p = j;
	    }
	}
	cnt[p]++;
    }
    mx = -1;
    int ans;
    for ( int i = 1 ; i<= n ; i++)
    {
	if (cnt[i]>mx)
	{
	    mx = cnt[i];
	    ans = i;
	}
    }
    cout<<ans<<endl;


  
	return 0;
}
