/* ***********************************************
Author :111qqz
Created Time :2016年02月08日 星期一 16时24分34秒
File Name :code/cf/#341/E.cpp
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
const LL MOD=1E9+7;
int n,b,k,X;
struct Matrix
{
    LL a[110][110];

};

void add(LL &x,LL y)
{
    x += y;
    x %= MOD;
}
Matrix multi(Matrix x,Matrix y )   //矩阵乘法。
{
    Matrix z;
    ms(z.a,0LL);
    for ( int i =  0 ; i < X  ;i++)
    {
	for ( int k = 0 ; k < X ; k++)
	{
	    if (x.a[i][k]==0) continue;
	    for ( int j = 0 ; j < X ; j++)
		add(z.a[i][j],x.a[i][k]*y.a[k][j]);
		
	}
    }
    return z;
}

Matrix Pow(Matrix x,int n)  //矩阵快速幂
{
    Matrix y;
    ms(y.a,0LL);
    for ( int i = 0 ; i < X ; i++) y.a[i][i] = 1LL;
    while (n)
    {
	if (n&1)
	    y = multi(x,y);
	x = multi(x,x);
	n >>=1;
    }
    return y;
}

int cnt[20];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n>>b>>k>>X;

	Matrix ori,res;
	ms(ori.a,0LL);
	ms(cnt,0);
	for ( int i = 1 ; i <= n ; i++)
	{
	    int tmp;
	    scanf("%d",&tmp);
	    cnt[tmp]++;
	}

	for ( int i = 0 ; i < X ; i++)
	    for (int j = 0 ; j <= 9 ; j++)
		add(ori.a[i][(i*10+j)%X],1LL*cnt[j]);
	res = Pow(ori,b);
	cout<<res.a[0][k]<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
