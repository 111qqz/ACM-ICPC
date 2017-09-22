/*************************************************************************
	> File Name: code/bc/#61/r1002.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月31日 星期六 20时01分12秒
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
                 
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
int n,t,s;
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   while (scanf("%d %d %d",&n,&s,&t)!=EOF)
    {
	if (s==t&&n!=1)
	{
	     puts("-1");
	    continue;
	}
	if (s==1&&t==n)
	{
	    printf("0\n");
	    continue;
	}
	if (s==n&&t==1)
	{
	    printf("0\n");
	    continue;
	}
	if (s==1)
	{
	    printf("1\n");
	    continue;
	}
	if (t==1)
	{
	    puts("1");
	    continue;
	}
	if (abs(s-t)==1)
	{
	    puts("1");
	    continue;
	}
	puts("2");
    }
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
