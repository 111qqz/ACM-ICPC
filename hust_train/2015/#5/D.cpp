/*************************************************************************
	> File Name: code/2015summer/#5/D.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月30日 星期四 13时17分26秒
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
int s,m,p;
double ans;

double cal(double x,int n)
{
    double res = 1.0;
    for ( int i = 1 ; i <= n ; i++ )
    {
	res = res * x;
    }
  //  cout<<"res:"<<res<<endl;
    return res;
}
int main()
{
    cin>>s>>m>>p;
    double sum = 0;
    double per = p*1.0/100+1;
    for ( int i = 1 ; i <= m;  i++ )
    {
	sum=sum+1.0/cal(per,i);
//	cout<<"sum:"<<sum<<endl;
    }
 //   cout<<sum<<endl;
    cout<<fixed<<setprecision(5)<<s*1.0/sum<<endl;
  
	return 0;
}
