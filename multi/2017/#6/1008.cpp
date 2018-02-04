/*************************************************************************
	> File Name: code/multi/#6/1008.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月06日 星期四 13时52分59秒
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
const int N=1E5+7;
struct Q
{
    int l,r;
    int id;
}q[N];
int n;
int rec[N];
bool vis[N];
bool cmp(Q a,Q b)
{
    if (a.r<b.r) return true;
    if (a.r==b.r&&a.l<b.l) return true;
    return false;
}
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
	memset(vis,false,sizeof(vis));
	memset(rec,0,sizeof(rec));
	scanf("%d",&n);
	for (  int i = 1 ; i <= n ; i++ )
	{
	    scanf("%d",&q[i].l);
	    q[i].id = i;
	}
	for ( int i = 1 ; i <= n ; i++ )
	{
	    scanf( "%d" , &q[i].r);
	}
	sort(q+1,q+n+1,cmp);
	int cur  = 0;
	for ( int i = 1 ; i <= n ; i++ )

	{
	    if (q[i].l==0)
	    {
		if (cur<=q[i].r)
		{
		    cur++;
		    vis[q[i].id]=true;
		    rec[cur]=q[i].id;
		}
	    }
	}
	for ( int i = 1 ; i <= n ; i++ )
	{
	    cout<<q[i].l<<" "<<q[i].r<<endl;
	}
	for ( int i = 1 ; i <= n ; i++ )
	{
	    if (vis[q[i].id]) continue;
	    if (cur>=q[i].l&&cur<=q[i].r)
	    {
		cur++;
		rec [cur]=q[i].id;
		vis[q[i].id] = true;
	    }
//	    if (cur<q[i].l)
//	    {
//		break;
//	    }
	}
	cout<<cur<<endl;
	for ( int i = 1 ; i <= cur  ; i ++ )
	{
	    cout<<rec[i]<<" ";
	}
	for ( int i = 1 ; i <= n ; i ++ )
	{
	    if (!vis[q[i].id])
	    {
		cout<<q[i].id<<" ";
	    }
	}
     }
	return 0;
}
