/* ***********************************************
Author :111qqz
Created Time :2016年02月27日 星期六 15时14分12秒
File Name :code/hdu/2152.cpp
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
int a[N],tmp[N];

int n,m;
int l[N],r[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif


	while (~scanf("%d %d",&n,&m))
	{
	    for ( int i =  1 ; i <= n ; i++) scanf("%d %d",&l[i],&r[i]);


	    ms(tmp,0);
	    ms(a,0);

	    for ( int i = l[1] ; i <= r[1] ; i++ )
	    {
		a[i] = 1;
	    }

	    for ( int i = 2 ; i <= n ; i++)
	    {
		for ( int j = 0  ; j <= m ; j++)
		{
		    for ( int k = l[i] ; k <= r[i] ; k++  )
		    {
			tmp[j+k] +=a[j];
		    }
		}
		
		for ( int j = 0 ; j <= m ; j++)
		{
		    a[j] = tmp[j];
		    tmp[j] = 0 ;
		}
	    }


	    printf("%d\n",a[m]);
	    



	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
