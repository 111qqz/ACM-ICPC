/*************************************************************************
	> File Name: code/cf/#295/A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月17日 星期一 04时05分12秒
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
bool v[30];
int main()
{
    int n;
    scanf("%d",&n);
    memset(v,false,sizeof(v));
    string st;
    cin>>st;
    for ( int i = 0 ; i < n ; i ++)
    {
	if (islower(st[i]))
	{
	    v[st[i]-'a'] = true;
	}
	else
	{
	    v[st[i]-'A'] = true;
	}
    }
    for ( int i = 0 ; i < 26 ; i++)
    {
	if (!v[i])
	{
	    
	    cout<<"NO"<<endl;
	    return 0;
	}
    }
    cout<<"YES"<<endl;
  
	return 0;
}
