/* ***********************************************
Author :111qqz
Created Time :2016年02月25日 星期四 22时15分31秒
File Name :code/hdu/1398.cpp
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
const int N=305;
int a[N],tmp[N];
int n;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (scanf("%d",&n)!=EOF&&n)
	{
	    for (int i = 0 ; i <=  n ;i++)
	    {
		a[i] = 1;
		tmp[i] = 0 ;
	    }
	    
	    for ( int i = 2 ; i*i <= n ; i ++)
	    {
		for ( int j = 0 ; j <= n ; j++)
		{
		    for ( int k = 0 ; k+j <= n ; k+=i*i)
		    {
			tmp[j+k] += a[j];
		    }
		}

		for ( int j = 0 ; j <= n ;j++)
		{
		    a[j] = tmp[j];
		    tmp[j] = 0 ;
		}
	    }

	    printf("%d\n",a[n]);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
