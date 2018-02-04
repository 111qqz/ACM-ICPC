/*************************************************************************
	> File Name: code/2015summer/searching/E.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: Thu 23 Jul 2015 11:51:38 PM CST
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
LL n;
LL ans;
int k = 0;
bool flag;
void dfs(LL x,LL n,LL k)
{
    if (flag) return;
    cout<<"x:"<<x<<endl;
    if (x%n==0)
    {
	  flag = true;
	  cout<<x<<endl;
	  return;
    }
    dfs(x*10,n,k+1);
    dfs(x*10+1,n,k+1);
}
int main()
{
    while (scanf("%lld",&n)!=EOF)
    {
        flag = false;
	  dfs(1,n,0);
    }
	return 0;
}
