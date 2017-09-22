/*************************************************************************
	> File Name: code/2015summer/#3/F.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月28日 星期二 13时05分42秒
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
const int N=1E3+5;
int a[N];
int n,k,r,l,sall,sk;
int main()
{
    cin>>n>>k>>l>>r>>sall>>sk;
    int sum = (n-k)*l;
    int ll=l;
    while (sum<sall-sk)
    {
	  ll++;
	  sum = (n-k)*ll;
    }
    for ( int i = n ; i  >= k+1 ; i--)
    {
	  a[i]=ll;
    }
 //   cout<<"a[n]:"<<a[n]<<endl;
    int i = n;
    while (sum>sall-sk)
    {
	  if (a[i]>l)
	  {
		a[i]--;
	  
		sum--;
	  }
	  else
	  {
		i--;
	  }
    }
    int newl =max(a[k+1],l);   //a[k+1]might be zero
    sum = k*newl;   
    ll = newl;
    while (sum<sk)
    {
	  ll++;
	  sum=k*ll;

    }
    for ( int i = 1 ; i <= k ; i++ )
    {
	  a[i]=ll;
    }
    i = k;
    while (sum>sk)
    {
	  if (a[i]>newl)
	  {
		a[i]--;
		sum--;
	  }
	  else
	  {
		i--;
	  }

    }
    for ( int i = 1 ; i < n ; i++ )
    {
	  cout<<a[i]<<" ";
    }
    cout<<a[n]<<endl;
	return 0;
}
