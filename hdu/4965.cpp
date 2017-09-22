/* ***********************************************
Author :111qqz
Created Time :Wed 19 Oct 2016 08:39:49 PM CST
File Name :code/hdu/4965.cpp
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
const int N=1E3+5;
int n,K;
struct Mat
{
    int mat[10][10];
    void clear()
    {
	ms(mat,0);
    }
}C,M;
Mat operator * ( Mat a, Mat b)
{
    Mat ans;
    ans.clear();
    for ( int i = 0 ; i < K ; i++)
    {
	for ( int j = 0 ; j < K ; j++)
	{
	    for ( int k = 0 ; k < K ; k++)
	    {
		ans.mat[i][j] = (ans.mat[i][j] + a.mat[i][k] * b.mat[k][j])%6;
	    }
	}
    }
    return ans;
}
Mat operator ^ ( Mat a,int b)
{
    Mat ans;
    ans.clear();
    for ( int i = 0 ; i < K ; i++) ans.mat[i][i]  = 1;
    while (b>0)
    {
	if (b&1) ans = ans * a;
	b = b >> 1;
	a = a * a;
    }
    return ans;
}
int A[N][10],B[10][N],ans[2][N][N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%d%d",&n,&K))
	{
	    if (n==0&&K==0) break;
	    ms(A,0);
	    ms(B,0);
	    C.clear();
	    for ( int i = 0 ; i < n ; i++)
		for ( int j = 0 ; j < K ; j++)
		    scanf("%d",&A[i][j]);
	    for ( int i = 0 ; i < K ; i++)
		for ( int j = 0 ; j < n ; j++)
		    scanf("%d",&B[i][j]);
	    for ( int i = 0 ; i < K ; i++)
		for ( int j = 0 ; j < K ; j++)
		    for ( int k = 0 ; k < n ; k++)
			C.mat[i][j] = (C.mat[i][j] + B[i][k] * A[k][j])%6;
	    M = C^(n*n-1);
	    ms(ans,0);
	    for ( int i = 0  ; i < n ; i++)
		for ( int j = 0 ; j < K ;j++)
		    for ( int k = 0 ; k < K ; k++)
			ans[0][i][j] =( ans[0][i][j] + A[i][k] * M.mat[k][j])%6;
	    for ( int i = 0 ; i < n ; i++)
		for ( int j = 0 ; j < n ; j++)
		    for ( int k = 0 ; k < K ; k++)
			ans[1][i][j] =( ans[1][i][j] + ans[0][i][k] * B[k][j])%6;
	    LL sum = 0 ;
	    for ( int i = 0 ; i < n ; i++)
		for ( int j = 0 ; j < n ; j++)
		    sum = sum + ans[1][i][j];
	    printf("%lld\n",sum);
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
