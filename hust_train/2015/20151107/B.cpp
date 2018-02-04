/*************************************************************************
	> File Name: code/hust/20151107/B.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月07日 星期六 13时30分54秒
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
const int N=5E2+7;
char str[N][2007];
int n;
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
   int T;
   scanf("%d",&T);
   int cas = 0;
   while (T--)
   {   cas++;
       scanf("%d",&n);
       for ( int i = 1 ; i <= n ; i++) scanf("%s",str[i]);
       
       bool hasres = false;
       int ans = -1;  //对于每个，分别向前后找.
       for ( int i = n-1 ; i >= 1 ; i--)
	{
	    if (strstr(str[i+1],str[i])==NULL)
	    {
		ans = max(ans,i);
		
		for ( int j = i+1 ; j <= n ; j++)
		    if (strstr(str[j],str[i])==NULL)
		    {
			ans = max(ans,j);
		    }
	    }
	}
    

      // printf("%d\n",ans);
       printf("Case #%d: %d\n",cas,ans);
   }
  
   
 #ifndef ONLINE_JUDGE  
  #endif
  fclose(stdin);
	return 0;
}
