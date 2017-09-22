/*************************************************************************
	> File Name: code/cf/#315/C.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月11日 星期二 00时54分13秒
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
const int N=2E6+5;
int f[N],g[N];
bool prime( int x)
{
    if (x==1) return false;
    if (x<=3) return true;
    for ( int i = 2 ; i*i<=x ; i ++)
    {
	if (x%i==0)
	return false;
    }
    return true;
}
bool pal( int x)
{
    int a[100];
    int len=0;
    while(x)
    {
	len++;
	a[len]=x%10;
	x = x/ 10;
    }

    for ( int i = 1 ;i  <= len/2 ; i++)
    {
	if (a[i]!=a[len+1-i])
	    return false;
    }
    return true;
}
int main()
{
    int cnt = 0;
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
    for (int i = 1 ; i <= N-5 ; i ++)
    {
	if (prime(i))
	{
	    cnt++;

	//    pri[cnt]  = i;
	}
	f[i] = cnt;
    }
    int cnt2 = 0 ;
    for ( int i =1 ; i <=N-5 ; i++)
    {
	if (pal(i))
	{
	    cnt2++;

	}
	g[i] = cnt2;
    }
 //   for ( int i =1; i <= N-5; i ++)
 //   {
//	cout<<"i:"<<i<<"f[i]:"<<f[i]<<" g[i]:"<<g[i]<<"f[i]/g[i]:"<<f[i]*1.0/g[i]*1.0<<" g[i]/f[i]"<<g[i]*1.0/f[i]<<endl;
  //  }
    int p,q;
    int i = 0;
    scanf("%d %d",&q,&p);
    double r = p*1.0/q;
    for ( int i = N-5 ; i >= 1 ; i--)
    {
	if (r*f[i]<=g[i])
	{
	    cout<<i<<endl;
	    break;
	}
    }
    

	return 0;
}
