/*************************************************************************
	> File Name: code/cf/#325/A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月12日 星期一 16时50分54秒
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
const int N=1E3+5;
int a[N];
int n ;
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
   scanf("%d",&n);
   ms(a,0);
   int cnt = 0 ;
   for ( int i =1 ; i <= n ; i++) scanf("%d",&a[i]);

   for ( int i = 1 ; i<= n ; i++)
   {
       if (a[i]==1) cnt++;
   }
   for ( int i = 2 ; i <= n-1 ; i++)
    {
	if (a[i]==0&&a[i-1]==1&&a[i+1]==1) cnt++;
    }
   cout<<cnt<<endl;
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
