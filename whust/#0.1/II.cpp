/*************************************************************************
	> File Name: code/whust/#0.1/II.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月09日 星期日 16时00分44秒
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
    cin>>T;
    string st;
    while (T--)
    {
	cin>>st;
	int len = st.length();
	LL p=0,q=0;
	LL ans = 0 ;
	for ( int i = 0 ; i < len ; i ++)
	{
	    if (st[i]=='L')
	    {
		p++;
		ans = ans + q;
	    }
	    else
	    {
		q = q+ p; //p为L的个数,q表示前面有"LO"组合的个数
	    }
	}
	cout<<ans<<endl;
    }
  
	return 0;
}
