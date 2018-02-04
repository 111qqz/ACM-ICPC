/* ***********************************************
Author :111qqz
Created Time :2017年09月30日 星期六 16时18分12秒
File Name :450B.cpp
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
LL n,x,y;
const LL MOD = 1E9+7;
struct Mat
{
    LL mat[5][5];
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
    for ( int i = 0 ; i < 2 ; i++)
	for ( int j = 0 ; j < 2 ; j++)
	    c.mat[i][j] = (i==j);
    while (b>0)
    {
	if (b&1) c = c*a;
	b = b >> 1;
	a = a*a;
    }
    return c;
}
LL solve()
{
    if (n==1) return x;
    if (n==2) return y;
    M.mat[0][0]=0;
    M.mat[0][1]=1;
    M.mat[1][0]=-1;
    M.mat[1][1]=1;
    M1.mat[0][0]=x;
    M1.mat[1][0]=y;
    Mat ans;
    ans.clear();
    ans=(M^(n-2))*M1;
    return ans.mat[1][0];
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	cin>>x>>y;
	cin>>n;
	LL ans = solve();
	ans = (ans % MOD + MOD)%MOD;
	printf("%lld\n",ans);


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
