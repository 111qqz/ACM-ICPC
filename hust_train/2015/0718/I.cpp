/*************************************************************************
	> File Name: code/2015summer/0718/I.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月18日 星期六 14时05分13秒
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
double calv(double a,double b,double c,double l,double m,double n)
{

    return sqrt((4*a*a*b*b*c*c-a*a*(b*b+c*c-m*m)*(b*b+c*c-m*m)-b*b*(c*c+a*a-n*n)*(c*c+a*a-n*n)-c*c*(a*a+b*b-l*l)*(a*a+b*b-l*l)+(a*a+b*b-l*l)*(b*b+c*c-m*m)*(c*c+a*a-n*n)))/12;
}

int main()
{

    double a,b,c,l,m,n;
    while(scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&c,&l,&n,&m) != EOF)
    {

	  printf("%.4lf\n",calv(a,b,c,l,m,n));
    }
    return 0;
}
