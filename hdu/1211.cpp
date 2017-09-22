/* ***********************************************
Author :111qqz
Created Time :Wed 19 Oct 2016 04:51:40 PM CST
File Name :code/hdu/1211.cpp
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
LL p,q,e,l,d;
LL n,fn;
LL exgcd( LL a,LL b,LL &x,LL &y)
{
    if (b==0)
    {
	x = 1;
	y = 0;
	return a;
    }
    LL ret = exgcd(b,a%b,y,x);
    y-=x*(a/b);
    return ret;
}
LL ksm( LL a,LL b,LL k)
{
    LL res = 1;
    while (b>0)
    {
	if (b&1) res = (res * a)%k;
	b = b >> 1;
	a = (a * a) % k;
    }
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%lld %lld %lld %lld",&p,&q,&e,&l))
	{
	    n = p * q;
	    fn = (p-1) * (q-1);
	    LL tmp;
	    exgcd(e,fn,d,tmp);
	    d = (d%fn + fn)%fn;
//	    printf("d:%lld\n",d);
	    for ( int i =1 ; i <= l ; i ++)
	    {
		LL x;
		scanf("%lld",&x);
		LL val = ksm(x,d,n);
	//	cout<<"val:"<<val<<endl;
		printf("%c",char(val));
	    }
	    printf("\n");
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
