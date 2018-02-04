/*************************************************************************
	> File Name: code/2015summer/0714/L.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com
	> Created Time: 2015年07月17日 星期五 15时28分38秒
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
const int N=30;
int sum;
int s,n;
int a[N];
int cnt[N];

bool cmp(int x,int y)
{
    if (x>y) return true;
    return false;
}
int main()
{

    int cas;
    scanf("%d",&cas);
    while (cas--)
    {
	  memset(cnt,0,sizeof(cnt));
	  sum = 0;
	  scanf("%d",&s);
	  scanf("%d",&n);
	  for ( int i = 0 ; i  < n ; i ++ )
	  {
		scanf("%d",&a[i]);
		sum = sum + a[i]*a[i];
		cnt[a[i]]++;
	  }
	  if (sum!=s*s)
	  {
		printf("HUTUTU!\n");
		return 0;
	  }
	  sort(a,a+n,cmp);
	  if (a[0]+a[1]>s)
	  {
		printf("HUTUTU!\n");
			  return 0;
	  }
	  for ( int i = 1 ; i <= 10; i++ )
	  {
		if (cnt[i]==0) continue;
		int tmp = n/a[i];
		if (2*tmp-1<cnt[i])
		{
		    printf("HUTUTU!\n");
		    return 0;
		}
	  }

	  printf("KHOOOOB!\n");
    }
	return 0;
}
