/*************************************************************************
	> File Name: code/51nod/learn/greedy/2.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月05日 星期一 19时24分32秒
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
const int N=1E4+5;
int n;
struct Q
{
    int t;
    bool sta;
}q[2*N];

bool cmp(Q a,Q b)
{
    return a.t<b.t;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   scanf("%d",&n);
   for ( int i = 0 ; i < 2*n ; i++)
   {
       scanf("%d",&q[i].t);
       if (i%2==0)
       {
	   q[i].sta = true;
       }
       else
	{
	   q[i].sta = false;
	}
   }
   sort(q,q+2*n,cmp);
   int ans = -1;
   int cnt = 0;
   for ( int i = 0 ; i < 2*n ; i++)
   {
       if (q[i].sta)
       {
	    cnt++;
       }
       else
	{
	    cnt--;
	}
       ans = max(ans,cnt);
   }
   printf("%d\n",ans);
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
