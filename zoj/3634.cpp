/*************************************************************************
	> File Name: code/zoj/3634.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月27日 星期二 13时46分35秒
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
                 
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=1E5+7;
double a[N],b[N],dp_a[N],dp_m[N];
int n;
int x,y;
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   while (scanf("%d %d %d",&n,&x,&y)!=EOF)
    {
	for ( int i = 1 ; i <= n ; i++) scanf("%lf %lf",&a[i],&b[i]);
	
	ms(dp_a,0);
	ms(dp_m,0);
	dp_a[n] = b[n];
	dp_m[n] =max(1.0,1.0/a[n]*b[n]); 

	for ( int  i = n-1 ; i >=1 ; i--)
	{
	    dp_a[i] = dp_m[i+1]*b[i]+dp_a[i+1];	    //转移方程还是没太想清楚TAT  主要是dp_m[i+1]*b[i]这部分。。。再想一下
	    dp_m[i] = max(dp_m[i+1],1.0/a[i]*dp_a[i]);
	}
	printf("%.2f\n",x*dp_m[1]+y*dp_a[1]);
    }
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
