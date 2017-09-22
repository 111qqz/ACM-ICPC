/*************************************************************************
	> File Name: code/51nod/1001.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月19日 星期一 18时31分13秒
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
const int N=5E4+7;
int k,n;
int a[N];
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   scanf("%d %d",&k,&n);
   for ( int i = 0 ; i < n ; i ++) scanf("%d",&a[i]);
   sort(a,a+n);
   int j = n-1;
   bool flag = false;
   for ( int i = 0 ; i < n-1 ; i++)
   {
       while (i<j&&a[i]+a[j]>k) j--;
       if (a[i]+a[j]==k&&i<j)
       {
	   flag = true;
//	   cout<<"i:"<<i<<" j:"<<j<<endl;
	   printf("%d %d\n",a[i],a[j]);
       }
   }
   if (!flag) puts("No Solution");
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
