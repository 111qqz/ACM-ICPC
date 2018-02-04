/*************************************************************************
	> File Name: code/multi/#5/1001.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月04日 星期二 14时22分11秒
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
string a,b;
set<string>se;
set<string>sa,sb;
set<string>::iterator it1;
set<string>::iterator it2;
int la,lb;
int main()
{
    int T;
    cin>>T;
    string tmp;
    while (T--)
    {
	cin>>a>>b;
	la = a.length();
	lb = b.length();
	for ( int i = 0 ; i < la ; i++ )
	{
	    for ( int j = 0 ; j <= la-i ; j++ )
	    {
		tmp = a.substr(i,j);
		sa.insert(tmp);
	 //   	cout<<a.substr(i,j)<<endl;
	    }
	}
//	cout<<"sa.size()"<<sa.size()<<endl;
	for ( int i = 0 ; i < lb ; i++ )
	{
	    for ( int j = 1 ; j <= lb - i ;  j++ )
	    {
		tmp = b.substr(i,j);
		sb.insert(tmp);
	    }	
	}
	for ( it1=sa.begin();it1!=sa.end();it1++)
	{
	    int p = 1;
	    for ( it2 = sb.begin();it2!=sb.end();it2++)
	    {
		
		tmp = *it1+*it2;
		se.insert(tmp);
	    }
	}
	cout<<se.size()<<endl;
    }
  
	return 0;
}
