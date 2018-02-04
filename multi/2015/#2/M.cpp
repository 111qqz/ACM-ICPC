/*************************************************************************
	> File Name: code/2015summer/#2/M.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: Fri 24 Jul 2015 12:36:37 PM CST
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
const int N=100;
int q[N],c[N],p[N];
int main()
{
    int n;
    cin>>n;
    for ( int i = 1 ; i <= n ; i++ )
    {
	  cin>>q[i];
    }
    for ( int i = 1 ; i <= n ; i++ )
    {
	  cin>>c[i];
    }
    for ( int i =1 ; i <= n ; i++ )
    {
	  cin>>p[i];
    }
    int mx = -1;
    for ( int i = 1 ; i <= n ; i++)
    {
	  int tmp = (q[i]-1)/c[i]+1;
//	  cout<<"i:"<<i<<" tmp:"<<tmp<<endl;
	  if (tmp>mx)
		mx=tmp;
    }
    LL ans = 0;
  //  cout<<"mx:"<<mx<<endl;
    for ( int i =1 ;  i <= n ; i++ )
    {
	  ans = ans + (mx*c[i]-q[i])*p[i];
    }
    cout<<ans<<endl;
  
	return 0;
}
