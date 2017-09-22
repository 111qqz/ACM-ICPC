/*************************************************************************
	> File Name: code/hdu/2149.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月22日 星期二 20时18分02秒
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
int n,m;
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
    while (scanf("%d %d",&m,&n)!=EOF) 
    {
	if (m<n+1)
	{
	    printf("%d",m);
	    for ( int i = m+1 ; i <= n; i++)
		printf(" %d",i);
	    printf("\n");
	    continue;
	}
	int tmp = m%(n+1);
	if (tmp>0)
	{
	    printf("%d\n",tmp);
	}
	else
	{
	    puts("none");
	}

    }
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
