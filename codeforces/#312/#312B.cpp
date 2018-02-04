/*************************************************************************
	> File Name: code/#312B.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: Mon 20 Jul 2015 10:41:09 PM CST
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
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int N=1E6+7;
struct Q
{
    int cnt,s,len;
}q[N];
int a[N];

bool cmp(Q a,Q b)
{
    if (a.cnt>b.cnt)
	  return true;
    if (a.cnt==b.cnt&&a.len<b.len) return true;
    return false;
}
int main()
{
    int n;
    int mx=-1;
    cin>>n;
    memset(q,0,sizeof(q));
    for ( int i = 1 ; i <= n ; i++)
    {
	  cin>>a[i];
	  if (a[i]>mx)
	  {
		mx = a[i];
	  }
	  if (q[a[i]].cnt==0)
	  {
		q[a[i]].s=i;
	  }
	  else
	  {
		q[a[i]].len=i-q[a[i]].s;
	  }
	  q[a[i]].cnt++;
    }
    sort(q+1,q+1+mx,cmp);
    cout<<q[1].s<<" "<<q[1].s+q[1].len<<endl;


	return 0;
}
