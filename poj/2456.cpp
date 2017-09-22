/* ***********************************************
Author :111qqz
Created Time :Mon 19 Sep 2016 10:57:54 PM CST
File Name :code/poj/2456.cpp
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
const int N=1E5+7;
int x[N];
int n,c;
bool check( int k)
{
    int cnt = 1;
    int cur = x[1];
    for ( int i = 2 ; i <= n ; i++)
    {
	if (x[i]-cur>=k)
	{
	    cnt++;
	    cur = x[i];
	}
    }
    return cnt>=c;
}
int bin()
{
    int l = 1;
    int r = x[n]-x[1];
    while (l<=r)
    {
	int mid = (l+r)>>1;
	if (!check(mid))
	{
	    r = mid-1;
	}
	else
	    l = mid+1;
    }
    return l-1;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	scanf("%d%d",&n,&c);
	for ( int i = 1 ; i <= n ; i++) scanf("%d",&x[i]);
	sort(x+1,x+n+1);
	int ans = bin();
	printf("%d\n",ans);
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
