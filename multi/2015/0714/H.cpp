/*************************************************************************
	> File Name: code/2015summer/0714/H.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月14日 星期二 20时37分33秒
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
const int N=1E2+5;
int n;
int a[N],b[N],c[N];
bool ok(int w,int x,int y,int z)
{
    int p[2][10];
    int k = 0;
    int sum1 = 0 ;
    int sum2 = 0;
    bool v[10];
    memset(p,0,sizeof(p));
    memset(v,false,sizeof(v));
    while (w)
    {
	  p[0][k]=w%10;
	  k++;
	  w = w/10;
    }
    k  = 0;
    while (x)
    {
	  p[1][k]=x%10;
	  k++;
	  x = x/10;
    }
    for ( int i = 0 ; i <4 ; i++ )
    { 
	  if (p[0][i]==p[1][i])
	  {
		sum2++;
	  }
    }
    for ( int i = 0 ; i < 4 ; i++)
	  for ( int  j = 0 ; j < 4 ; j++)
	  {
		if (p[0][i]==p[1][j]&&!v[j])
		{
		    sum1++;
		    v[j]=true;
		    break;
		}
	  }

    if (sum1==y&&sum2==z)
	  return true;
    return false;
    
}
int main()
{
    while (scanf("%d",&n)!=EOF&&n)
    {
	  int k = 0;
	  int p;
	  for ( int i = 0 ; i < n ; i++ )
	  {
		scanf("%d %d %d",&a[i],&b[i],&c[i]);
	  }
	  for ( int i = 1000 ; i <=9999 ; i++ )
	  {
		bool flag=false;
		for ( int j = 0 ; j < n ; j++ )
		{
		    if (!ok(i,a[j],b[j],c[j]))
		    {
			  flag = true; 
			  break;
		    }
		}
		if (!flag)
		{
		    k++;
		    p = i;
		}
	  }
	  if (k==1)
	  {
		cout<<p<<endl;
	  }
	  else
	  {
		cout<<"Not sure"<<endl;
	  }
    }

	return 0;
}
