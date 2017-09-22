/* ***********************************************
Author :111qqz
Created Time :2016年02月27日 星期六 20时18分14秒
File Name :code/hdu/1261.cpp
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
int n;
double a[320],tmp[320];
double f[320];
int num[30];

void pre()
{
    f[0] = 1.0;
    for ( int i = 1 ; i <= 320 ; i++)
    {
	f[i] = f[i-1] *1.0*i;
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	pre();

	while (~scanf("%d",&n)&&n)
	{
	    for ( int i = 1 ; i <= n ;  i++) scanf("%d",&num[i]);

	    ms(tmp,0);
	    ms(a,0);
	    for ( int i = 0  ; i <= num[1]  ; i++)
	    {
		a[i] = 1.0/f[i];
	    }

	    int cur = num[1];
	    for ( int i = 2 ; i <= n ; i++ )
	    {
		for ( int j = 0 ; j <= cur ; j++)
		{
		    for ( int k = 0 ; k <= num[i] ; k++)
		    {
			tmp[j+k] += a[j]*1.0/f[k];
		    }
		}
		cur +=num[i];
		for ( int j = 0 ; j <= cur ; j++)
		{
		    a[j] = tmp[j];
		    tmp[j] = 0 ;
		}
	    }


	    double ans = a[cur]*f[cur];

	    printf("%d\n",int(ans+0.5));


	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
