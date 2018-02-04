/*************************************************************************
	> File Name: code/2015summer/#4/H.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月30日 星期四 12时46分16秒
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
    int n;
    char st[30];
    cin>>n;
    for ( int i = 0 ; i < n ; i++ )
    {
	cin>>st;
	int len = strlen(st);
	if (st[len-1]=='o'||st[len-1]=='x'||st[len-1]=='s'||(st[len-1]=='h'&&st[len-2]=='c'))
	{
	    cout<<st<<"es"<<endl;
	    continue;
	}
	if (st[len-1]=='f')
	{
	    st[len-1]='v';
	    cout<<st<<"es"<<endl;
	    continue;
	}
	if (st[len-1]=='e'&&st[len-2]=='f')
	{
	    st[len-2]='v';
	    cout<<st<<"s"<<endl;
	    continue;
	}
	if (st[len-1]=='y')
	{
	    st[len-1]='i';
	    cout<<st<<"es"<<endl;
	    continue;
	}
	cout<<st<<"s"<<endl;
    }
	return 0;
}
