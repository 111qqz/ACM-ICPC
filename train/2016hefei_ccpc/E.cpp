/* ***********************************************
Author :111qqz
Created Time :2017年10月11日 星期三 15时34分52秒
File Name :E.cpp
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
#define PB push_back
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
const int N=1E4+7;
const LL mod =1E8+7;
//神TM 1E*8+7
LL dp[N];
char st[N];
int a[N];
int n;
LL solve( int num)
{
    if (num>2) return 0;
    ms(dp,0);
    if (num==1) dp[1] = 2;
    else dp[1] = 1;
    int x = 0;
    int y = num;
    for ( int i = 2 ; i <= n ; i++)
    {
	int z = a[i-1]-x-y;
	if (z<0||z>2) return 0;
	if (i==n)
	{
	    if (y+z!=a[n]) return 0;
	}
//	cout<<lst1<<" "<<lst2<<" "<<cur<<endl;
	if (z==1) dp[i] = dp[i-1]*2%mod;
	else dp[i] = dp[i-1] % mod;
	x  = y;
	y = z;
    }
   // printf("dp[n]:%d\n",dp[n]);
    return dp[n]%mod;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("./in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%s",st);
	    n = strlen(st);
	    for ( int i = 1 ; i <= n ; i++) a[i] = st[i-1]-'0';
	    LL ans = 0 ;
	    //cout<<"a:"<<endl;
	    //for ( int i = 1 ; i <= n ; i++) printf("%d%c",a[i],i==n?'\n':' ');
	    if (n==1) 
	    {
		if (a[1]==1) ans = 2;
		else if (a[1]==0||a[1]==2) ans=1; 
		else ans =  0;
	    }
	    else
	    for ( int i = 0 ; i <= a[1]  ; i++) ans = (ans + solve(i)) % mod;
	    printf("%lld\n",ans);
	}



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
