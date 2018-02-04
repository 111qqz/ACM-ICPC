/* ***********************************************
Author :111qqz
Created Time :Sat 24 Sep 2016 12:32:20 PM CST
File Name :code/net/2016/beijing/F.cpp
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

using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=6E4+7;
LL a[N];
LL b[N];
LL n;
LL sum[N],sum2[N];

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%lld",&n);
	    for ( int i = 1 ; i <= n ; i ++) scanf("%lld",a+i);
	    sum[0] = sum2[0] = 0 ;
	    for ( int i = 1 ; i <= n ; i++) scanf("%lld",b+i);
	    for ( int i = 1 ; i <= n ; i++)
	    {
		sum[i] = sum[i-1] + a[i];
		sum2[i] = sum2[i-1] + a[i]*a[i];
	    }
	    for ( int i = 1 ; i <= n ; i++) printf("sum:%lld  sum2: %lld\n",sum[i],sum2[i]);
	    LL ans = 1LL<<60;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		LL tmp = n * b[i]*b[i] - 2*b[i] * sum[n] + sum2[n];
		cout<<"tmp:"<<tmp<<endl;
		if (tmp<ans) ans = tmp;
	    }
	    printf("%lld\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
} 
