/*************************************************************************
	> File Name: code/51nod/1049.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月11日 星期日 17时01分49秒
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
int a[N];
int n;
LL ans,last;
int main()
{

  #ifndef  ONLINE_JUDGE 
 //  freopen("in.txt","r",stdin);
  #endif
   scanf("%d",&n);
   bool flag = false;
   for ( int i = 0  ; i < n ;i++)
    {
	scanf("%d",&a[i]);
	if (a[i]>=0)
	flag = true;
    }
   for ( int i = 0 ; i < n ; i++)
   {
       last = max(LL(0),last) + a[i];
       ans = max(ans,last);
   }
   if (!flag) ans = 0 ;
   cout<<ans<<endl;
  
   
 #ifndef ONLINE_JUDGE  
 // fclose(stdin);
  #endif
	return 0;
}
