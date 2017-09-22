/*************************************************************************
	> File Name: code/whust/#7/J.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月01日 星期六 12时55分14秒
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
const int N=5E4+7;
int n;
double x[N],w[N];
int main()
{
    int T;
    cin>>T;
    int cas=0;
    while (T--)
    {
	cas++;
	scanf("%d",&n);
	double res = 0;
	double sum = 0;
	for ( int i = 0 ; i< n ; i++ )
	{
	    scanf("%lf %lf",&x[i],&w[i]);
	    res = res + x[i]*w[i];
	    sum = sum + w[i];
	}
	 double p = res/sum;
	long double ans  = 0;
	cout<<p<<endl;
//	    p = pow(p,1.0/3);
	    for ( int i = 0 ; i < n ;i++ )
	{
	    ans = ans+ pow(fabs(x[i]-p),3.0)*w[i];
	    cout<<ans<<endl;
	}
	printf("Case #%d: %lld\n",cas,LL(ans+0.5));
	
	
	
    }
  
	return 0;
}
