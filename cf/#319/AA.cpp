/*************************************************************************
	> File Name: code/cf/#319/AA.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月15日 星期二 19时41分47秒
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
int main()
{
  #ifndef  ONLINE_JUDGE 
    freopen("in.txt","r",stdin);
  #endif
    int n,x;
    int ans = 0 ;
    cin>>n>>x;
    for ( int i = 1 ; i <= n ; i++)
    {
	if (x%i==0&&x/i<=n)
	{
	    ans++;
	}
	
    }
    cout<<ans<<endl;
  
  
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
