/*************************************************************************
	> File Name: code/2015summer/#3/I.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月28日 星期二 12时50分03秒
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
int n,m,k,a[N];
int main()
{
    cin>>n>>m>>k;
    int ans = 0;
    for ( int i  = 0 ;  i < n ; i ++ )
    {
	  scanf("%d",&a[i]);
	 // a[i]=3-a[i];
    }
    sort(a,a+n);
    for ( int i = n-1 ; i>=0; i--)
    {
	  if (a[i]==2)
	  {
		if (k>0)
		{
		    k--;
		}
		else if (m>0)
			{
			  m--;
		      }
		      else
			  {
				ans++;
			  }
	  }
	  if (a[i]==1)
	  {
		if (m>0)
		{
		    m--;
		}
		else
		{
		    ans++;
		}
	  }
    }
    cout<<ans<<endl;
  
	return 0;
}
