/* ***********************************************
Author :111qqz
Created Time :2016年02月26日 星期五 16时24分17秒
File Name :code/hdu/2189.cpp
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
const int N=155;
int pri[N];
int a[N],tmp[N];
int cnt;
int n;

bool judge ( int n)
{
    if (n<=3) return true;
    for ( int i = 2 ; i*i <= n ; i++)
    {
	if (n%i==0) return false;
    }

    return true;
} 


void pre()
{
    cnt  = 0;
    for ( int i = 2 ; i <= 200 ;  i++)
    {
	if (judge(i))
	    pri[++cnt] = i;
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	
	int T;
	pre();
	scanf("%d",&T);
	while (T--)
	{
	    scanf("%d",&n);

	    ms(a,0);
	    for ( int i = 0 ; i <= n ; i+=2 )
	    {
		a[i] = 1;
		tmp[i] =  0;
	    }

	    
	    for ( int i = 2 ; pri[i] <= n ; i++)
	    {
		for ( int j = 0 ; j <= n ; j++)
		{
		    for ( int k = 0 ; k + j <= n ; k +=pri[i])
		    {
			tmp[j+k] +=a[j];
		    }
		}
		for ( int j = 0 ; j <= n ; j ++)
		{
		    a[j] = tmp[j];
		    tmp[j] =  0;
		}
	    }

	    printf("%d\n",a[n]);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
