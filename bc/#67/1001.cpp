/* ***********************************************
Author :111qqz
Created Time :2015年12月26日 星期六 18时34分30秒
File Name :code/bc/#67/1001.cpp
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
const int N=1E6+7;
int a[N];
int sum[N];
int n;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	cin>>T;
	while (T--)
	{
	    sum[0] = 0 ;
	    scanf("%d",&n);
	    bool ok = false;
	    ms(a,-1);
	    for ( int i = 1  ; i <= n ; i++)
	    {
		scanf("%d",&a[i]);
		sum[i] = sum[i-1] + a[i];
	    }
	    sum[n+1] =  sum[n];
	    int cnt = 0 ;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		if (a[i]==0) cnt++;
	    }
	    if (cnt%2==0)
	    {
		puts("YES");
	    }
	    else
	    {
		puts("NO");
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
