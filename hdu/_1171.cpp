/* ***********************************************
Author :111qqz
Created Time :2016年02月25日 星期四 23时08分48秒
File Name :code/hdu/_1171.cpp
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
const int N=3E5+7;
int n;
int a[N],tmp[N];
int v[55],num[55];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (scanf("%d",&n))
	{
	    if (n<0) break;

	    for ( int i =  1 ; i <= n ; i++)
	    {
		scanf("%d %d",&v[i],&num[i]);
	    }

	    ms(a,0);
	    for ( int i = 0 ; i <= num[1]*v[1] ; i+=v[1])
	    {
		a[i] = 1;
	    }

	    int cur = num[1]*v[1];
	    for ( int i = 2 ; i <= n ; i++)
	    {
		for ( int j = 0 ; j <= cur ;  j++)
		{
		    for ( int k = 0 ; k<=num[i]*v[i] ; k +=v[i] )
		    {
			tmp[j+k] += a[j];
		    }
		}

		cur += num[i]*v[i];

		for ( int j = 0 ; j <= cur ; j++)
		{
		    a[j] = tmp[j];
		    tmp[j] = 0 ;
		}
	    }

	    for ( int i = cur/2 ; i >= 0 ; i--)
	    {
		if (a[i]!=0)
		{
		    printf("%d %d\n",cur-i,i);
		    break;
		}
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
