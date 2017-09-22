/*************************************************************************
	> File Name: code/0920/F.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月20日 星期日 12时55分29秒
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
const long double eqs = 1E-11;
long double a[1111];
int main()
{
//  #ifndef  ONLINE_JUDGE 
 //   freopen("in.txt","r",stdin);  
 // #endif
    int T;
  a[0] = 0.0 ;
  for ( int i = 1 ; i <= 1111 ; i++)
    {
	a[i] = (a[i-1]+0.5)/2.0;
    }
   cin>>T;

   while (T--)
    {
	long double x = 0.0;
	scanf("%Lf",&x);
	for ( int i = 0 ; i <= 1000 ; i++)
	{
	    //cout<<fixed<<setprecision(9)<<a[i]<<endl;
	    if (fabs(x-a[i])<=eqs)
	    {
		//printf("%d\n",-1);
		puts("-1");
		break;
	    }
	    if (a[i]-x>eqs)
	    {
		printf("%d\n",i*4);
		break;
	    }
	}
    }
  
  
 // #ifndef ONLINE_JUDGE  
 //  fclose(stdin);
 //  #endif
	return 0;
}
