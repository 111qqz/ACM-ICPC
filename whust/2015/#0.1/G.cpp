/*************************************************************************
	> File Name: code/whust/#0.1/G.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月09日 星期日 16时30分27秒
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
int a[20];
int n,k;
int main()
{

    int T;
    cin>>T;
    while (T--)
    {
	int ans = 0 ;
	scanf("%d %d",&n,&k);
	for ( int i = 0 ; i < n ; i++ )
	{
	    a[i] = i+1;
	}
	do
	{
	    bool flag = true;
	    for ( int i = 0 ; i < n-1 ; i++)
	    {
		if (abs(a[i]-a[i+1])>k)
		{
		    flag = false;
		    break;
		}
	    }
	    if (flag) ans++;
	}while (next_permutation(a,a+n));

	cout<<ans<<endl;
    }
	return 0;
}
