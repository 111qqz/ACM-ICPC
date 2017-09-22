/*************************************************************************
	> File Name: code/whust/#7/I.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月01日 星期六 13时34分59秒
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
const int N=166;
int d[N][N];
bool v[N];
int ans[N];
int n,m;
bool flag;
void dfs(int num,int x)
{
    if (flag) return;
    if (num==n&&d[ans[1]][ans[n]]==1)
    {
	for ( int i = 1 ; i< n ; i++)
	    cout<<ans[i]<<" ";
	cout<<ans[n]<<endl;
	flag = true;
	return;
    }
    for (int i = 1 ; i <= n ; i++)
    {
	if  (!v[i]&&i!=x&&d[i][x]==1)
	{
	    v[i]=true;
	    ans[num+1]=i;
	    dfs(num+1,i);
	    v[i]=false;
	}

    }
}
int main()
{
    while (scanf("%d %d",&n,&m)!=EOF)
    {
	memset(v,false,sizeof(v));
	memset(d,0,sizeof(d));
	memset(ans,0,sizeof(ans));
	int x,y;
	for ( int i =  0 ; i < m ; i ++ )
	{
	    scanf("%d %d",&x,&y);
	    d[x][y]=1;
	    d[y][x]=1;
	}
	v[1]=true;
	ans[1]=1;
	flag = false;
	dfs(1,1);
	if (!flag)
	{
	    cout<<"no solution"<<endl;
	}
	
    }
	return 0;
}
