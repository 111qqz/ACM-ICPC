/*************************************************************************
	> File Name: code/bc/#61/1001.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月31日 星期六 18时55分30秒
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
const int N=1E3+7;
int n;
int a[N];
int flag[N];

bool cmp( int a,int b)
{
    return a>b;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   while (scanf("%d",&n)!=EOF)
    {
	ms(flag,-1);
	bool ok = false;
	int haszero = 0;
	for ( int i = 0 ; i < n ; i++)
	{
	    scanf("%d",&a[i]);
	    flag[a[i]] = i;
	    if (a[i] ==0) haszero++;
	}
	sort(a,a+n);
	if (haszero)
	{
	    if (haszero>=3)
	    {
		ok = true;
	    }
	    for ( int i = 0 ;i < n -1 ; i ++)
		if (a[i]==a[i+1]&&a[i]!=0)
		{
		    ok = true;
		    break;
		}
	}
	else
	{
	    for ( int i = 0 ; i < n-1 ; i++)
		for ( int j = i + 1 ; j < n ; j++)
		{
		    int tmp = a[i]+a[j];
		    if (flag[tmp]!=-1)
		    {
			ok  = true;
			break;
		    }
		}
	}


	if (!ok)
	{
	    puts("NO");
	}
	else
	{
	    puts("YES");
	}
    }
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
