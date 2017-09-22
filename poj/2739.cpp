/*************************************************************************
	> File Name: code/poj/2739.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月25日 星期五 01时32分43秒
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
#include<cctype>
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
#define lr dying111qqz
using namespace std;
#define For(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
int pri[10005];
int n ;
int mx;
bool prime ( int n)
{
    if (n<=3) return true;
    for ( int i = 2 ; i*i<= n ; i++)
    {
	if (n%i==0) return false;
    }
    return true;
}

void solve()
{
    int head = 1;
    int tail = 1;
    int sum = 0 ;
    int ans = 0 ;
    while (pri[tail]<=n)
    {
	cout<<"asd"<<endl;
	sum = sum + pri[tail];
	if (sum>=n)
	{
	    while (sum>n)
	    {
		sum = sum - pri[head];
		head++;
	    }
	
	    if (sum==n)
	    {
		ans++;
	    }
	}
	   tail++;
    }
    printf("%d\n",ans);
}
int main()
{
  #ifndef  ONLINE_JUDGE 
  // freopen("in.txt","r",stdin);
  #endif
    
   int cnt = 0 ;
   for ( int i = 2 ; i <= 10005 ; i++)
    {
	if (prime(i))
	{
	    cnt++;
	    pri[cnt] = i ;
//	    if (i>10000) cout<<i<<endl;
	}
    }
    while (scanf("%d",&n)!=EOF&&n)
    {
	solve();
    }
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
