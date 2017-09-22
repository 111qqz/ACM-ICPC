/* ***********************************************
Author :111qqz
Created Time :Wed 26 Oct 2016 09:16:22 AM CST
File Name :code/hdu/4549.cpp
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
LL a,b,n;
struct Mat
{
    LL mat[2][2];
    void clear()
    {
	ms(mat,0);
    }
}M,M1;
Mat operator * ( Mat a,Mat b)
{
    Mat res;
    res.clear();
    for ( int i = 0 ; i < 2 ; i ++)
	for ( int j = 0 ; j < 2 ; j++)
	    for ( int k = 0 ; k < 2 ; k++)
		res.mat[i][j] = (res.mat[i][j] + a.mat[i][k] * b.mat[k][j] ) % (mod - 1);
    return res;
}
Mat operator ^ (Mat a,LL b)
{
    Mat res;
    res.clear();
    for ( int i = 0 ; i < 2 ; i++) res.mat[i][i] = 1;
    while (b>0)
    {
	if (b&1) res = res * a;
	b = b >> 1LL;
	a = a * a ;
    }
    return res;
}
LL ksm( LL a,LL b)
{
    LL res = 1LL;
    while (b>0)
    {
	if (b&1){
	    res = (res * a) %mod;
	}
	b = b >> 1LL;
	a = ( a * a ) % mod;
    }
    return res;
}
void init()
{
    M.clear();
    M.mat[0][1] = 1;
    M.mat[1][0] = 1;
    M.mat[1][1] = 1;
    M1.clear();
    M1.mat[0][0] = 0;
    M1.mat[1][0] = 1;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%lld %lld %lld",&a,&b,&n))
	{
	    if (n==0)
	    {
		printf("%lld\n",a);
		continue;
	    }
	    if (n==1)
	    {
		printf("%lld\n",b);
		continue;
	    }
	    init();
	    Mat ans;
	    ans.clear();
	    ans = (M ^(n-1))*M1;
	    LL x = ans.mat[0][0];
	    LL y = ans.mat[1][0];
	    LL ret =(ksm(a,x)*ksm(b,y))%mod;
	    printf("%lld\n",ret);
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
