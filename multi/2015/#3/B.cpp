/*************************************************************************
	> File Name: code/2015summer/#3/B.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月28日 星期二 12时27分39秒
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
 
    cin>>n;
    memset(color,0,sizeof(color));
    memset(num,0,sizeof(num));
    for ( int i = 1; i <= n ; i++ )
    {
	  cin>>st[i];
	  color[st[i]-'A'+1]++;
	  num[st[i]-'0']++;
    }
    

	return 0;
}
