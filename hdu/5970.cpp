/* ***********************************************
Author :111qqz
Created Time :2017年11月02日 星期四 09时38分56秒
File Name :5970.cpp
************************************************ */

#include <bits/stdc++.h>
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
LL n,m,p;
LL f(LL x,LL y,LL &c)
{
    LL t;
    while (y>0)
    {
	c++;
	t = x % y;
	x = y;
	y = t;
    }
    return c * x * x;
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
	    scanf("%lld%lld%lld",&n,&m,&p);
	    LL ans = 0 ;
	    for ( int j = 1 ; j <= m ; j++)
	    {
		for ( int i = 1 ; i <= j && i <= n ; i++)
		{
		    LL c=0,fun = f(i,j,c);
		    for ( int k = 0 ; k < c;  k++)
		    {
			if (i+k*j>n) break;
			LL a1 = (i+k*j)*j/fun ;
			LL d = c*j*j/fun;
			LL num = (n-i-k*j)/(c*j) + 1;
			ans = (ans + num * a1 % p + (num-1)*(num)/2%p*d )%p;
		    }
		}
	    }
	    printf("%lld\n",ans);
	}                                                                         
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
