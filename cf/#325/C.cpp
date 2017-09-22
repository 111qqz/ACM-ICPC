/*************************************************************************
	> File Name: code/cf/#325/C.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月12日 星期一 16时51分20秒
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
                 
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=4E3+7;
int n;
int ans[N];
int cnt;
int v[N],d[N],p[N];
bool vis[N];
bool hasgo[N];
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   ms(hasgo,false);
   scanf("%d",&n);
   for ( int i = 1 ; i <= n ;i++) scanf("%d %d %d",&v[i],&d[i],&p[i]);

   int now= 1 ;
   cnt = 0 ;
   ms(vis,false);
   while (now<=n)
   {
       if (hasgo[now]) 
	{
	    now++;
	    continue;
	}
	int redu = v[now];
       for ( int i = now+1 ; i<=n&&redu>0 ; i++)
       {
	   p[i]-=redu;
	   redu--;
       }
       for ( int i = now+1 ; i <= n ; i++)
       {
	   if (p[i]<0&&!hasgo[i])
	   {
	       cnt++;
	   //    cout<<"go id:"<<i<<endl;
	       vis[i] = true;
	       hasgo[i] = true;
	       for ( int j = i+1 ; j <= n ; j++)
	       {
		   p[j] -= d[i];
	       }
	   }
       }
       now++;
   }
   printf("%d\n",n-cnt);
   int sum = 0 ;
   for ( int i = 1 ; i<=n ; i++)
    {
	if (!hasgo[i])
	{
	    sum++;
	    ans[sum] = i ;
	}
    }
   for ( int i = 1 ; i <= sum ; i++)
    {
	if (i==sum) printf("%d\n",ans[i]);
	else printf("%d ",ans[i]);
    }
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
