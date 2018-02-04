/*************************************************************************
	> File Name: code/loj/1185.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月12日 星期三 00时08分21秒
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
const int N=1E2+5;
int n,m;
bool d[N][N],vis[N];
int x,y;
int ans;
bool v[N];
void dfs( int x,int num)
{
   // cout<<"x:"<<x<<" num:"<<num<<endl;
    if (num%2==0&&!v[x])
    {
	ans++;
	v[x] = true;
//	cout<<"x:"<<x<<endl;
    }
    for ( int i = 1 ; i <= n ; i++  )
    {
	if (vis[i]) continue;
	if (x==i) continue;
	if (d[x][i])
	{
	    vis[i] = true;
	    dfs(i,num+1);
	        vis[i] = false;
	}
    }
}
int main()
{

    int T;
    int cas = 0;
    cin>>T;
    while (T--)
    {
	cas++;
	memset(d,false,sizeof(d));
	memset(vis,false,sizeof(vis));
	memset(v,false,sizeof(v));
	scanf("%d %d",&n,&m);
	 ans = 0;
	for ( int i = 1 ; i <= m ; i++ )
	{
	    scanf("%d %d",&x,&y);
	    d[x][y] = true;
	    d[y][x] = true;
	}
	dfs(1,1);
	printf("Case %d: %d\n",cas,ans);
    }
	return 0;
}
