/* ***********************************************
Author :111qqz
Created Time :2015年12月26日 星期六 13时20分31秒
File Name :code/51nod/1081.cpp
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
const int N=5E4+7;
int n,q;
LL a[N];
LL sum[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d",&n);
	sum[0] = 0  ;
	for ( int i = 1 ; i <= n ; i++)
	{
	    cin>>a[i];
	    sum[i] = sum[i-1] + a[i];
	}
	cin>>q;
	while (q--)
	{
	    int x,y;
	    scanf("%d %d",&x,&y);
	    printf("%lld\n",sum[x+y-1]-sum[x-1]);
	}

  #ifndef ONLINE_JUDGE  
 // fclose(stdin);
  #endif
    return 0;
}
