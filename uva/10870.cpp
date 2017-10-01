/* ***********************************************
Author :111qqz
Created Time :2017年10月01日 星期日 03时57分36秒
File Name :10870.cpp
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
const int N=20;
int n,d;
LL mod;
LL a[N],f[N];
struct Mat
{
    LL mat[N][N];
    void clear()
    {
	ms(mat,0);
    }
    void print()
    {
	for ( int i = 0 ; i < d ; i++)
	    for ( int j = 0 ; j < d ; j++)
		printf("%lld%c",mat[i][j],j==d-1?'\n':' ');
    }
}M,M1;

Mat operator * (Mat a,Mat b)
{
    Mat c;
    c.clear();
    for ( int i = 0 ; i < d ; i++)
	for ( int j = 0 ; j < d ; j++)
	    for ( int k = 0 ; k < d ; k++)
	    {
		a.mat[i][k]%=mod;
		b.mat[k][j]%=mod;
		c.mat[i][j] = (c.mat[i][j] + (a.mat[i][k] * b.mat[k][j])%mod)%mod;
	    }
    return c;
}
Mat operator ^ (Mat a,LL b)
{
    Mat ret;
    ret.clear();
    for ( int i = 0 ; i < d ; i++) ret.mat[i][i] = 1LL;
    while (b>0)
    {
	if (b&1) ret = ret * a;
	b = b >> 1LL;
	a = a * a;
    }
    return ret;
}
LL solve()
{
    if (n==1) return f[1];
    M1.clear();
    for ( int i = 1 ; i <= d  ; i++)
	M1.mat[i-1][0] = f[i];
    M.clear();
    for ( int i = 1 ; i <= d ; i++)
	M.mat[d-1][i-1]=a[d-i+1];
    for ( int i = 0 ; i < d-1 ; i++)
	for ( int j = 1 ; j < d ; j++)
	    if (i+1==j) M.mat[i][j] = 1;

   // M.print();
    
    Mat ans;
    ans.clear();
    ans = (M ^ (n-d))*M1;
    return ans.mat[d-1][0];
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	while (~scanf("%d %d %lld",&d,&n,&mod))
	{
	    if (d==0&&n==0&&mod==0) break;
	    for ( int i = 1 ; i <= d ; i++) scanf("%lld",&a[i]);
	    for ( int i = 1 ; i <= d ; i++) scanf("%lld",&f[i]);
	    LL ans = solve();
	    ans = (ans % mod + mod ) % mod;
	    printf("%lld\n",ans);
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
