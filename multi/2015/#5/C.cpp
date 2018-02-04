/*************************************************************************
	> File Name: code/2015summer/#5/C.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月30日 星期四 13时33分17秒
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
LL a,b,c;
LL x,y;
set<LL>myset;
int main()
{
    cin>>a>>b>>c;
    x = 1;
    myset.insert(1);
    LL ans = -1;
    LL y11,y2;
    for ( int  i = 1 ; i <=2000000/100000 ; i++)
    {
	y11 = (a%c)*(x%c)%c;
	y2 = x%b%c;
	y = (y11+y2)%c; 
	cout<<"y:"<<y<<endl;

	if (myset.count(y)==1)
	{
	    ans = i;
	  //  break;
	}
	else
	{
	    myset.insert(y);
	}
	x = y;

    }
    cout<<ans<<endl;
  
	return 0;
}
