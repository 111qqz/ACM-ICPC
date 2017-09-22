/*************************************************************************
	> File Name: code/test/a.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月23日 星期三 19时12分53秒
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
 //  freopen("in.txt","r",stdin);
  #endif
    for ( int i = 10000; i*4<=99999 ;i ++)
    {
	int a,b,d,e;
	a = i /10000;
	e = i % 10;
	b = i/1000;
	b = b % 10;
	d = i/10;
	int a2,b2,e2,d2;
	int i2;
	i2 = i*4;
	a2 = i2/10000;
	e2 = i2%10;
	b2 = i2/1000;
	b2 = b2 % 10;
	d2 = i2/10;

	if (a==e2&&b==d2&&d==b2&&e==a2)
	{
	    cout<<i<<endl;
	    break;
	}
    
    }
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
