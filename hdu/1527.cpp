/*************************************************************************
	> File Name: code/hdu/1527.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月01日 星期四 20时26分40秒
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
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
   int a,b;
  while (scanf("%d %d",&a,&b)!=EOF)
  {
      if (a<b) swap(a,b);
      int tmp =a-b ;
      if (b==int(tmp*(sqrt(5)+1)/2))
	{
	    puts("0");
	}
       else
	{
	    puts("1");
	}
  }
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
