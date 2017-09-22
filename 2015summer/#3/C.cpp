/*************************************************************************
	> File Name: code/2015summer/#3/C.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月28日 星期二 12时27分50秒
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
const int N=1E2+7;
double p[N];
int n;

bool cmp(double a,double b)
{
    if (a>b) return true;
    return false;
}
double solve (int x)
{
    double res=0;
    double poss;
    for  ( int i = 1 ; i <= x; i++)
    {
	poss = 1.0;
	for ( int j = 1 ; j <= x;  j++ )
	{
	    if (j==i) poss=poss*p[j-1];
	    else poss = poss * (1-p[j-1]);
	}
	res = res + poss;
    }
    return res;
}
int main()
{
    cin>>n;
    for ( int i = 0 ; i < n ; i++ )
    {
	cin>>p[i];
    }
    sort(p,p+n,cmp);
    double ans = 0;
    for ( int i = 0 ; i < n ; i++ )
    {
	ans = max(ans,solve(i+1));
    }
    cout<<fixed<<setprecision(12)<<ans<<endl;
  
	return 0;
}
