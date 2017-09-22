/* ***********************************************
Author :111qqz
Created Time :2016年01月29日 星期五 19时31分35秒
File Name :code/uva/10177.cpp
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
const int N=105;
LL n;
LL s2[N],s3[N],s4[N];
void pre()
{
    s2[1]=1;
    for ( LL i = 2 ; i <=101 ; i++)
    {
	s2[i]=s2[i-1]+i*i;
    }
    s3[1]=1;
    for ( LL i = 2 ; i <=101 ; i++)
    {
	s3[i] = s3[i-1]+i*i*i;
    }

    s4[1]=1;
    for ( LL i =2 ; i <= 101 ; i++)
    {
	s4[i] = s4[i-1]+i*i*i*i;
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	pre();

	while (~scanf("%lld",&n))
	{
	    LL k = n*(n+1)/2;
	    LL total2=k*k;
	    LL total3=k*k*k;
	    LL total4=k*k*k*k;


	    printf("%lld %lld %lld %lld %lld %lld\n",s2[n],total2-s2[n],s3[n],total3-s3[n],s4[n],total4-s4[n]);
	


	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
