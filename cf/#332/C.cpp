/*************************************************************************
	> File Name: code/cf/#332/C.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月21日 星期六 03时14分55秒
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
const int N=1E5+7;
int n;
int a[N];
int l[N],r[N];
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
   cin>>n;
   for ( int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);
   r[n+1] = inf;
   for ( int i = n ; i >= 0 ; i --) r[i] = min(r[i+1],a[i]);
   int mx = -1;
   int cnt = 0 ;
   for ( int i = 1 ; i <= n ; i++)
    {
	mx = max(mx,a[i]);
	if (mx<=r[i+1])
	    cnt++,mx = -1;
    }
    printf("%d\n",cnt);
  
   
 #ifndef ONLINE_JUDGE  
  #endif
  fclose(stdin);
	return 0;
}
