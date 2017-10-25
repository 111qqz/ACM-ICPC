/* ***********************************************
Author :111qqz
Created Time :2017年10月25日 星期三 13时55分25秒
File Name :C.cpp
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
const LL mod = 998244353;
const int N=5005;
LL C[N][N];
LL fac[N];
void init()
{
    C[1][0] = C[1][1] = 1;
    C[2][0] = C[2][2] = 1;
    C[2][1] = 2;
    for ( int i = 3 ; i < N ; i++)
    {
	for ( int j = 0 ; j  <= i ; j++)
	{
	    if (j==0)
	    C[i][j] = 1;
	    else C[i][j] = (C[i-1][j] + C[i-1][j-1])%mod;
	}
    }
    fac[0] = fac[1] = 1;
    for ( int i = 2 ; i < N ; i++) fac[i] = (fac[i-1] * i)%mod;
}
int a,b,c;
LL ans = 1;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	init();
	cin>>a>>b>>c;
	LL cur = 0;
	for ( int i = 0 ; i <= min(a,b) ; i++)
	{
	    cur = ( cur + C[a][i] * C[b][i] % mod * fac[i] % mod) %mod;
	}
	ans = ans * cur % mod;
	cur = 0 ;
	for ( int i = 0 ; i <= min(a,c) ; i++)
	    cur = ( cur + C[a][i] * C[c][i] % mod * fac[i] % mod ) % mod;
	ans = ans * cur % mod;
	cur = 0 ;
	for ( int i = 0 ; i <= min (b,c) ; i++)
	    cur = ( cur + C[b][i] * C[c][i] % mod * fac[i] % mod) %mod;
	ans = ans * cur % mod;
	cout<<ans<<endl;



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
