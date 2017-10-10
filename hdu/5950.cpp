/* ***********************************************
Author :111qqz
Created Time :2017年10月10日 星期二 17时38分11秒
File Name :5950.cpp
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
const int N=7;
const LL MOD =2147493647LL;
LL a,b,n;
struct Mat
{
    LL mat[N][N];
    void clear()
    {
	ms(mat,0);
    }
    void print()
    {
	for ( int i = 0 ; i < N; i++)
	    for ( int j = 0 ; j < N ; j++)
		printf("%lld%c",mat[i][j],j==N-1?'\n':' ');
	puts("");
    }
}M,M1;
Mat operator * (Mat a,Mat b)
{
    Mat c;
    c.clear();
    for ( int i = 0 ; i < N ; i++)
	for ( int j = 0 ; j < N  ; j++)
	    for ( int k = 0 ; k < N  ; k++)
		c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j]%MOD)%MOD;
    return c;
}
Mat operator ^ (Mat a,LL b)
{
    Mat res;
    res.clear();
    for ( int i = 0 ; i < N ; i++) res.mat[i][i] = 1;
    while (b>0)
    {
	if (b&1) res = res * a;
	b = b >> 1LL;
	a = a * a;
    }
    return res;
}
LL solve()
{
    M.clear();
    M.mat[0][1]=M.mat[1][2]=1;
    for ( int i = 1 ; i < N; i++) M.mat[i][N-1]=1,M.mat[i][i]=1;
    M.mat[1][0]=M.mat[4][5]=2;
    M.mat[1][3]=M.mat[1][5]=M.mat[2][3]=M.mat[2][5]=4;
    M.mat[1][4]=M.mat[2][4]=6;
    M.mat[3][4]=M.mat[3][5]=3;
    //M.print();
    M1.clear();
    M1.mat[0][0]=a;
    M1.mat[1][0]=b;
    //注意下标是从1开始的
    M1.mat[2][0]=16;
    M1.mat[3][0]=8;
    M1.mat[4][0]=4;
    M1.mat[5][0]=2;
    M1.mat[6][0]=1;
    //M1.print();
    Mat ans;
    ans.clear();
    ans = (M^(n-2))*M1;
    //ans.print();
    return ans.mat[1][0];
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%lld%lld%lld",&n,&a,&b);
	    LL ans = solve();
	    printf("%lld\n",ans);
	}
	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
