/*************************************************************************
	> File Name: code/cf/#313/D.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月17日 星期一 08时42分25秒
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
const int N=2E5+7;
string a,b;
int len;

bool equal( string x,string y,int len)
{
  //  cout<<"x:"<<x<<" y:"<<y<<" len:"<<len<<endl;
    if (x==y) return true;
    string x1,x2,y1,y2;
    x1 = x.substr(0,len/2);
    x2 = x.substr(len/2,len);
    y1 = y.substr(0,len/2);
    y2 = y.substr(len/2,len);
    if (len%2==0&&equal(x1,y2,len/2)&&equal(x2,y1,len/2))
    {
	return true;
    }
    if (len%2==0&&equal(x1,y1,len/2)&&equal(x2,y2,len/2))
    {
	return true;
    }
    return false;
}
int main()
{
    cin>>a;
    cin>>b;
    len = a.length();
    if (equal(a,b,len))
    {
	puts("YES");
    }
    else
    {
	puts("NO");
    }
      
	return 0;
}
