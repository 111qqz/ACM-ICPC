/*************************************************************************
	> File Name: code/multi/#5/1007.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月04日 星期二 12时39分42秒
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
const int N=1E6+7;
multiset<int>se;
multiset<int>::iterator it;
int main()
{
    int n;
    int cmd;
    int x;
    scanf("%d",&n);
    for ( int i = 0 ; i < n;  i++)
    {
	scanf("%d",&cmd);
	if (cmd==1)
	{
	    scanf("%d",&x);
	    se.insert(x);
	}
	if (cmd==2&&!se.empty())
	{
	    se.erase(se.begin());
	}
	if (cmd==3)
	{
	    if (se.empty())
	    {
		printf("0\n");
	    }
	    else
	    {
		it = se.end();
		it--;
		printf("%d\n",*it);
	    }
	}
    }
	return 0;
}
