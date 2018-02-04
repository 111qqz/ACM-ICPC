/*************************************************************************
	> File Name: code/cf/#321/A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月23日 星期三 20时50分00秒
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
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
#define lr dying111qqz
using namespace std;
#define For(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=1E5+7;
int a[N];
int n;
int main()
{
  #ifndef  ONLINE_JUDGE 
//   freopen("in.txt","r",stdin);
  #endif
   scanf("%d",&n);
   for ( int i = 1 ; i <= n ; i++)
    {
	scanf("%d",&a[i]);
    }
   int ans = -1;
   int tmp = 0;
   a[0] = 0 ;
   for ( int i = 1 ; i <= n ; i++ )
    {
	if (a[i]>=a[i-1])
	{
	    tmp++;
	}
	else
	{
	    tmp = 1 ;
	}
//	cout<<i<<"  "<<tmp<<endl;
	ans = max(tmp,ans);

    }
    cout<<ans<<endl;
      
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
