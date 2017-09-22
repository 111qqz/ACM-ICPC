/* ***********************************************
Author :111qqz
Created Time :Wed 19 Oct 2016 08:14:56 PM CST
File Name :code/hdu/2157.cpp
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
const int N=25;
const int mod = 1000;
int n,m;
struct Mat
{
    int mat[N][N];
    void clear()
    {
	ms(mat,0);
    }
}M;

Mat operator * (Mat a,Mat b)
{
    Mat ans;
    ans.clear();
    for ( int i = 0 ; i < n ; i++)
	for ( int j = 0 ; j < n ;j++)
	    for ( int k = 0 ; k < n ; k++)
		ans.mat[i][j] = (ans.mat[i][j] + a.mat[i][k] * b.mat[k][j])%mod;

    return ans;
}

Mat operator ^ (Mat a,int b)
{
    Mat ans;
    ans.clear();
    for ( int i = 0 ; i < n ; i++) ans.mat[i][i] = 1;

    while (b>0)
    {
	if (b&1) ans = ans * a;
	b = b >> 1LL;
	a = a* a;
    }
    return ans;
}
LL ksm( LL a,LL b, LL k)
{
    LL res = 1LL;
    while (b)
    {
	if (b&1) res = (res * a) % k;
	b = b >> 1LL;
	a = ( a * a) % k;
    }
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%d%d",&n,&m))
	{
	    if (n==0&&m==0) break;
	    M.clear();
	    for ( int i = 1 ; i <= m ; i ++)
	    {
		int s,t;
		scanf("%d %d",&s,&t);
		M.mat[s][t] = 1;
	    }

	    int T;
	    scanf("%d",&T);
	    while (T--)
	    {
		int a,b,k;
		scanf("%d%d%d",&a,&b,&k);
		Mat ans;
		ans.clear();
		ans = M ^ k;
		printf("%d\n",ans.mat[a][b]);
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
