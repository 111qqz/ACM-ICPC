/*************************************************************************
	> File Name: code/bc/#50/1003.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月08日 星期六 19时22分23秒
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
LL ans [100];
LL c[70][70];
LL sum[70][70];
int n;
void init()
{
    memset(c,0,sizeof(c));
    memset(sum,0,sizeof(sum));
    c[2][1]=1;
    c[2][2]=3;
    c[2][3]=6;
    sum[2][1] = 0;
    for ( int i = 1 ; i <= 61 ; i++ )
    {
	c[2][i]=(i)*(i+1)/2;
	sum[2][i]=sum[2][i-1]+c[2][i];
    }
    for ( int i = 3 ; i <= 61 ; i ++)
    {
	for ( int j = 1 ; j <= 61-i ; j++)
	{
	    c[i][j]=sum[i-1][j];
	    sum[i][j]=sum[i][j-1]+c[i][j];
	}
    }

    
    
}
LL solve ( int x)
{
    LL res  = x;
    LL rm;
    LL rem;
    for ( int i = 2; i <= (x+2)/3; i ++)  //摆放的个数
    {
	rm = x - (3*i-2);
	res = res + c[i][rm+1];
    }
    return res;
}
int main()
{
    init();
    for ( int i = 1 ; i <= 61 ; i ++ )
    {
	ans[i] = solve (i);
    }
    while (scanf("%d",&n)!=EOF)
    {
	cout<<ans[n]<<endl;
    }
  
	return 0;
}
