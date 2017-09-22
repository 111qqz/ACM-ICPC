/* ***********************************************
Author :111qqz
Created Time :2015年12月06日 星期日 16时02分28秒
File Name :code/bc/#64/1002.cpp
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



using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=1E5+7;
const int MOD =10007;
int n;
int a[N];
int b[N];
int sum;
int cal ( int x)
{
    return (1890*x+143)%MOD;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (scanf("%d",&n)!=EOF)
	{
	    sum = 0 ;
	    for ( int i = 0 ; i< n ; i++) 
	    {
		scanf("%d",&a[i]);
		sum = sum + a[i];
		a[i] = a[i] % MOD;
		b[i] = cal(a[i]);
		b[i] = b[i]-a[i];
	    }
	    int last = 0 ;
	    int ans = 0 ;
	    for ( int i = 0 ; i < n ; i++)
	    {
		last = max(0,last)+b[i];
		ans = max(ans,last);
	    }
	    printf("%d\n",ans+sum);
	}   

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
