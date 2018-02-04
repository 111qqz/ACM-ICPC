/*************************************************************************
	> File Name: code/2015summer/0714/EE.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月15日 星期三 23时58分45秒
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
LL ans;
LL n;
int len;
char st[20];
void dfs(int x,LL sum)
{
    if (x==len)
    {
	  if (sum==n)
		ans++;
	  return;
    }
    LL tmp = 0 ;
    for ( int i = x ; i < len ; i++)
    {
	  tmp = tmp*10+st[i]-'0';
	  dfs(i+1,sum+tmp);
	  if (x) dfs(i+1,sum-tmp);
    }
}
int main()
{
 
    while (scanf("%s",st)!=EOF)
    {
	  cin>>n;
	  len = strlen(st);
	  ans = 0;
	  dfs(0,0);
	  cout<<ans<<endl;
    }
	return 0;
}
