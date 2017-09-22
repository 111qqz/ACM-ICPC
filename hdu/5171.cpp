/* ***********************************************
Author :111qqz
Created Time :Thu 20 Oct 2016 10:40:39 AM CST
File Name :code/hdu/5171.cpp
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
const int N =1E5+7;
const LL mod = 1E7+7;
int n;
LL k;
LL a[N];
LL sum;
LL a0,a1;
struct Mat
{
    LL mat[3][3];
    void clear()
    {
	ms(mat,0);
    }
    Mat operator * (const Mat &b)const
    {
	Mat ans;
	ans.clear();
	for ( int i = 0 ; i < 2 ; i++)
	    for ( int j = 0 ; j < 2 ; j++)
		for ( int k = 0 ; k < 2 ; k++)
		    ans.mat[i][j] = ( ans.mat[i][j] + mat[i][k] * b.mat[k][j] ) % mod;
	return ans;
    }
  
    Mat operator ^ ( LL b)
    {
	Mat res;
	res.clear();
	for ( int i = 0 ; i < 2 ; i++) res.mat[i][i] = 1;
	Mat a = *this;
	while (b>0)
	{
	    if (b&1) res = res * a;
	    b = b >> 1LL;
	    a = a * a;
	}
	return res;
    }
    
    void out()
    {
	for ( int i = 0 ; i < 2 ; i++)
	{
	    for ( int j = 0 ; j < 2 ; j++)
	    {
		printf("%d ",mat[i][j]);
	    }
		printf("\n");
	}
    }
}M,M1;

/*
Mat operator ^ (Mat a, LL b)
{
    Mat res;
    res.clear();
    for ( int i = 0 ; i < 2 ; i++) res.mat[i][i] = 1;
//    res.out();
    while (b>0)
    {
	if (b&1) res = res * a;
	b = b >> 1LL;
	a = a * a;
    }
    return res;
}
*/
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%d%lld",&n,&k))
	{
	    sum = 0 ;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		scanf("%lld\n",&a[i]);
	    }
	    sort(a+1,a+n+1);
	    for ( int i = 1 ; i <= n-2 ; i++)
	    {
		sum = (sum + a[i])%mod;
	    }
	    a0 = a[n-1];
	    a1 = a[n];
	   // cout<<"a0:"<<a0<<" a1:"<<a1<<endl;
	    M1.clear();
	    M1.mat[0][0] = a0;
	    M1.mat[1][0] = a1;
	    M.clear();
	    M.mat[0][1] = 1;
	    M.mat[1][0] = 1;
	    M.mat[1][1] = 1;
	   // M=M*M*M;
	   // M.pr();
	    Mat ans;
	    ans.clear();
	    ans = (M^(k+2));
	    sum = (sum + a0*ans.mat[0][1]%mod + a1 * ans.mat[1][1]%mod)%mod;
	    sum = (sum-a1 + mod) %mod;
	    printf("%lld\n",sum);
    	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
