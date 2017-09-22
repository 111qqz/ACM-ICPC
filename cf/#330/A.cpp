/*************************************************************************
	> File Name: code/cf/#330/A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月09日 星期一 13时40分00秒
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
#define fst first              
#define sec second      
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
const int inf = 0x3f3f3f3f;
const int N=2E2+7;
int a[N][N];
int n,m;
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   scanf("%d %d",&n,&m);

       ms(a,0);
       for ( int i = 1 ; i <= n ; i++)
	   for ( int j = 1 ; j <= 2*m ; j++)
	       scanf("%d",&a[i][j]);

       int cnt = n*m;
       for ( int i = 1 ; i <= n ; i++)
	{
	    for ( int j = 1 ; j <= 2*m-1 ; j = j+2)
	    {
		if (a[i][j]==0&&a[i][j+1]==0)
		{
		    cnt--;
		}
	    }
	}
       printf("%d\n",cnt);
   
  
   
 #ifndef ONLINE_JUDGE  
  #endif
  fclose(stdin);
	return 0;
}
