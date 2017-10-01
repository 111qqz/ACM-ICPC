/* ***********************************************
Author :111qqz
Created Time :2017年10月01日 星期日 18时39分17秒
File Name :10518.cpp
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
const int N = 5;
LL n,base;
struct Mat
{
    LL mat[N][N];
    void clear()
    {
	ms(mat,0);
    }
}M,M1;
Mat operator * ( Mat a,Mat b)
{
    Mat c;
    c.clear();
    for ( int i = 0  ;  i <  3 ; i++)
	for ( int j = 0 ; j < 3 ; j++)
	    for  ( int k = 0 ;  k <  3 ; k++)
		c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j]% base)%base;

    return c;
}

Mat operator ^ (Mat a,LL b)
{
    Mat ret;
    ret.clear();
    for ( int i = 0 ; i < 3 ; i++) ret.mat[i][i] = 1;
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
    if (n==0) return 0;
    if (n==1) return 1;
    M.clear();
    M1.clear();
    M.mat[0][0] = M.mat[0][1] = M.mat[0][2] = 1;
    M.mat[1][0] = M.mat[2][2] = 1;
    M1.mat[0][0]=M1.mat[1][0]=M1.mat[2][0] = 1;

    Mat ans;
    ans.clear();
    ans = (M ^ (n-1))*M1;
    return ans.mat[0][0]%base;
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	int cas = 0 ;
	while (~scanf("%lld %lld",&n,&base))
	{
	    if (n==0&&base==0) break;
	    LL ans = solve();
	    printf("Case %d: %lld %lld %lld\n",++cas,n,base,ans);
	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
