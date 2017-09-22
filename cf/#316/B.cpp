/*************************************************************************
	> File Name: code/cf/#316/B.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月14日 星期五 00时36分16秒
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
int n,m;
int main()
{
    cin>>n>>m;
    if (n==1&&m==1)
    {
	cout<<1<<endl;
	return 0;
    }
    if (n%2==0)
    {
	if (m<=n/2)
	{
	    cout<<m+1<<endl;
	}
	else
	{
	    cout<<m-1<<endl;
	}
    }
    else
    {
	if (m>=(n+1)/2)
	{
	    cout<<m-1<<endl;
	}
	else
	{
	    cout<<m+1<<endl;
	}
    }
  
	return 0;
}
