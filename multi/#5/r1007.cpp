/*************************************************************************
	> File Name: code/multi/#5/r1007.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月04日 星期二 12时55分56秒
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
    int cmd;
    int n;
    int mx = 0;
    int num = 0;
    int x;
    cin>>n;
    for ( int i = 0 ; i < n;  i++ )
    {
	scanf("%d",&cmd);
	if (cmd==1)
	{
	    num++;
	    scanf("%d",&x);
	    if (x>mx)
		mx = x;
	}
	if (cmd==2&&num!=0)
	{
	    num--;
	    if (num==0)
		mx = 0;
	}
	if (cmd==3)
	{
	    cout<<mx<<endl;
	}
    }
  
	return 0;
}
