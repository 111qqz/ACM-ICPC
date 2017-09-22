/*************************************************************************
	> File Name: code/bc/#49/B.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月01日 星期六 19时08分57秒
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
string st;
string s1,s2,s3;
bool flag;
bool ok(string x)
{
    int l = x.length();
    for ( int i = 0 ; i < l/2; i++)
    {
	if (x[i]!=x[l-i-1])
	{
	    return false;
	}
    }
   
    return true;
}
int main()
{
    int T;
    cin>>T;

    while (T--)
    {
	bool flag = false;
	cin>>st;
	int len = st.length();
	int cnt  = 0 ;
	string re;
	for ( int i = 1 ; i <= len - 2 ; i++)
	{
	    s1=st.substr(0,i);
	    if (ok(s1))
	    {
		cnt++;
		st1[cnt]=s1;
	    }
	}
	int cnt2 = 0;
	for ( int j = len-1 ; j >=2 ;j ++)
	{
	    s2=st.substr(j);
	    if (ok(s2))
	    {
		cnt2++;
		st2[cnt2]=s2;
	    }
	}
	for ( int i =1 ; i <=cnt ; i++)
	{
	
	}
	if (flag)
	{
	    cout<<"Yes"<<endl;
	}
	else
	{
	    cout<<"No"<<endl;
	}
	
    }
  
	return 0;
}
