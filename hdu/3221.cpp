/* ***********************************************
Author :111qqz
Created Time :Sun 30 Oct 2016 11:46:33 PM CST
File Name :code/hdu/3221.cpp
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
LL a,b,p,n;
LL mod;
LL euler( LL x)
{
    LL ret = 1;
    for ( LL i = 2 ; i*i <= x;  i++)
    {
	if (x%i==0)
	{
	    x/=i;
	    ret*=(i-1);
	    while (x%i==0)
	    {
		x/=i;
		ret*=i;
	    }
	}
    }
    if (x>1) ret*=(x-1);
    return ret;
}

struct Mat
{
    LL mat[2][2];
    void clear()
    {
	ms(mat,0);
    }
}M,M1;

Mat operator * (Mat a,Mat b)
{
    Mat res;
    res.clear();
    for ( int i = 0 ; i < 2 ; i++)
	for ( int j = 0 ; j < 2 ; j++)
	    for ( int k = 0 ; k < 2 ; k++)
	    {
		res.mat[i][j] = (res.mat[i][j] + a.mat[i][k]*b.mat[k][j]);
		if (res.mat[i][j]>=mod)
		    res.mat[i][j] = res.mat[i][j] % mod + mod;
	    }
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
	a = a * a;
    }
    return res;
}
void init()
{
    M.clear();
    M.mat[0][1] =  M.mat[1][0] = M.mat[1][1] = 1;
    M1.clear();
    M1.mat[0][0] = 0 ;
    M1.mat[1][0] = 1;
}
LL ksm( LL a,LL b,LL k)
{
    LL res = 1LL;
    while (b>0)
    {
	if (b&1) res = (res * a) % k;
	b = b >> 1LL;
	a = ( a * a ) % k;
    }
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	int cas = 0 ;
	cin>>T;
	while (T--)
	{
	    scanf("%lld%lld%lld%lld",&a,&b,&p,&n);
	    printf("Case #%d: ",++cas);
	    if (n==1)
	    {
		printf("%lld\n",a%p);
		continue;
	    }
	    if (n==2)
	    {
		printf("%lld\n",b%p);
		continue;
	    }
	    init();
	    mod = euler(p);
	    Mat ans;
	    ans.clear();
	    ans = (M^(n-2))*M1;
	    LL x = ans.mat[0][0];
	    LL y = ans.mat[1][0];
	    LL ret = ksm(a,x,p)*ksm(b,y,p)%p;
	    printf("%lld\n",ret);
	   // printf("Case #%d: %lld\n",++cas,ret);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
