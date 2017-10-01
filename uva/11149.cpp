/* ***********************************************
Author :111qqz
Created Time :Tue 18 Oct 2016 05:10:53 PM CST
File Name :code/poj/3233.cpp
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
const int N=45;
int n,k,mod;
struct Mat
{
    LL mat[N][N];
    void clear()
    {
	ms(mat,0);
    }
    void out()
    {
	for ( int i = 0 ; i < n ; i++ )
	{
	    for ( int j = 0 ; j <n-1 ; j++) printf("%lld ",mat[i][j]%mod);
	    printf("%lld\n",mat[i][n-1]%mod);
	}
    }
}M;
Mat operator * ( Mat a ,Mat b )
{
    Mat c;
    c.clear();
    for ( int i = 0 ; i < n ; i++)
	for ( int j = 0 ; j < n; j ++)
	    for ( int k = 0 ; k < n;  k++)
		c.mat[i][j] = (c.mat[i][j] + a.mat[i][k]*b.mat[k][j])%mod;
    return c;
}
Mat operator + (Mat a,Mat b)
{
    Mat c;
    c.clear();
    for ( int i = 0 ; i < n ;i ++)
	for ( int j = 0 ; j < n ; j++)
	    c.mat[i][j] = (a.mat[i][j] + b.mat[i][j])%mod;
    return c;
}
Mat operator ^ (Mat a,int b)
{
    Mat c;
    for ( int i = 0 ; i < n ; i++)
	for ( int j = 0 ;j  <n ; j++)
	    c.mat[i][j] = (i==j);
    while (b>0)
    {
	if (b&1) c = c * a;
	b = b >> 1;
	a = a* a;
    }
    return c;
}
Mat solve(  int k)
{
    if (k==1) return M;
    Mat res;
    res.clear();
    for ( int i = 0 ; i < n ;  i++) res.mat[i][i] = 1;
    res = res + (M^(k>>1));
    res = res * solve(k>>1);
    if (k%2==1) res = res + (M^k);
    return res;
}
int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("./in.txt","r",stdin);
#endif
	
        while (~scanf("%d%d",&n,&k)&&n)
	{
	    mod = 10;
	    for ( int i = 0 ; i < n ; i++)
		for ( int j = 0 ; j  < n ; j++)
		    scanf("%lld",&M.mat[i][j]);
	    Mat ans;
	    ans.clear();
	    ans = solve(k);
	    ans.out();
	    printf("\n");
	}
#ifndef ONLINE_JUDGE  
	fclose(stdin);
#endif
	return 0;
}
