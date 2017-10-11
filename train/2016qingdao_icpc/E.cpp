/* ***********************************************
Author :111qqz
Created Time :2017年10月08日 星期日 13时47分27秒
File Name :E.cpp
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
const int NN = 2;
LL P,X0;
struct Mat
{
    LL mat[NN][NN];
    void clear()
    {
	ms(mat,0);
    }
}M,M1;
Mat mul (Mat a,Mat b,LL mod)
{
    Mat c;
    c.clear();
    for ( int i = 0 ; i < NN ; i++)
	for ( int j = 0 ; j < NN ; j++)
	    for ( int k = 0 ; k < NN ; k++)
		c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j]% mod ) %mod;
    return c;
}
Mat mat_ksm( Mat a,LL b,LL mod)
{
    Mat res;
    res.clear();
    for ( int i = 0 ; i < NN ; i++) res.mat[i][i] = 1;
    while (b>0)
    {
	if (b&1) res = mul(res,a,mod);
	b = b >> 1LL;
	a = mul(a,a,mod);
    }
    return res;
}
LL gcd(LL a,LL b)
{
    return b?gcd(b,a%b):a;
}
const  int N = 1E6+7;
bool prime[N];
int p[N];
void isprime()
{
    int cnt = 0 ;
    ms(prime,true);
    for ( int i = 2 ; i < N ; i++)
    {
	if (prime[i])
	{
	    p[cnt++] = i ;
	    for ( int j = i+1 ; j < N ; j+=i) prime[j] = false;
	}
    }
}
LL ksm(LL a,LL b,LL mod)
{
    LL res = 1;
    while (b>0)
    {
	if (b&1) res = (res*a)%mod;
	b = b >> 1LL;
	a = a * a % mod;
    }
    return res;
}
LL legendre( LL a,LL p)
{
    if (ksm(a,(p-1)>>1,p)==1) return 1;
    return -1;
}
LL pri[N],num[N];
int cnt;
void solve(LL n,LL pri[],LL num[])
{
    cnt =  0;
    for ( int i  = 0; p[i]*p[i] <= n ; i++)
    {
	if (n%p[i]==0)
	{
	    int Num = 0 ;
	    pri[cnt]= p [i];
	    while (n%p[i]==0)
	    {
		Num++;
		n/=p[i];
	    }
	    num[cnt] = Num;
	    cnt++;
	}
    }
    if (n>1)
    {
	pri[cnt] = n ;
	num[cnt] = 1;
	cnt++;
    }
}
LL fac[N];
int cnt2;
void get_fac(LL n)
{
    cnt2=0;
    for ( int i = 1 ; i*i <= n ; i++)
    {
	if (n%i==0)
	{
	    if (i*i!=n)
	    {
		fac[cnt2++] =  i;
		fac[cnt2++] = n/i;
	    }else fac[cnt2++] =  i;
	}
    }
}
LL find_loop(LL n)
{
    solve(n,pri,num);
    LL ans = 1;
    for ( int i = 0 ; i < cnt ; i++)
    {
	LL rec  = 1;
	if (pri[i]==2) rec = 3;
	else if (pri[i]==3) rec = 5;
	else if (pri[i]==5) rec = 20;
	else
	{
	    if (legendre(5,pri[i])==1)
		get_fac(pri[i]-1);
	    else get_fac(2*pri[i]+2);
	    sort(fac,fac+cnt2);
	    for ( int j = 0 ; j < cnt2 ;  j++)
	    {
		Mat tmp = mat_ksm(M,fac[j],pri[i]);
		tmp = mul(tmp,M1,pri[i]);
		if (tmp.mat[0][0]==1&&tmp.mat[1][0]==1)
		{
		    rec=fac[j];
		    break;
		}
	    }
	}
	for ( int j = 1 ; j < num[i]  ; j++)
	    rec*=pri[i];
	ans = ans / gcd(ans,rec)*rec;
    }
    return ans;
}
/*
LL get_fib(LL n,LL mod)
{
    if (mod==1) return 0;
    Mat ret;
    ret = mat_ksm(M,n-1,mod);
    ret = mat(ret,M1,mod);
    return (ret.mat[1][0])%mod;
}
*/
void init()
{
    M.clear();
    M.mat[0][1] = M.mat[1][0] = M.mat[1][1] = 1;
    M1.clear();
    M1.mat[0][0] = M1.mat[1][0] = 1;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	//freopen("./in.txt","r",stdin);
  #endif
	int T;
	isprime();
	scanf("%d",&T);
	while (T--)
	{
	    init();
	    scanf("%lld",&P);
	    LL loop1 = find_loop(P);
	    cout<<"loop1:"<<loop1<<endl;
	    //LL loop2 = find_loop(loop1);
	    //printf("%lld\n",loop2);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
