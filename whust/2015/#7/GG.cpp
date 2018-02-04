/*************************************************************************
	> File Name: code/whust/#7/GG.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月01日 星期六 15时13分26秒
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
const int N=2E2+5;
LL  a[8][N];
LL b[N*N],c[N*N];
LL n;
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
	cin>>n;

//	scanf("%I64d",&n);
	for ( int i = 1 ; i <= 5 ; i++ )
	{
	    for ( int j = 1 ; j <= n ; j++ )
	    {
		//	scanf("%lld",&a[i][j]);
		   cin>>a[i][j];
	    }
	}
	int cnt = 0;
	for ( int i = 1 ; i <= n ; i++)
	{
	    for ( int j = 1 ; j <= n ; j++ )
	    {
		cnt++;
		b[cnt]=a[1][i]+a[2][j];
	    }
	}
	int cnt2 = 0;
	for ( int i = 1 ; i <= n ; i++ )
	{
	    for ( int j = 1  ; j <= n ; j ++)
	    {
		cnt2++;
		c[cnt2]=a[3][i]+a[4][j];
	    }
	}
	sort(b+1,b+cnt+1);
	sort(c+1,c+cnt2+1);
	bool flag = false;
	for ( int i = 1 ; i<=n ; i++)
	{
	    int j = 1;
	    int k = n;
	    while (j<=cnt&&k>=1)
	    {
		if (b[j]+c[k]==-a[5][i])
		{
		    flag = true;
		    break;
		}
		if (b[j]+c[k]>-a[5][i]) k--;   //不能写成while ,i和j要同步动
		if (b[j]+c[k]<-a[5][i]) j++;
	    }
	    if (flag)
	    {
		break;
	    }
	}
	if (flag)
	{
	    printf("Yes\n");
	}
	else
	{
	    printf("No\n");
	}
    
    }
	return 0;
}
