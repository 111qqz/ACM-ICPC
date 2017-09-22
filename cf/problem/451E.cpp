/* ***********************************************
Author :111qqz
Created Time :2016年03月02日 星期三 20时54分07秒
File Name :code/cf/problem/451E.cpp
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
const LL mod = 1E9+7;
int n;
LL s;
LL f[35];

int ny[35];
LL ksm(LL a,LL b)   //快速幂
{
    LL res = 1;
    while (b)
    {
	if (b&1) res = (res*a)%mod;
	b>>=1;
	a = (a*a)%mod;
    }
    return res;
}

void getny()  //预处理逆元
{
    ms(ny,0);
    for ( int i = 1 ; i <= 35 ; i++)
    {
	ny[i] = ksm(i,mod-2);
    }
}
void gny()
{
    LL val=1  ;
    for ( LL i = 1 ; i <= 20 ; i++) val = val*i%mod;
    ny[20]=ksm(val,mod-2);
    for ( LL i = 19 ; i+1 ; i--) ny[i]=(ny[i+1]*(i+1))%mod;
}


LL cal( LL x,LL y)   //lucas 定理求组合数
{
    LL res  = 1LL;
    for (LL  i = x ; i > x-y ;  i--)  res = (res*(i%mod))%mod;
    res = (res*ny[y])%mod;
    return res;
}
LL  solve(LL x,LL s)
{
    if (s<0) return 0;
    if (x==n+1) return cal(s+n-1,n-1);
    return (solve(x+1,s)-solve(x+1,s-f[x]-1)+mod)%mod;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	gny();
	cin>>n>>s;
	for ( int i = 1 ; i <= n ; i++)
	{
	    cin>>f[i];
	}

	LL ans = solve(1,s)%mod;
	

	cout<<ans<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
