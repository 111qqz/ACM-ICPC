/*************************************************************************
	> File Name: code/whust/##1/D.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月12日 星期三 13时07分21秒
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
const int N=1E6+5;
int f[N];
int g[N];
int n;
int main()
{
    f[1] = 1;
    f[2] = 1;
    for ( int i = 3 ; f[i]<=1000000 ; i++)
    {
	f[i]=f[i-1]+f[i-2];
    }
    int n ;
    int ans;
    cin>>n;
    for ( int a =  1; a <= n-1 ;a++)
    {
	for ( int b = 1;b <= n-a;  b++)
	{
	    g[1] = a;
	    g[2] = b;
	    for ( int i = 3 ;g[i]<=n ;i++)
	    {
		g[i]=a*f[i-2]+b*f[i-1];
		if (g[i]>n) break;
	    //	cout<<i<<" "<<g[i]<<endl;
		if (g[i] == n)
		{
		    ans++;
		}

	    }
	}
    }
    cout<<ans<<endl;
   // cout<<n<<":"<<ans<<endl;
    
	return 0;
}
