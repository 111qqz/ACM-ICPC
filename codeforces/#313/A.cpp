/*************************************************************************
	> File Name: code/cf/#313/A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: Wed 22 Jul 2015 09:52:39 PM CST
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
int main()
{
    int n;
    cin>>n;
    bool flag = false;
    int x;
    for ( int i = 1 ; i <= n ; i++)
    {
	  cin>>x;
	  if (x==1)
	  {
		flag = true;
	  }
    }
    if (flag)
    {
	  cout<<-1<<endl;
    }
    else
    {
	  cout<<1<<endl;
    }
  
	return 0;
}
