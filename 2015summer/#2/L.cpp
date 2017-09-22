/*************************************************************************
	> File Name: code/2015summer/#2/L.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: Fri 24 Jul 2015 12:49:06 PM CST
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
const int N=1E4+5;
int p[N],k[N],r[N];
int main()
{
    int n;
    cin>>n;
    for ( int i  =1 ; i <= n ; i++)
    {
	  cin>>p[i];
    }
    for ( int i = 1 ; i  <= n ; i++ )
    {
	  cin>>k[i];
    }
    for ( int i = 1 ; i <= n ; i++ )
    {
	  cin>>r[i];
    }
    int ans1 = 0;
    int ans2 = 0;
    for ( int i = 1 ; i <= n ; i++ )
    {
	  if (abs(k[i]-r[i])<abs(p[i]-r[i]))
	  {
		ans2++;
	  }
	  if (abs(k[i]-r[i])>abs(p[i]-r[i]))
	  {
		ans1++;
	  }
    }
    cout<<ans1<<" "<<ans2<<endl;
  
	return 0;
}
