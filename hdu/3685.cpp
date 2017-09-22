/* ***********************************************
Author :111qqz
Created Time :2016年11月17日 星期四 21时39分20秒
File Name :code/hdu/3685.cpp
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
const int N=5E4+7;
LL n;
int m;
LL cal( LL i,LL j)
{
//    printf("%lld %lld\n",i,j);
    return i*i + 100000*i + j*j - 100000*j +i*j;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	for ( int i = 1 ; i <= 10 ; i++)
	{
	    for ( int j = 1 ; j <= 10 ; j++)
	    {
		printf("%lld ",cal(i,j));
	    }
	    printf("\n");
	}
	
	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%lld%d",&n,&m);
	    LL x,y;
	    int p = 0 ;
	    int sum = 0;
	    bool flap = false;
	    for ( int i = 1 ; i <= 2*n-1 ; i++)
	    {
		LL tmp = i;
		if (i>n)
		{
		    tmp = 2 * n - tmp;
		    flap = true;
		}
		sum = sum + tmp ;
	//	printf("sum:%d m:%d \n",sum,m);
		if (sum>=m)
		{
		    p = i ;
		    break;
		 x = m-(p)*(p-1)/2;
		 y = n+2-p-x;
		}
	    }
//	    	    printf("p: %d ",p);
	    if (p>n)
	    {
		m = m - n*(n+1)/2;
		n--;
		LL k = 1 ;
		while (m-n>0&&n>=1)
		{
		    m-=n;
		    k++;
		    n--;
		}
		x = k+m;
		y = m;
	    }
	    else
	    {
		 x = m-(p)*(p-1)/2;
		 y = n+x-p;
	    }
//	    printf("x:%d y:%d\n",x,y);
	    printf("%lld\n",cal(x,y));
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
