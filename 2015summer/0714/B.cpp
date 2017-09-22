/*************************************************************************
	> File Name: code/2015summer/0714/B.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月14日 星期二 15时45分14秒
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
const int N=1E3+5;
const int C=100;
int n;
int ans[20];
bool l[N],tx[N],ty[N];
void solve(int i)
{
    for ( int j = 1 ; j <= n; j++ )
    {
	  if (!l[j]&&!tx[i-j+C]&&!ty[i+j+C])
	  {
		l[j]=true;
		tx[i-j+C]=true;
		ty[i+j+C]=true;
		if (i<n) solve(i+1);
		else ans[0]++;
		l[j]=false;
		tx[i-j+C]=false;
		ty[i+j+C]=false;
	  }

    }
}
void init()
{
    ans = 0;
    for ( int i = 0 ; i <=15;i++)
	  l[i]=false;
    for ( int i=50;i<=150;i++)
    {
	  tx[i]=false;
	  ty[i]=false;
    }
}
int main()
{
    memset(ans,-1,sizeof(ans));
    while (scanf("%d",&n)!=EOF)
    {	  
	  
	  if (n==0) break;
	  if (ans[n]!=-1) cout<<ans[n]<<endl;
	  else
	  {
		
	    init();
	    solve(1);
	    ans[n]=ans[0];
	  

    }
  
	return 0;
}
