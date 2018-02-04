/*************************************************************************
	> File Name: code/cf/#314/A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月06日 星期四 00时01分51秒
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
LL a[N];
int main()
{
    int n;
    cin>>n;
    a[0]=-inf;
    a[n+1]=inf;

    for ( int i  = 1 ; i <= n ; i ++ )
    {
	cin>>a[i];
    }
    int mx = -1;
    int mi = inf;
    cout<<a[2]-a[1]<<" "<<a[n]-a[1]<<endl;
    for ( int i = 2 ; i <= n-1 ; i++ )
    {
	cout<<min(abs(a[i]-a[i-1]),abs(a[i+1]-a[i]))<<" "<<max(abs(a[i]-a[1]),abs(a[n]-a[i]))<<endl;
    }
    cout<<a[n]-a[n-1]<<" "<<a[n]-a[1]<<endl;
	return 0;
}
