/* ***********************************************
Author :111qqz
Created Time :2017年10月01日 星期日 13时34分52秒
File Name :4686.cpp
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
const int N=10;
const LL mod = 1E9+7;
LL n,A0,Ax,Ay,B0,Bx,By;
struct Mat
{
    LL mat[N][N];
    void clear()
    {
	ms(mat,0);
    }
    void pr()
    {
	for ( int i = 0 ; i < 5 ; i++)
	    for ( int j = 0 ; j < 5 ; j++)
		printf("%lld%c",mat[i][j],j==4?'\n':' ');
    }
}M,M1;
Mat operator * (Mat a,Mat b)
{
    Mat c;
    c.clear();
    for ( int i = 0 ; i < 5 ;  i++)
	for ( int j = 0 ; j < 5 ; j++)
	    for ( int k = 0 ; k < 5 ; k++)
	    {
		a.mat[i][k]%=mod;
		b.mat[k][j]%=mod;
		c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j] % mod) %mod;
	    }
    return c;
}
Mat operator ^ (Mat a,LL b)
{
    Mat ret;
    ret.clear();
    for ( int i = 0 ; i < 5 ; i++) ret.mat[i][i] =  1;
    while (b>0)
    {
	if (b&1)
	    ret = ret * a;
	b = b>>1LL;
	a = a * a;
    }
    return ret;
}
LL solve()
{
    M1.clear();
    M.clear();
    M.mat[0][0] = Ax*Bx;
    M.mat[0][1] = Ax*By;
    M.mat[0][2] = Ay*Bx;
    M.mat[0][3] = Ay*By;

    M.mat[1][1] = Ax;
    M.mat[1][3] = Ay;
    M.mat[2][2] = Bx;
    M.mat[2][3] = By;
    M.mat[3][3] = 1;
    M.mat[4][0] = 1;
    M.mat[4][4] = 1;

    M1.mat[0][0] = A0*B0;
    M1.mat[1][0] = A0;
    M1.mat[2][0] = B0;
    M1.mat[3][0] = 1;
    M1.mat[4][0] = 0;

    Mat ans;
    ans.clear();
    ans = (M ^ (n))*M1;
   // ans.pr();
    return ans.mat[4][0];
}                                                                                                                                                                                    
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	while (~scanf("%lld%lld%lld%lld%lld%lld%lld",&n,&A0,&Ax,&Ay,&B0,&Bx,&By))
	{
	    LL ans = solve();
	    ans = (ans % mod + mod )%mod;
	    printf("%lld\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
