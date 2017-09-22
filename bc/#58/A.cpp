/*************************************************************************
	> File Name: code/bc/#58/A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月08日 星期四 19时21分56秒
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
const int N=505;
int a[N];
int b[N];
int m,n;
int sum1,sum2;

bool cmp( int a,int b)
{
    return a>b;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
    int T;
    cin>>T;
    while (T--)
    {
	scanf("%d %d",&n,&m);
	for ( int i = 0 ;i  < n;  i++)
	{
	    scanf("%d",&a[i]);
	}
	for ( int i = 0 ; i < n ; i++) scanf("%d",&b[i]);

	sort(a,a+n);
	sort(b,b+n,cmp);
	sum1 = 0 ;
	sum2 = 0 ;
	for ( int i = 0 ; i < m ; i++)
	{
	    sum1+=a[i];
	    sum2+=b[i];
	}
	if (sum1>sum2)
	{
	    puts("YES");
	}
	else
	{
	    puts("NO");
	}
    }
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
