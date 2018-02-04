/*************************************************************************
	> File Name: code/cf/#309/B.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: Tue 21 Jul 2015 02:33:37 PM CST
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
string st[105];
int main()
{
    int n ;
    cin>>n;
    getchar();
    for ( int i  = 0 ; i < n ; i++ )
    {
	cin>>st[i];
    }
    int ans = 0;
    for ( int i = 0 ; i < n;  i++ )
    {
	int sum = 0;
	for ( int j = 0 ; j < n ; j++)
	{
	    if (st[i]==st[j])
	    {
		sum++;
	    }
	}
	ans = max (ans,sum);
    }
    cout<<ans<<endl;
  
	return 0;
}
