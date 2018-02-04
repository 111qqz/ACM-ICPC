/*************************************************************************
	> File Name: code/bc/#50/1001.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月08日 星期六 19时02分16秒
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
int cnt[10005];
int n;
int x;
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
	bool flag = false;
	memset(cnt,0,sizeof(cnt));
	for ( int i = 0 ; i < n ; i ++ )
	{
	    scanf("%d",&x);
	    cnt[x]++;
	    if (flag) continue;
	    if (cnt[x]>n/2)
	    {
		flag = true;
		cout<<x<<endl;
	    }
	}
	if (!flag)
	{
	    cout<<-1<<endl;
	}
    }
	return 0;
}
