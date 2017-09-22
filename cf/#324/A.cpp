/*************************************************************************
	> File Name: code/cf/#324/A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月11日 星期日 23时32分46秒
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
int n,t;
int main()
{
  #ifndef  ONLINE_JUDGE 
 //  freopen("in.txt","r",stdin);
  #endif
   cin>>n>>t;
   if (n==1&&t==10)
    {
	puts("-1");
	return 0;
    }
   if (n==1)
    {
	cout<<t<<endl;
	return 0;
    }
   if (t==10)
    {
	for ( int i = 1 ; i <=n-1 ; i++)
	    cout<<1;
	cout<<0<<endl;
	return 0;
    }
   for ( int i = 1  ; i <= n ; i++)
       cout<<t;
   cout<<endl;
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
