/*************************************************************************
	> File Name: code/bc/#57/1001.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月26日 星期六 19时04分34秒
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
const int N=1E3+7;
char str[N];
int len;
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
    int T;
    cin>>T;
    while (T--)
    {
	scanf("%s",str);
	len = strlen(str);
	int cnt = 0;
	int ans = 0 ;
	for ( int i = 0 ; i < len ; i++)
	{
	    if (str[i]=='(')
	    {
		cnt++;
	    }
	    else
	    {
		cnt--;
		if (cnt>=0)
		{
		    ans++;
		}
		if (cnt<0)
		    cnt = 0 ;
	    }
	}
	printf("%d\n",ans);
    }
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
