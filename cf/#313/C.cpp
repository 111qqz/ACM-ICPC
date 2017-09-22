/*************************************************************************
	> File Name: code/#313/C.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月17日 星期一 07时13分54秒
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
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x7fffffff;
int main()
{
    int a[10];
    int b[5];
    for ( int i = 1 ; i <= 6 ; i++)
    {
	cin>>a[i];
    }
    memset(b,0,sizeof(b));
    for ( int i = 1 ; i <= 6 ; i++)
    {
	if (i<=3)
	{
	    b[0] = b[0] + a[i] ;
	}
	if (i%2==1)
	{
	    b[i/2+1] = a[i];
	}
    }
    int ans;
    ans = b[0]*b[0]-b[1]*b[1]-b[2]*b[2]-b[3]*b[3];
    cout<<ans<<endl;
  
	return 0;
}
