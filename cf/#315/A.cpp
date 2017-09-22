/*************************************************************************
	> File Name: code/cf/#315/A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月11日 星期二 01时26分16秒
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
int main()
{
    int t,s,q;
    cin>>t>>s>>q;
    int ans = 1;
    int x = s*q;
    while (x<t)
    {
	ans++;
	x = x*q;
    }
                     
    cout<<ans<<endl;

  
	return 0;
}
