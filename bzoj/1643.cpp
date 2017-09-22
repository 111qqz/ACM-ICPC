/* ***********************************************
Author :111qqz
Created Time :2016年04月10日 星期日 16时34分31秒
File Name :code/bzoj/1643.cpp
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
const int N=1E4+7;
int n;
int a[N],tmp[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d",&n);
	ms(tmp,0);
	for ( int i =  0 ; i*i <= n ; i++)
	{
	    a[i*i] = 1;
	}
	for ( int i = 2 ; i <= 4 ; i++)
	{
	    for ( int j = 0 ; j <= n ; j++)
	    {
		for ( int k = 0 ; k*k+j <= n ; k++)
		{
		    tmp[j+k*k] += a[j];
		}
	    }

	    for ( int j = 0 ; j <= n ; j++)
	    {
		a[j] = tmp[j];
		tmp[j] = 0 ;
	    }
	}

	printf("%d\n",a[n]);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
