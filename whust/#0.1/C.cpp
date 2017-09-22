/*************************************************************************
	> File Name: code/whust/#0.1/C.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月08日 星期六 13时30分17秒
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
    int T;
    string s;
    int n,p;
    cin>>T;
    while (T--)
    {
	cin>>n>>s>>p;
	if (s=="odd")
	{
	    cout<<2*p<<endl;
	}
	else
	{
	    cout<<2*p-1<<endl;
	}
    }
	return 0;
}
