/*************************************************************************
	> File Name: code/2015summer/0720/H.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: Mon 20 Jul 2015 10:10:40 AM CST
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
int n,k,x,y,ans;

bool root( int x)
{
    if (f[x]!=x)
    {
	  rank[x]=(rank[x]+rank[f[x]])%3;
	  f[x]=root(f[x]);
    }
    return f[x];
}
bool union(int kind,int x,int y)
{
    int xx=root(x);
    int yy=root(y);
    if (xx==yy)
    {
	  if (kind==1&&rank[x]!=rank[y]) return false;
	  if (kind==2)
	  {
		if (rank[x]==0&&rank[y]!=2) return false;
		if (rank[x]==1&&rank[y]!=0)return false;
		if (rank[x]==2&&rank[y]!=1) return false;
	  }
	  return true;
    }
    f[xx]=yy;
    if (kind==2)
    {
	  rank[xx]=(rank[yy]-rank[xx]+3+1)%3;
    }
    else
    {
	  rank[xx]=(rank[yy]-rank[xx]+3)%3;
    }
    return true;
}
void init()
{
    for ( int i = 0  ;  i< N ; i++)
    {
	  rank[i] =  0;
	  f[i] = 1;
    }
}
int main()
{
  scanf("%d %d",&n,&k);
  ans = 0;
  init();
  while (k--)
  {
	scanf("%d %d %d",&d,&x,&y);
	if (x>n||y>n) 
	{
	    ans++;
	    continue;
	}
	if (d==2&&x==y)
	{
	    ans++;
	    continue;
	}
	if (!union(d,x,y))
	{
	    ans++;
	}
	cout<<k<<endl;
  }
	return 0;
}

