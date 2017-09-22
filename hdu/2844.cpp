/* ***********************************************
Author :111qqz
Created Time :2016年11月17日 星期四 10时36分41秒
File Name :code/hdu/2844.cpp
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
const int N = 1E5+7;
int value[105],num[105];
int a[N],tmp[N];
int n,m;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%d%d",&n,&m))
	{
	    if (n==0&&m==0) break;
	    for ( int i = 0 ; i <= m ; i++) a[i] =  0;
	    for ( int i = 1 ; i <= n ; i++) scanf("%d",&value[i]);
	    for ( int i = 1 ;i <= n ; i++) scanf("%d",&num[i]);
	    for (int i = 0 ; i <= num[1] ; i++)
    	    {
		//printf("%d %d %d\n",i,value[i],i*value[i]);
		if (i*value[1]>m) break;
		a[i*value[1]] = 1;
		tmp[i*value[1]] = 0 ;
	    }
	    int cur = num[1]*value[1];
	    cur = min(m,cur);
	    for ( int i = 2 ; i <= n ; i++)
	    {
		for (int j = 0 ; j <= cur ; j++)
		{
		    for (int k = 0 ; k <= num[i]&&j+value[i]*k<=m ; k++)
		    {
			tmp[j+value[i]*k] += a[j];
		    }
		}
		cur += num[i]*value[i];
		cur = min(cur,m);
		for (int j = 0 ; j <= cur ; j++)
		{
		    a[j] = tmp[j];
		    tmp[j] = 0 ;
		}
	    }
	    
	 
	    int cnt = 0 ;
	    for ( int i = 1 ; i <= m ; i++) if (a[i]) cnt++;
	    printf("%d\n",cnt);

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
