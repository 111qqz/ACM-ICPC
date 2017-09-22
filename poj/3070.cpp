/* ***********************************************
Author :111qqz
Created Time :Tue 18 Oct 2016 01:18:40 AM CST
File Name :code/poj/3070.cpp
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
const int MOD = 1E4;
int n;
struct Mat
{
    int mat[5][5];

    void clear()
    {
	ms(mat,0);
    }

}M,M1;
Mat operator * (Mat a,Mat b)
{
    Mat c;
    c.clear();
    for ( int i = 0 ; i < 2 ; i++)
	for ( int j = 0 ; j < 2 ; j++)
	    for ( int k = 0 ; k < 2 ; k++)
		c.mat[i][j] = (c.mat[i][j] + a.mat[i][k]*b.mat[k][j])%MOD;
    return c;
}
Mat operator ^ (Mat a,int b)
{
    Mat c;
    c.clear();
    for  ( int i = 0 ; i < 2 ; i++)
	for ( int j = 0 ; j < 2 ; j++)
	    c.mat[i][j]=(i==j); //初始化为单位矩阵。
    while (b>0)
    {
	if (b&1) c = c * a;
	b = b >> 1;
	a = a * a;
    }
    return c;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%d",&n))
	{
	    if (n==-1) break;
	    if (n==0)
	    {
		printf("%d\n",0);
		continue;
	    }
	    M.mat[0][0] = 0;
	    M.mat[0][1] = 1;
	    M.mat[1][0] = 1;
	    M.mat[1][1] = 1;
	    M1.mat[0][0] = 0;
	    M1.mat[1][0] = 1;
	    Mat ans;
	    ans.clear();
	    ans = (M ^ n )* M1;
	    printf("%d\n",ans.mat[0][0]);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
