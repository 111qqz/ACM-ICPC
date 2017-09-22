/*************************************************************************
	> File Name: code/whust/#0.2/II.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月09日 星期日 16时50分17秒
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
string st1,st2;
map<string,LL>mp;
map<string,LL>::iterator it;
LL ans;
int main()
{
    int T;
    cin>>T;
    int n;
    while (T--)
    {
	ans = 1;
	scanf("%d",&n);
	mp.clear();
	for ( int i = 0 ; i < n; i ++)
	{
	    cin>>st1>>st2;
	    if (mp[st2]!=0)
	    {
		mp[st2]++;
	    }
	    else
	    {
		mp[st2]=1;
	    }
	}
	for ( it=mp.begin();it!=mp.end();it++)
	{
	    ans*=(it -> second+1);
	}
	cout<<ans-1<<endl;

    }
  
	return 0;
}
