/*************************************************************************
	> File Name: code/poj/p3414.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月25日 星期六 14时27分53秒
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
const int N=1E2+5l
void bfs()
{
    memset(d,-1,sizeof(d));
    queue<int>x;
    queue<int>y;
    x.push(a);
    y.push(b);
    d[a]=0;
    d[b]=0;
    while (!x.empty()&&!y.empty())
    {
	  int px = x.front();x.pop();
	  int py = y.front();y.pop();
    }

}
int main()
{
    cin>>a>>b>>c;

  
	return 0;
}
