/* ***********************************************
Author :111qqz
Created Time :Mon 31 Oct 2016 02:47:01 PM CST
File Name :code/hdu/4291.cpp
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
const LL loop0 = 1E9+7;
const LL loop1=222222224,loop2=183120; //暴力得到每一层的循环节。
/*
LL find_loop(LL mod)
{
    LL a,b,c;
    a = 0 ;
    b = 1 ;
    for ( int i = 2 ; ; i++)
    {
	c = (a+3*b%mod)% mod;
	a = b;
	b = c; 
//	cout<<"a:"<<a<<" b:"<<b<<endl;
	if (a==0&&b==1)
	{
	    return i-1; // i的时候得到第i项，判断循环的时候是判断g[i-1]==g[0]&&g[i]==g[1]，所以循环节长度是i-1;
	}
    }
}*/
LL n;
struct Mat
{
    LL mat[2][2];
    void clear()
    {
	ms(mat,0);
    }
    void out()
    {
	cout<<mat[0][0]<<" "<<mat[0][1]<<endl;
	cout<<mat[1][0]<<" "<<mat[1][1]<<endl;
	cout<<endl;
    }
}M,M1;
Mat mul(Mat a,Mat b,LL MOD)
{
    Mat c;
    c.clear();
    for ( int i = 0 ; i < 2 ; i++)
	for  ( int j = 0 ; j < 2 ; j++)
	    for ( int k = 0 ; k < 2 ; k++)
		c.mat[i][j] = (c.mat[i][j] + a.mat[i][k]*b.mat[k][j]%MOD)%MOD;
    return c;
}
Mat power(Mat a,LL b,LL MOD)
{
    Mat res;
    res.clear();
    for ( int i = 0 ;i < 2 ; i++) res.mat[i][i] = 1;
    while (b>0)
    {
	if (b&1) res = mul(res,a,MOD);
	b = b>>1LL;
	a = mul(a,a,MOD);
    }
    return res;
}
void Mat_init()
{
    M.clear();
    M.mat[0][1] = 1;
    M.mat[1][0] = 1;
    M.mat[1][1] = 3;
    M1.clear();
    M1.mat[1][0] = 1;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	/*
	loop1 = find_loop(loop0);
	printf("loop1:%lld\n",loop1);
	loop2 = find_loop(loop1);
	printf("loop2:%lld\n",loop2);
	*/
	Mat_init();
	while (scanf("%lld\n",&n)!=EOF)
	{
	    if (n==0)
	    {
		puts("0");
		continue;
	    }
	    if (n==1)
	    {
		puts("1");
		continue;
	    }

	    LL cur = n;
	    Mat ans;
	    ans = power(M,cur-1,loop2);
	    //	    	    ans.out();
	    ans = mul(ans,M1,loop2);
	    //	    	    ans.out();
	    cur = ans.mat[1][0];
	   // cout<<"cur1:"<<cur<<endl;
	    if (cur!=0&&cur!=1)
	    {

		ans = power(M,cur-1,loop1);
		ans = mul(ans,M1,loop1);
		//	    ans.out();
		cur = ans.mat[1][0];
	    }
	   // cout<<"cur2:"<<cur<<endl;
	    if (cur!=0&&cur!=1)
	    {
		ans = power(M,cur-1,loop0);
		ans = mul(ans,M1,loop0);
		cur = ans.mat[1][0];
	    }
	    printf("%lld\n",cur);
	}


#ifndef ONLINE_JUDGE  
	fclose(stdin);
#endif
	return 0;
}
