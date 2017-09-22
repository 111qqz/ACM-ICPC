/*************************************************************************
	> File Name: code/2015summer/0717/I.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com
	> Created Time: 2015年07月17日 星期五 11时19分39秒
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
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)
typedef long long LL;
typedef unsigned long long ULL;
const int N = 1E3+5;
char st[N];
int h[N],t[N];
int len;
int solve(int x)
{
    int head=x,tail=len;
    int res = 0;
    int k = 0;
    while (head<=tail)
    {
	  k++;
	   while (st[head]==st[tail])
	  {
	    res = res + 2;
	    head++;
	    tail--;
	  }
	   if (tail-head<=2)
	  {
		return res;
	  }
	   else
		{
		    res = 0;
		    head = x;
		    tail = len - k;

		}
    }
    return res;
}

int main()
{
    cin>>st;
    len = strlen(st);
    int index;
    int ans = -1;
    for ( int i = 0  ; i < len ; i++ )
    {

	  if ( solve(i)>ans)
	  {
		ans = solve(i);
		index = i;
	  }
    }
    for ( int i = index ; i <index+ans ; i++ )
    {
	  cout<<st[i];
    }
    cout<<endl;
	return 0;
}
