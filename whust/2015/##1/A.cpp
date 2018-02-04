/*************************************************************************
	> File Name: code/whust/##1/A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月12日 星期三 13时38分02秒
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
const long double C = 1.6180339887;
const double eqs = 1E-6;
int a,b,g0,g1;
int main()
{
    cin>>a>>b>>g0>>g1;
    double delta = a*a*1.0+4*b*1.0;
    if (delta<0)
    {

	cout<<"NO"<<endl;
	return 0;
    }

    if (a*g1==0&&b*g0==0)
    {
	cout<<"NO"<<endl;
	return 0;
    }
    if (b==0)
    {
	cout<<"YES"<<endl;
	cout<<fixed<<setprecision(10)<<a*1.0<<endl;
	return 0;
    }
    if ( a==0 && b==1)
    {
	if (g0==g1)
	{
	    cout<<"YES"<<endl;
	    cout<<fixed<<setprecision(10)<<1.0<<endl;
	}
	if (g0==-g1)
	{
	    cout<<"YES"<<endl;
	    cout<<fixed<<setprecision(10)<<1.0<<endl;
	}
	return 0;
    }
    if (a==0)
    {
	if (g0!=0)
	{
	    if (b*g0*g0==g1*g1)
	    {
		if (g0*g1<0)
		{
		    cout<<"YES"<<endl;
		    cout<<fixed<<setprecision(10)<<-1.0<<endl;
		    return 0;
		}
		else
		{
		    cout<<"YES"<<endl;
		    cout<<fixed<<setprecision(10)<<1.0<<endl;
		    return 0;
		}
	    }
	}
	cout<<"NO"<<endl;
	return 0;
    }
    double lim1 = (a + sqrt(delta*1.0))/2.0;
    double lim2 = (a - sqrt(delta*1.0))/2.0;
    double c1 = (g1-lim2*g0)/(lim1-lim2);
    double c2 = (lim1*g0-g1)/(lim1-lim2);
    if (fabs(c1)<eqs)
    {
	cout<<"YES"<<endl;
	cout<<fixed<<setprecision(10)<<lim2<<endl;
	return 0;
    }
    if (fabs(c2)<eqs)
    {
	cout<<"YES"<<endl;
	cout<<fixed<<setprecision(10)<<lim1<<endl;
	return 0;
    }
    double r = lim2/lim1;
    if (fabs(r)<1)
    {
	cout<<"YES"<<endl;
	cout<<fixed<<setprecision(10)<<lim1<<endl;
    }
    else
    {
	cout<<"YES"<<endl;
	cout<<fixed<<setprecision(10)<<lim2<<endl;
    }


	return 0;
}
