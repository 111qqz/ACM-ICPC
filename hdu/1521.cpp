/* ***********************************************
Author :111qqz
Created Time :2016年02月27日 星期六 19时48分31秒
File Name :code/hdu/1521.cpp
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
double a[15],tmp[15],f[15];
int n,m;
int num[15];
void pre()
{
    f[0] = 1.0;
    for ( int i = 1 ;i  <= 10 ; i++)
    {
	f[i] = f[i-1]*i*1.0;
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	pre();
	while (scanf("%d %d",&n,&m)!=EOF)
	{
	    for ( int i = 1 ; i <= n ; i++) scanf("%d",&num[i]);

	    ms(a,0);
	    ms(tmp,0);

	    for ( int i = 0 ; i <= num[1] ; i++)
	    {
		a[i] = 1.0/f[i];
	    }

	    for ( int i = 2 ; i <= n ; i++)
	    {
		for ( int j = 0 ; j <= m ; j++)
		{
		    for ( int k = 0 ; k+j<=m&&k<=num[k] ; k++)
		    {
			tmp[j+k] += a[j]/f[k];
		    }
		}

		for ( int j  = 0 ; j <= m ; j++)
		{
		    a[j] = tmp[j];
		    tmp[j] = 0.0;
		}
	    }
	    
	    double ans = a[m]*f[m];
	    printf("%d\n",int(ans+0.5));
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
