/*************************************************************************
	> File Name: code/2015summer/0814/E.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月14日 星期五 16时27分57秒
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
const int N=1E4+5;
    const double eqs = 1E-6;
int n;
int b[N];
set<int>ans;
set<int>::iterator it;
struct Q
{
    int id;
    double val;
}q[N];
bool cmp(Q a,Q b)
{
    if (a.val<b.val) return true;
    if (a.val==b.val)
    {
	if (a.val<0) 
	{
	    if (a.id<b.id) return true;
	}
	if (a.val>=0)
	{
	    if (a.id>b.id) return true;
	}
    }
    return false;
}
int main()
{
    cin>>n;
    int cnt = 0;
    bool ok = false;
    for ( int i = 1 ; i <= n ; i++ )
    {
	scanf("%lf",&q[i].val);
	if (q[i].val<0) cnt++;
	q[i].id = i;
    }
    sort(q+1,q+n+1,cmp);
//    for ( int i = 1 ; i <= n ; i++ )
//    {
//	printf("%lf ",q[i].val);
//    }

    for ( int i = cnt+1 ; i <= n ; i++)
    {
	if (q[i].val>1)
	{
	    ok = true;
	    ans.insert(q[i].id);
	}
    }
    for ( int i = 1 ; i < cnt ; i = i + 2 )
    {
	if (q[i].val * q[i+1].val>1)
	{
	    ok = true;
	    ans.insert(q[i].id);
	    ans.insert(q[i+1].id);

	}
    }
    if (!ok)
    {
	if (cnt==0)
	{
	    
	}
	if (cnt==1)
	{
	//	    for ( int i = 2 ;i <= n ;i++)
	 //   {
//		if (q[i].val==q[n].val)
//		{
		    ans.insert(q[n].id);
//		    break;
//		}
//	    }
	}
	else
	{
	    if (q[n].val>=q[1].val*q[2].val)
	    {
//		for ( int i = cnt + 1 ; i<= n; i++)
//		{
//		    if (q[i].val==q[n].val)
//		    {
			ans.insert(q[n].id);
//			break;
//		    }
//		}
	    }
	    else
	    {
		ans.insert(q[1].id);
		ans.insert(q[2].id);
	    }
	}
    }
    cout<<ans.size()<<endl;
    for ( it=ans.begin();it!=ans.end();it++)
    {
	cout<<*it<<" ";
    }
    

	return 0;
}
