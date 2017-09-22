/*************************************************************************
	> File Name: code/2015summer/searching/C.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: Tue 21 Jul 2015 01:07:51 PM CST
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
const int N =1E5+7;
int d[N];
int n,k;
void bfs()
{
    memset(d,-1,sizeof(d));
    queue<int>x;
    x.push(n);
    d[n]=0;
    while (!x.empty())
    {
	  int prex = x.front();x.pop();
	  int next[3];
	  next[0]=prex-1;
	  next[1]=prex+1;
	  next[2]=2*prex;
	  for ( int i = 0 ;  i < 3 ; i++ )
	  {
		if (next[i]>=0&&next[i]<=100000&&d[next[i]]==-1)
		{
		    d[next[i]]=d[prex]+1;
		    x.push(next[i]);
		}
	  }
    }
}
int main()
{
	  cin>>n>>k;
    bfs();
    cout<<d[k]<<endl;
	return 0;
}
