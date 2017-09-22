/*************************************************************************
	> File Name: code/hdoj/2046.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月19日 星期四 23时13分17秒
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
#define fst first              
#define sec second      
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
const int inf = 0x3f3f3f3f;
const int N=55;
LL a[N];
int n;
int main()
{
  #ifndef  ONLINE_JUDGE 
//   freopen("in.txt","r",stdin);
  #endif

   a[0] = 1;
   a[1] = 2;
   for ( int i = 2 ; i <= 50 ; i++)
       a[i] = a[i-1] + a[i-2];

   while (scanf("%lld",&n)!=EOF)
   {
       cout<<a[n-1]<<endl;
   }
  
   
 #ifndef ONLINE_JUDGE  
  #endif
  fclose(stdin);
	return 0;
}
