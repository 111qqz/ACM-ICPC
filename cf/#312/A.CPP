/*************************************************************************
	> File Name: code/#312A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com
	> Created Time: Mon 20 Jul 2015 10:20:43 PM CST
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
const int N=1E5+7;
struct Q
{
    int a,x;
}p[N],z[N],f[N];


bool cmp( Q aa,Q bb)
{
    if (aa.x>bb.x) return true;
    return false;
}
bool cmp2(Q aa,Q bb)
{
        if (aa.x<bb.x) return true;
        return false;
}
int main()
{

    int n;
    cin>>n;
    for ( int i = 0 ; i < n ; i++)
    {
	  cin>>p[i].x>>p[i].a;
    }
    int id1=0;
    int id2=0;
    for ( int i= 0 ; i< n ; i++)
    {
	  if (p[i].x>0)
	  {
		id1++;
		z[id1].x = p[i].x;
		z[id1].a = p[i].a;
	  }
	  if (p[i].x<0)
	  {
		id2++;
		f[id2].x=p[i].x;
		f[id2].a=p[i].a;
	  }
    }
    sort(z+1,z+id1+1,cmp2);
    sort(f+1,f+id2+1,cmp);
    int k = min(id1,id2);
    int ans = 0;
    for ( int i = 1 ; i <= k; i++)
    {
	  ans = ans + f[i].a+z[i].a;
    }
    cout<<"id1："<<id1<<" id2:"<<id2<<endl;
    if(id1>id2)
    {
	  ans = ans + z[id2+1].a;
    }
    if (id1<id2)
    {
	  ans = ans + f[id1+1].a;
    }
    cout<<ans<<endl;
	return 0;
}
