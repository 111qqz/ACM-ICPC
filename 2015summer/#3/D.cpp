/*************************************************************************
	> File Name: code/2015summer/#3/D.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月28日 星期二 13时47分48秒
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
const int N=5E5+7;
int a[N],b[N];
int n;
int main()
{
    cin>>n;
    int x;
    int top = -1;
    LL ans = 0;
    for ( int i = 1 ; i <= n ; i++ )
    {
	  scanf("%d",&x);
	  while (top>=1&&a[top-1]>=a[top]&&a[top]<=x)
	  {
	      ans = ans + min(x,a[top-1]);
	      top--;
	  }
	  top++;
	  a[top]=x;
    }                                                        


    sort(a,a+top+1);
    for ( int i = 0 ; i <top-1 ; i++)
    {
	ans = ans + a[i];
    }
    cout<<ans<<endl;
    
  
	return 0;
}
