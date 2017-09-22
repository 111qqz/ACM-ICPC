/*************************************************************************
	> File Name: code/bc/#43/A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月31日 星期五 16时13分06秒
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
int len;
string ans1,ans2;
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
	cin>>st;
	len = st.length();
	int k = len/2-1;
	ans1="";
	ans2="";
	for ( int i = len - 1 ; i >= 0 ; i--)
	{
	    if (i%2==1)
	    {
		ans2=ans2+st[i];
	    }
	    else
	    {
		ans1=ans1+st[i];
	    }
	}
	for ( int i = k ; i >= 0; i--)
	{
	    cout<<ans1[i];
	}
	cout<<endl;
	cout<<ans2<<endl;
    }
  
	return 0;
}
