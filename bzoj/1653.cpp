/* ***********************************************
Author :111qqz
Created Time :2016年04月12日 星期二 10时54分23秒
File Name :code/bzoj/1653.cpp
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
int sum;
int a[15];
int tmp[15];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d %d",&n,&sum);
	for ( int i = 1 ; i <= n ; i++) a[i] = i;
	
	do
	{
	    for ( int i = 1 ; i <= n ; i++) tmp[i] = a[i];
	    for ( int i = 1 ; i < n ; i++)
		for ( int j = 1 ; j <= n - i ; j ++)
		    tmp[j]+=tmp[j+1];
	    if (tmp[1]==sum)
	    {
		for ( int i = 1 ; i< n ; i++)
		    printf("%d ",a[i]);
		printf("%d\n",a[n]);
		break;
	    }
	}while (next_permutation(a+1,a+n+1));


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
