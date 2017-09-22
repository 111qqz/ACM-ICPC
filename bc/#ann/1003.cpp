/*************************************************************************
	> File Name: code/nv/#ann/1003.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com
	> Created Time: 2015年07月28日 星期二 23时03分09秒
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
const int N=1E5+7;
int k,m,f[N];
void init()
{
    for ( int i = 1 ; i <N; i++)
    {
	f[i]=3*i*(i-1)+1;
	if (f[i]>1000000000)
	{
	    k = i-1;
	    break;
	}
    }
}
int solve (int x)
{
    for ( int i = 1 ; f[i]<=x ; i++ )
    {
	if (x==f[i])
	    return 1;
    }
    int j = k;
    for ( int i = 1 ; i <= k-1&&f[i]<x ; i++)
    {
	while(f[i]+f[j]>x) j--;
	if (f[i]+f[j]==x) return 2;
    }
    for ( int i = 3 ; i <= m ; i++ )
    {
	if ((m-i)%6==0)
	    return i;
    }
}
int main()
{
    int T;
    init();
    cin>>T;
    int ans;
    while (T--)
    {

	scanf("%d",&m);
	cout<<solve(m)<<endl;

    }

	return 0;
}
