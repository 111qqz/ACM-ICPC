/*************************************************************************
	> File Name: code/2015summer/#2/B.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: Fri 24 Jul 2015 12:28:41 PM CST
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
const int N=1E5+5;
int ans[2][N];
int m,n;
int a[N];
int mon,rm,sum;
int main()
{
    cin>>n>>m;
    for ( int i = 1 ; i<= n ; i++ )
	  cin>>a[i];
    mon = 0;
    rm = 0;
    sum =0;
    int pp=1;
    while (pp<=n)
    {
	  mon++;
	  rm = rm +m;
	  while (rm>=a[pp]&&pp<=n)
	  {
		rm=rm-a[pp];
		sum++;
	//	cout<<"rm:"<<rm<<endl;
	//	cout<<"pp:"<<pp<<endl;
		pp = pp + 1;
	  }
	  ans[0][mon]=sum;
	  ans[1][mon]=rm;
    }
    int q;
   // cout<<"sum:"<<sum<<endl;
   // cout<<"month:"<<mon<<endl;
    for ( int j = mon+1 ; j <=100005; j++)
    {
	  ans[0][j]=sum;
	  ans[1][j]=rm;
    }
   // cout<<"ans[0][8] "<<ans[0][8]<<endl;
    cin>>q;
    int d;
    for ( int i = 1 ; i<= q ; i++ )
    {
	  cin>>d;
	  cout<<ans[0][d]<<" "<<ans[1][d]<<endl;
    }
	return 0;
}
