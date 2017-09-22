/* ***********************************************
Author :111qqz
Created Time :Tue 25 Oct 2016 07:00:23 PM CST
File Name :code/bzoj/4547.cpp
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
const LL mod = 1E7+7;
const int N=1E5+7;
int n,k;
LL a[N];
LL a0,a1;
LL sum;
struct Mat
{
    LL mat[2][2];
    void clear()
    {
	ms(mat,0);
    }
}M,M1;
Mat operator*(Mat a,Mat b)
{
    Mat res;
    res.clear();
    for ( int i = 0 ; i < 2 ; i++)
	for ( int j = 0 ; j < 2 ; j++)
	    for ( int k = 0 ; k < 2 ; k++)
		res.mat[i][j] = (res.mat[i][j] + a.mat[i][k]*b.mat[k][j] ) %mod;
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
int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
#endif
    scanf("%d%d",&n,&k);
    for ( int i = 1 ; i <= n  ;i++) scanf("%lld",&a[i]);
    sum = 0 ;
    sort(a+1,a+n+1);
    a0 = a[n-1];
    a1 = a[n];
    //cout<<"a0:"<<a0<<" a1:"<<a1<<endl;
    //
    if (a1<0)
    {
	for ( int i = 1 ; i <= n ; i++) sum = ( sum + a[i] + mod ) %mod;
	sum = (sum + k*(a0+a1+mod)%mod+mod)%mod;
	printf("%lld\n",sum);
	return 0;
    } 
    for ( int i = 1 ;i  <= n-2 ; i++) sum =( sum + a[i]+mod ) % mod;
    if (a0<0)
    {
	LL num = -a0/a1+1;
//	cout<<"num:"<<num<<endl;
	if (num<=k)
	{
	    k-=num;
	    sum = ( sum + num*a0%mod + (a1*(num-1))*num/2%mod +mod)%mod;
	    a0 = (a0 + a1 *num%mod)%mod;
	    if (a0>a1) swap(a0,a1);
	}
    } 
	Mat ans;
	M.clear();
	M1.clear();
	ans.clear();
	M.mat[0][1] = M.mat[1][0] = M.mat[1][1] = 1;
	M1.mat[0][0] = a0;
	M1.mat[1][0] = a1;
	ans = (M^(k+2))*M1;
	sum = (sum + ans.mat[1][0] - a1 + mod)%mod;
	printf("%lld\n",sum);
	return 0;
    /*
     if (a0<0)
    {
	LL num = (-a0)/a1 + 1;
//	cout<<"num:"<<num<<endl;
	if (k<=num)
	{
	    for ( int i = 1 ; i <= n-2 ; i++) sum = (sum + a[i] + mod ) % mod;
	    sum = ( sum + a[n] + mod ) %mod;
	    num = k+1;
//	    cout<<"sum:"<<sum<<endl;
	    sum = (sum + (num*a0 + num*(num-1)/2*a1)%mod+mod)%mod;
	    printf("%lld\n",sum);
	    return 0;
	}
	k-=num;
	for ( int i = 1 ; i <= n-2 ; i++)  sum = (sum + a[i]+mod ) % mod;
	sum = (sum + num*a0 + num*(num-1)/2*a1+mod)%mod;
	a0 = a0 + num*a1;
//<F5printf("a0:%lld a1:%lld\n",a0,a1);
	Mat ans;
	M.clear();
	M1.clear();
	ans.clear();
	M.mat[0][1] = M.mat[1][0] = M.mat[1][1] = 1;
	M1.mat[0][0] = a0;
	M1.mat[0][1] = a1;
	ans = (M ^(k+2))*M1;
	sum = (sum + ans.mat[1][0] - a1 + mod ) %mod;
	printf("%lld\n",sum);
    }  */
#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
