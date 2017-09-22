/* ***********************************************
Author :111qqz
Created Time :2015年12月15日 星期二 20时28分44秒
File Name :code/cf/problem/466C.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define fst first
#define sec second
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;
#define pi pair < int ,int >
#define MP make_pair

using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=5E5+7;
int n;
int a[N];
LL sum[N],rsum[N];
int p[N],rp[N];
int cnt,rcnt;
int b[N];
int c[N];
LL ans;
LL solve()
{
    LL total = sum[n];
    if (total%3!=0) return 0;
    LL ave = total/3;
    cnt = 0 ;
    for ( int i = 1 ; i <= n ; i++)
    {
	if (sum[i]==ave)
	{
	    cnt++;
	    p[cnt] = i;
	   // cout<<"i:"<<i<<endl;
	}
    }
    ms(b,0);
    for ( int i =  n ; i >= 1 ; i--)
    {
	if (rsum[i]==ave)
	{
	    b[i] = 1; //b[i]为1表示可以，为0表示不可以。
	}
    }
    c[n] = b[n]; //c[i]表示i..n一共有多少个b[i]可以。
    for ( int i = n-1  ; i >= 1 ; i--)
    {
	c[i] = c[i+1] + b[i];
    }
    
     
    LL res =  0 ;
    for (  int i = 1 ; i <= cnt ; i++)
    {
	res+= c[p[i]+2]; //中间至少隔一个，因为要分成三组。
    }
    return res;

}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n;
	sum[0] = 0 ;

	for ( int i = 1 ; i <= n ; i++)
	{
	    scanf("%d",&a[i]);
	    sum[i] = sum[i-1] + a[i];
	}
	rsum[n+1] = 0 ;
	for ( int i = n ; i >= 1 ; i --)
	{
	    rsum[i] = rsum[i+1] + a[i];
	}
	ans = solve();
	cout<<ans<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
