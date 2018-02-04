/*************************************************************************
	> File Name: code/cf/#323/BB.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月04日 星期日 01时07分59秒
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
const int N=1E3+7;
int a[N];
bool vis[N];
int n;
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
   cin>>n;
   for ( int i = 1 ; i<= n ;i++) scanf("%d",&a[i]);
   int cnt = 0 ;
   int dir = 1;
   int ans = 0 ;
   ms(vis,false);
   while (cnt<n)
   {
       if (ans%2==0)
       {
	   for ( int i = 1 ; i <= n ; i++)
	    {
		if (cnt>=a[i]&&!vis[i])
		{
		    cnt++;
		    vis[i] = true;
		}
	    }
//	   cout<<"cnt111:"<<cnt<<endl;
       }
       else
	{
	    for ( int i = n ; i >=1 ; i--)
	    {
		if (cnt>=a[i]&&!vis[i])
		{
		    cnt++;
		    vis[i] = true;
		}
	    }
//	    cout<<"cnt2 "<<cnt<<endl;
	}
       ans++;
  //     cout<<"cnt:"<<cnt<<" ans:"<<ans<<endl;
   }
   
   cout<<ans-1<<endl;
   
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
