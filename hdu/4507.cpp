/* ***********************************************
Author :111qqz
Created Time :2016年03月16日 星期三 10时44分58秒
File Name :code/hdu/4507.cpp
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
const LL MOD = 1E9+7;
LL l,r;
int digit[30];
LL power[40];
struct node
{
    LL cnt,sum,sq;
    node(){}
    node (LL _cnt,LL _sum,LL _sq):
	cnt(_cnt),sum(_sum),sq(_sq){};
}dp[25][20][20];                
LL Add(LL a,LL b)
{
    LL res = (a+b) %MOD;
    return res;
}
LL Mul(LL a,LL b)
{
    LL res = ((a%MOD)*(b%MOD))%MOD;
    return res;
}
node dfs (int pos,int mod7,int sum7,bool limit)
{
    if (pos==0)
    {
	if (mod7!=0&&sum7!=0) return node(1,0,0);
	else return node (0,0,0);
    }
    if (!limit&&dp[pos][mod7][sum7].cnt!=-1) return dp[pos][mod7][sum7];

    int mx = limit?digit[pos]:9;
    node res ;
    res.cnt=res.sum=res.sq=0;
    for ( int i = 0 ; i <= mx;  i++)
    {
	if (i==7) continue;
	node tmp = dfs(pos-1,(mod7+i)%7,(sum7*10+i)%7,limit&&i==mx);
	res.cnt = Add(res.cnt,tmp.cnt);
	res.sum = Add(res.sum,Add(tmp.sum,Mul(i,Mul(power[pos],tmp.cnt))));
	res.sq  = Add(res.sq,Add(tmp.sq,Mul(2*tmp.sum,i*power[pos])));
	res.sq  = Add(res.sq,Mul(i*power[pos],Mul(i*power[pos],tmp.cnt)));
    }
    if (!limit) dp[pos][mod7][sum7] = res;
    return res;
}
LL solve ( LL n)
{
    int len = 0 ;
    ms (digit,0);
    while (n)
    {
	digit[++len] = n % 10;
	n/=10;
    }
    return dfs(len,0,0,true).sq;
}

void pre()
{
    power[1] = 1;
    for ( int i = 2 ;i  <= 30 ; i++)
	power[i] = (power[i-1]*10LL)%MOD;
}
int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
#endif
    pre();
    int T;
    cin>>T;
    ms(dp,-1);
    while (T--)
    {
	scanf("%lld %lld",&l,&r);
	LL ans = solve (r) - solve (l-1);
	while (ans<0) ans +=MOD;
	//  ans = ans % MOD;
	printf("%lld\n",ans);
    }
#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
