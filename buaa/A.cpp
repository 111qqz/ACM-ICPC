/* ***********************************************
Author :111qqz
Created Time :2015年12月20日 星期日 14时01分11秒
File Name :code/buaa/A.cpp
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
const int N=1E3+7;
int n , m;
LL total;
LL k;
LL sum[N];
LL a[N][N];
bool cmp(int a,int b)
{
    return a>b;
}
void print()
{
    for ( int i =1 ; i <= n ; i++)
    {
	for ( int j = 1 ;  j <= m ; j++)
	{
	    printf("%lld ",a[i][j]);
	}
	printf("\n");
    }
    puts("****************");
    
    for ( int j = 1 ; j <= m ; j++)
    {
	printf("%lld ",sum[j]);
    }
    puts(" ");
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (scanf("%d%d%lld",&n,&m,&k)!=EOF){

	    ms(sum,0);
	    ms(a,0);
	    for ( int i = 1  ; i <= n ; i ++ )
		for ( int j = 1 ; j <= m ; j++)
		{
		    scanf("%lld",&a[i][j]);
		}

	    for ( int i = 1 ; i <= n ; i++)
		sort(a[i]+1,a[i]+m+1,cmp);


	    for (int j = 1 ; j <= m ; j++)
	    {
		for ( int i = 1; i <= n;  i++)
		{
		    if (a[i][j]>=0)
		    sum[j] += a[i][j];
		}
	    }
	  //  print();
	    total = 0  ;
	    bool flag = false;
	    if (k==0)
	    {
	//	puts("0");
	//	continue;
	    }
	    sum [0] = 0 ;
	    for ( int i = 0 ; i <= m ; i++)
	    {
		total+=sum[i];
		if (total>=k)
		{
		    flag = true;
		    printf("%d\n",i);
		    break;
		}
	    }
	    if (!flag)
	    {
		puts("-1");
	    }
	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
