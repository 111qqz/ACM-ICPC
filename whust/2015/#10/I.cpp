/*************************************************************************
	> File Name: code/whust/#10/I.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月07日 星期五 12时50分56秒
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
int n,k;
int main()
{
    int cas = 0 ;
    while (~scanf("%d %d",&n,&k))
    {
	cas++;
	printf("Case %d: ",cas);
	int rm = n-2*k;
	if (rm%2==1)
	{
	    cout<<"Bob"<<endl;
	}
	else
	{
	    cout<<"Alice"<<" "<<max(k-1,1)<<endl;
	}

    }
  
	return 0;
}
