/* ***********************************************
Author :111qqz
Created Time :2017年10月11日 星期三 15时08分57秒
File Name :H.cpp
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
#define PB push_back
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
int n,m;
int a[N];
int sum[N];
int solve( int x)
{
    int ret = 0;
    int mn = inf;
    for ( int i = 1 ; i <= n ; i++)
    {
	for ( int j = i ; j <= n ; j++)
	{
	    int tmp = sum[j]^sum[i-1];
	    //printf(" xor ( %d %d) = %d\n",i,j,tmp);
	    tmp = abs(tmp-x);
	    if (tmp<mn || (tmp==mn&&j-i+1>ret))
	    {
		mn = tmp;
		ret = j-i+1;
	    }
	}
    }
    return ret;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    ms(sum,0);
	    scanf("%d",&n);
	    for ( int i = 1 ; i <= n ; i++) 
	    {
		scanf("%d",&a[i]);
		sum[i] = sum[i-1]^ a[i];
	    }
	    scanf("%d",&m);
	    while (m--)
	    {
		int x;
		scanf("%d",&x);
		int ret = solve(x);
		printf("%d\n",ret);
	    }
	    printf("\n");
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
