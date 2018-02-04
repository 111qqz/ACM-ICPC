/*************************************************************************
	> File Name: code/whust/#4/L.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月26日 星期日 12时34分34秒
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
const int N=2E5+9;
int n,w;
int a[N];
int main()
{
    cin>>n>>w;
    for ( int i = 1 ; i <= 2*n ; i++ )
    {
        scanf("%d",&a[i]);
    }

    sort(a+1,a+2*n+1);

    long double ans;
   // for ( int i = 1; i <=2*n ; i++ )
   //    cout<<a[i]<<endl;
    if (a[1]*2>=a[n+1])
    {
        ans =1.5*n*a[n+1];
       // cout<<ans<<endl;
    }
    else
    {
        ans = 3*n*a[1];
          //  cout<<ans<<endl;
    }
    if (w<ans)
        ans = w*1.0;
    cout<<fixed<<setprecision(6)<<ans<<endl;

    return 0;
}
