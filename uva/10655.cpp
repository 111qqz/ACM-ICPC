/* ***********************************************
Author :111qqz
Created Time :2017年10月01日 星期日 03时01分38秒
File Name :10655.cpp
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
LL p,q,n;
struct Mat
{
    LL mat[105][105];
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
		c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
    return c;
}
Mat operator ^ (Mat a,LL b)
{
    Mat ret;
    ret.clear();
    for ( int i = 0 ; i < 2 ; i++) ret.mat[i][i] = 1LL;

    while (b>0)
    {
	if (b&1) ret = ret * a;
	a = a * a;
	b = b >> 1LL;
    }
    return ret;
}
LL solve()
{
    if (n==0) return 2LL;
    if (n==1) return p;
    if (n==2) return p*p-2*q;
    M1.clear();
    M1.mat[0][0] = p;
    M1.mat[1][0] = p*p-2*q;
    M.clear();
    M.mat[0][1] = 1;
    M.mat[1][0] = -q;
    M.mat[1][1] = p;
    Mat ans;
    ans.clear();
    ans = (M^(n-2))*M1;
    return ans.mat[1][0];
}
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("./in.txt","r",stdin);
  #endif
	while (scanf("%lld%lld%lld",&p,&q,&n)==3)
	{
	    //if (p==0&&q==0) break;
	    //scanf("%lld",&n);
	    LL ans = solve();
	    printf("%lld\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
