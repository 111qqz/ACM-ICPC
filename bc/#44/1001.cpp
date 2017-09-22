/*************************************************************************
	> File Name: code/bc/#44/1001.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月29日 星期三 14时45分01秒
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
    int T;
    cin>>T;
    int cas =0;
    int score;
    int a[10];
    int x,y;
    a[1]=1000;
    a[2]=1500;
    a[3]=2000;
    a[4]=2500;
    while (T--)
    {
	cas++;
	score = 0;
	for ( int i = 1; i  <= 4 ; i ++ )
	{
	    scanf("%d %d",&x,&y);
	    score+= max((int)(a[i]*0.4),a[i]/250*(250-x)-y*50);
	}
	printf("Case #%d: %d\n",cas,score);
    }
  
	return 0;
}
