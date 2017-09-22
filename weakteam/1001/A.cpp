/*************************************************************************
	> File Name: code/weakteam/1001/A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月01日 星期四 11时29分24秒
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
const  double eqs = 1E-8;
int n;
int a[N];

int main()
{
//  #ifndef  ONLINE_JUDGE 
//   freopen("in.txt","r",stdin);
//  #endif

   while (scanf("%d",&n)!=EOF)
   {
       for ( int i = 0 ; i < n ; i++) scanf("%d",&a[i]);

       bool flag = true;
       for ( int i = 0 ; i < n ; i++)
	{
	    double tmp;
	    tmp = sqrt(a[i]);
	    if (fabs(tmp-int(tmp))<eqs)
	    {
		continue;
	    }
	    else
	    {
		flag = false;
		break;
	    }
	}
        if (flag)
	{
	    puts("Yes");
	}
	else
	{
	    puts("No");
	}
   }
      
   
// #ifndef ONLINE_JUDGE  
//  fclose(stdin);
//  #endif
	return 0;
}
