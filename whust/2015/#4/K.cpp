/*************************************************************************
	> File Name: code/whust/#4/K.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月26日 星期日 14时57分13秒
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
string st;
LL solve(LL x,char tar)
{
    for(LL i=x;i>=0;i--)
    if(st[i]!=tar) return solve(i-1,'A'^'B'^'C'^tar^st[i])+((LL)1<<i);
    return 0;
}
int main()
{
    while(cin>>st&&st!="X")
    {
	  int len = st.length();
	  cout<<solve(len-1,'B')<<endl;
    }
    return 0;
}
