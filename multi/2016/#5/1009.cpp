/*************************************************************************
	> File Name: code/multi/#5/1009.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月04日 星期二 15时04分04秒
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
const int N=1E3+5;
string st[N];
int n,m;
int main()
{
    st[1]="b";
    st[2]="a";
    for ( int i = 3 ; i<= 10 ; i++ )
    {
	st[i]=st[i-1]+st[i-2];
    }
    cout<<st[1000].substr(0,5)<<endl;
    int T;
    cin>>T;
    string str;
    while (T--)
    {
	scanf("%d %d",&n,&m);
	str = st[1000].substr(0,m);
	cout<<str<<endl;
    }
    

	return 0;
}
