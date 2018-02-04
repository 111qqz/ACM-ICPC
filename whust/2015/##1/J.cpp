/*************************************************************************
	> File Name: code/whust/##1/J.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月12日 星期三 12时40分45秒
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
int x,y,p,q,n,m,k;
int ans;
int mod;
bool fb[15000];
int a[20],b[20];
int h( int x,int y)
{
    return x%4007 + y % 3733 + 5;
}
bool ok ( int x,int y)
{
    if (x<1||x>n||y<1||y>m)
	return false;
    for ( int i =  1 ; i <= k ; i++ )
    {
	if (a[i]==x&&b[i]==y)
	{
	    return false;
	}
    }
    return true;
}

void dfs( int x,int y)
{

//    cout<<"x:"<<x<<" y:"<<y<<endl;
    if (x==n&&y==m)
    {
	ans++  ;   
	ans =ans % mod;
	return;
    }
    if (ok(x+p,y+q))
    dfs(x+p,y+q);
    if (ok(x+q,y+p))
    dfs(x+q,y+p);

}


int main()
{

    cin>>p>>q>>mod;
    cin>>n>>m;
    cin>>k;
    memset(fb,false,sizeof(fb));
    for ( int i = 1 ;i  <= k; i ++ )
    {
	scanf("%d %d",&x,&y);
	a[i] = x;
	b[i] = y;
    }
    ans = 0 ;
    dfs(1,1);
    cout<<ans<<endl;
	return 0;
}
