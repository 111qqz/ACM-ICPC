

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

bool cmp(Q a ,Q b )
{
    if (a.cnt>b.cnt)
	  return true;
    if (a.cnt==b.cnt&&a.len<b.len) return true;
    return false;
}
int main()
{
    int n;
    cin>>n;
    memset(q,0,sizeof(q));
    for ( int i = 0 ; i < n ; i++)
    {
	  cin>>a[i];
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
    sort(q,q+n,cmp);
    cout<<q[0].s+1<<" "<<q[0].s+q[0].len+1<<endl;


	return 0;
}
