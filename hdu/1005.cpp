/* ***********************************************
Author :111qqz
Created Time :Mon 31 Oct 2016 05:03:40 AM CST
File Name :code/hdu/1005.cpp
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
    Mat c;
    c.clear();
    for ( int i = 0 ;i  < 2 ; i ++)
	for ( int j = 0 ; j < 2 ; j++)
	    for ( int k = 0 ; k < 2 ; k++)
		c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j] )%7;
    return c;
}
Mat operator ^ ( Mat a,LL b)
{
    Mat res;
    res.clear();
    for ( int i = 0 ; i < 2 ; i++)
	res.mat[i][i] = 1;
    while (b>0)
    {
	if (b&1) res = res * a;
	b = b >> 1LL;
	a = a * a;
    }
    return res;
}
LL A,B,n;
void init()
{
    M.clear();
    M.mat[0][1] = 1;
    M.mat[1][0] = B;
    M.mat[1][1] = A;
    M1.clear();
    M1.mat[0][0] = 1;
    M1.mat[1][0] = 1;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%lld%lld%lld",&A,&B,&n))
	{
	    init();
	    if (A==0&&B==0&&n==0) break;
	    Mat res = (M^(n-2))*M1;
	    printf("%lld\n",res.mat[1][0]);

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
